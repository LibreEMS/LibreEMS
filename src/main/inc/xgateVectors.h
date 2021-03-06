/* FreeEMS - the open source engine management system
 *
 * Copyright 2010 Sean Keys, Fred Cooke
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
 * @ingroup xgateFiles
 * @ingroup xgateHeaders
 *
 * @brief C header for assembly xgate functions
 *
 * Because we need to call the assembly flash burning function from C code an
 * extern function declaration is required to allow successful compilation.
 */
#ifndef FILE_XGATEVECTORS_H_SEEN
#define FILE_XGATEVECTORS_H_SEEN


#define START_OF_FLASH_WINDOW	(unsigned short*)0x8000 /* 16KB long */
#define START_OF_RAM_WINDOW		(unsigned short*)0x1000 /* 4KB long */
#define XGATE_RAM_ALLOCATION_SIZE	0x0800 /* 2 KBytes */
#define RPAGE_TUNE_TWO_WINDOW_DIFFERENCE (0x8000) /*RPAGE2 starts at 0x9000 for xgate and 0x1000 for s12 */

#define XGATE_INTERRUPT	0x80
#define	PRIORITY_LEVEL_ONE	0x01
#define	PRIORITY_LEVEL_TWO	0x02
#define SCHEDULER_BUSY 0x01

#define ROUTE_INTERRUPT(channel_id, cpu_assignment, priority) \
        INT_CFADDR = (channel_id * 2) & 0xF0;                 \
        INT_CFDATA_ARR[((channel_id * 2) & 0x0F) >> 1] = (cpu_assignment | priority);


typedef struct {
	unsigned short programCounterValue; /* This data is forced into the XGATE PC register */
	unsigned short initialVariable; /* This data is forced into the XGATE R1 register */
} xgateIntVector;

// This statement imports the symbol from the xgate ASM for use in the vector table
extern void xgateSchedule(); 
extern void xgatePITTurnOff();
extern void xgatePITBangLoop();
extern void xgateMetronome();
extern void startXGATECode();
extern void endXGATECode();

/* parameter variables */  //TODO there should be a better way to define these  ex unsigned short
extern void parametersBase();
extern void parameterChannelID();
extern void parameterDelayH();
extern void parameterDelay();
extern void parameterRuntime();
extern void parameterChannelID1();
extern void parameterDelayH1();
extern void parameterDelay1();
extern void parameterRuntime1();
extern void parameterChannelID2();
extern void parameterDelayH2();
extern void parameterDelay2();
extern void parameterRuntime2();
extern void parameterChannelID3();
extern void parameterDelayH3();
extern void parameterDelay3();
extern void parameterRuntime3();
extern void parameterChannelID4();
extern void parameterDelayH4();
extern void parameterDelay4();
extern void parameterRuntime4();
extern void parameterChannelID5();
extern void parameterDelayH5();
extern void parameterDelay5();
extern void parameterRuntime5();

//extern void parameterInputStamp();
extern void xGSInputEdgeStamp();
extern void xGSFlags();
extern void xgsNumOfEventsToSchedule();
//extern void parameterGuard(); /* counter that gets update when a write to shared RAM begins and again when the write is complete */


// Xgate control value
#define XGATE_ERROR_HANDLER 0x0000 /* TODO Create the XGATE error handling thread in asm. */


/* end of the wrapper ifdef from the very top */
#endif
