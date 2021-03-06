/* FreeEMS - the open source engine management system
 *
 * Copyright 2008-2013 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */


/** @file
 *
 * @ingroup measurementsAndCalculations
 *
 * @brief Generate the derived variables.
 *
 * Second level variables are derived from the core variables and generated here.
 */


#define DERIVEDVARSGENERATOR_C
#include "inc/freeEMS.h"
#include "inc/commsCore.h"
#include "inc/tableLookup.h"
#include "inc/derivedVarsGenerator.h"
#include "inc/locationIDs.h"
#include "inc/decoderInterface.h"


/**
 * Use core variables to lookup and calculate the derived variables. This
 * function uses the core variables to lookup and calculate further second
 * order variables such as load, VE, Lamdda, Transient fuel correction, engine
 * temperature enrichment, Injector dead time, etc.
 */
void generateDerivedVars(){
	extern unsigned long RPMWeighted;
	extern KeyUserDebug KeyUserDebugs;
	extern const volatile fixedConfig1 fixedConfigs1;                                                                                                
	extern const volatile fixedConfig2 fixedConfigs2;
	/* Determine load based on options */
	if(!(fixedConfigs2.algorithmSettings.loadType)){ /* Use MAP as load */
		DerivedVars->LoadMain = CoreVars->MAP;
	}else if(fixedConfigs2.algorithmSettings.loadType == LOAD_TPS){ /* Use TPS as load */
		DerivedVars->LoadMain = CoreVars->TPS;
	}else if(fixedConfigs2.algorithmSettings.loadType == LOAD_AAP){ /* Use AAP corrected MAP as load */
		DerivedVars->LoadMain = ((unsigned long)CoreVars->MAP * CoreVars->AAP) / KPA(100);
		// TODO add maf calc load option here
	}else if(fixedConfigs2.algorithmSettings.algorithmType == ALGO_MAF){
		//For now keep Load based on MAP for other uses, during the fuel calc algorithmType
		//will catch the MAF mode and use its reading
		DerivedVars->LoadMain = CoreVars->MAP;
	}else{ /* Default to MAP, but throw error */
		DerivedVars->LoadMain = CoreVars->MAP;
	}

	// Back calculate KPA using a MAF sensor. Air Flow is in CC/min, looked up from a 2d table based on the signal from the MAF sensor.
	if(fixedConfigs2.algorithmSettings.algorithmType == ALGO_MAF){
		unsigned long collectiveFlow = lookupTwoDTableUSV((twoDTableUSMAF*)&TablesC.SmallTablesC.MAFVersusVoltageTable, CoreVars->MAF, TWODTABLEUS_MAF_LENGTH);
		collectiveFlow <<= 16;
		unsigned long cylFill = ((collectiveFlow / fixedConfigs1.engineSettings.cylinderCount) / ((RPMWeighted / RPM_FACTOR)
							/ (fixedConfigs1.engineSettings.strokesPerCycle / 2)));
		KeyUserDebugs.zsp9 = (cylFill * CYLINDER_FLOW_FACTOR) / fixedConfigs1.engineSettings.perCylinderVolume; //Calculated KPA
		//KeyUserDebugs.zsp8 = lookupTwoDTableUSV((twoDTableUSMAF*)&TablesC.SmallTablesC.MAFVersusVoltageTable, CoreVars->MAF, TWODTABLEUS_MAF_LENGTH);
	}

	/* Look up target Lambda with RPM and Load */
//#if CONFIG == SEANKR1_ID //FIXME temp hack until a real lambda table is built
//	DerivedVars->Lambda = LR(0.80); //From what I read E85 makes best power in the low .8s
//#else
	DerivedVars->Lambda = lookupMainTable(CoreVars->RPM, DerivedVars->LoadMain, LAMBDA_TABLE_LOCATION_ID);
//#endif

	/* Look up injector dead time with battery voltage */
	DerivedVars->IDT = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.injectorDeadTimeTable, CoreVars->BRV);

	if(!(fixedConfigs2.algorithmSettings.dwellType)){
		DerivedVars->Dwell = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.dwellDesiredVersusVoltageTable, CoreVars->BRV);
	}else if(fixedConfigs2.algorithmSettings.dwellType == DWELL_RPM){
		DerivedVars->Dwell = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.dwellVersusRPMTable, CoreVars->RPM);
	}else if(fixedConfigs2.algorithmSettings.dwellType == DWELL_FIXED){
		DerivedVars->Dwell = fixedConfigs2.algorithmSettings.dwellFixedPeriod;
	}else{
		DerivedVars->Dwell = 0;
	}

	unsigned long tempAdvance = ANGLE_FACTOR * (unsigned long)lookupMainTable(CoreVars->RPM, DerivedVars->LoadMain, IGNITION_ADVANCE_TABLE_MAIN_LOCATION_ID);
	DerivedVars->Advance = (unsigned short)(tempAdvance / 1024); // This calculation will change when the timing tables get shrunk to a more reasonable 8 bit size with appropriate scaling
	// Move this magic number to an appropriate place and/or refactor timing calcs/values/etc

/// @todo TODO make generic!!!!
// to go generic we need:
// angle between ignition events (if have tpd) (or total angle and number of events)
// max % dwell
// minimum spark time
// a setting to choose which behaviour (don't limit/% dwell limit/min spark time/other?)
#if CONFIG == HOTEL_ID
	/// @bug hack for hyundai! 135 = 3/4 of 180 = one cycle...
	unsigned long threeQuartersOfAvailableTime = ((unsigned long)CoreVars->DRPM * 135 * ANGLE_FACTOR) / TICKS_PER_DEGREE_MULTIPLIER;
	if(DerivedVars->Dwell > threeQuartersOfAvailableTime){
		DerivedVars->Dwell = threeQuartersOfAvailableTime;
	}
#endif

	/* Look up the engine temperature enrichment percentage with temperature */
	DerivedVars->ETE = lookupTwoDTableUS((twoDTableUS*)&TablesA.SmallTablesA.engineTempEnrichmentTablePercent, CoreVars->CHT);
	/* TODO The above needs some careful thought put into it around different loads and correction effects. */


	/* Calculate the Transient Fuel Correction */
	if(TRUE /*WWTFC*/){ /* Do ONLY WW correction if enabled */
		// Do ww stuff, maybe pre done via RTC/RTI for consistent period?
		DerivedVars->TFCTotal = 0; /* TODO replace with real code */
	}else if(FALSE /*STDTFC*/){ /* Do any combination of standard approximate methods */
		/* Initialse the variable as a base */
		DerivedVars->TFCTotal = 0;
		/* Based on the rate of change of MAP and some history/taper time */
		if(FALSE /*MAPTFC*/){
			// Do MAP based
			DerivedVars->TFCTotal += 0;
		}

		/* Based on the rate of change of TPS and some history/taper time */
		if(FALSE /*TPSTFC*/){
			// Do TPS based
			DerivedVars->TFCTotal += 0;
		}

		/* Based on the rate of change of RPM and some history/taper time */
		if(FALSE /*RPMTFC*/){
			// Do RPM based
			DerivedVars->TFCTotal += 0;
		}
	}else{ /* Default to no correction */
		DerivedVars->TFCTotal = 0;
		/* Don't throw error as correction may not be required */
	}
}
