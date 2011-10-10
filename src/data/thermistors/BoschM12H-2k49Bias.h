/* FreeEMS - the open source engine management system
 *
 * Copyright 2008-2011 Fred Cooke
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


/** @file BoschM12H-2k49Bias.h
 * @ingroup dataInitialisers
 *
 * Generated by FreeTherm 0.7-SNAPSHOT using the following parameters:
 *
 * Bias Resistor:
 * - Value: 2490
 *
 * Sensor Sample Points:
 * - Temp Low  : 0
 * - Temp Mid  : 30
 * - Temp High : 80
 * - Res Low   : 5896
 * - Res Mid   : 1707
 * - Res High  : 323
 *
 * Temp Units:
 * - Input Temp Scale: Celcius
 * - Output Temp Scale: Kelvin
 *
 * Bosch M12-H datasheet: http://www.bosch-motorsport.de/en-US/literature/en-US/0281002170_DataSheet_enUS_T6821419403.pdf
 */


65535, 64772, 58061, 54730, 52580, 51021, 49810, 48828, 48005, 47300, 46686, 46142, 45656, 45217, 44816, 44449,
44111, 43797, 43504, 43230, 42973, 42731, 42503, 42286, 42080, 41885, 41698, 41520, 41349, 41185, 41028, 40877,
40731, 40591, 40456, 40325, 40199, 40076, 39957, 39842, 39731, 39622, 39517, 39414, 39314, 39217, 39122, 39030,
38939, 38851, 38765, 38681, 38599, 38519, 38440, 38363, 38287, 38213, 38141, 38070, 38000, 37931, 37864, 37798,
37733, 37670, 37607, 37546, 37485, 37426, 37367, 37309, 37253, 37197, 37142, 37088, 37034, 36982, 36930, 36879,
36829, 36779, 36730, 36681, 36634, 36587, 36540, 36494, 36449, 36404, 36360, 36316, 36273, 36231, 36188, 36147,
36106, 36065, 36025, 35985, 35945, 35906, 35868, 35830, 35792, 35755, 35718, 35681, 35645, 35609, 35573, 35538,
35503, 35469, 35435, 35401, 35367, 35334, 35301, 35269, 35236, 35204, 35172, 35141, 35110, 35079, 35048, 35017,
34987, 34957, 34928, 34898, 34869, 34840, 34811, 34782, 34754, 34726, 34698, 34670, 34643, 34615, 34588, 34561,
34535, 34508, 34482, 34456, 34430, 34404, 34378, 34353, 34328, 34303, 34278, 34253, 34228, 34204, 34179, 34155,
34131, 34108, 34084, 34060, 34037, 34014, 33991, 33968, 33945, 33922, 33900, 33877, 33855, 33833, 33811, 33789,
33767, 33745, 33724, 33702, 33681, 33660, 33639, 33618, 33597, 33576, 33555, 33535, 33514, 33494, 33474, 33454,
33434, 33414, 33394, 33374, 33355, 33335, 33316, 33296, 33277, 33258, 33239, 33220, 33201, 33182, 33164, 33145,
33127, 33108, 33090, 33071, 33053, 33035, 33017, 32999, 32981, 32963, 32946, 32928, 32910, 32893, 32876, 32858,
32841, 32824, 32806, 32789, 32772, 32755, 32739, 32722, 32705, 32688, 32672, 32655, 32639, 32622, 32606, 32590,
32573, 32557, 32541, 32525, 32509, 32493, 32477, 32461, 32446, 32430, 32414, 32399, 32383, 32368, 32352, 32337,
32322, 32306, 32291, 32276, 32261, 32246, 32231, 32216, 32201, 32186, 32171, 32156, 32142, 32127, 32112, 32098,
32083, 32069, 32054, 32040, 32025, 32011, 31997, 31983, 31968, 31954, 31940, 31926, 31912, 31898, 31884, 31870,
31856, 31842, 31829, 31815, 31801, 31788, 31774, 31760, 31747, 31733, 31720, 31706, 31693, 31680, 31666, 31653,
31640, 31626, 31613, 31600, 31587, 31574, 31561, 31548, 31535, 31522, 31509, 31496, 31483, 31470, 31457, 31445,
31432, 31419, 31406, 31394, 31381, 31368, 31356, 31343, 31331, 31318, 31306, 31293, 31281, 31269, 31256, 31244,
31232, 31219, 31207, 31195, 31183, 31171, 31159, 31146, 31134, 31122, 31110, 31098, 31086, 31074, 31062, 31050,
31039, 31027, 31015, 31003, 30991, 30980, 30968, 30956, 30944, 30933, 30921, 30909, 30898, 30886, 30875, 30863,
30852, 30840, 30829, 30817, 30806, 30794, 30783, 30771, 30760, 30749, 30737, 30726, 30715, 30704, 30692, 30681,
30670, 30659, 30647, 30636, 30625, 30614, 30603, 30592, 30581, 30570, 30559, 30548, 30537, 30526, 30515, 30504,
30493, 30482, 30471, 30460, 30449, 30438, 30428, 30417, 30406, 30395, 30384, 30374, 30363, 30352, 30342, 30331,
30320, 30309, 30299, 30288, 30278, 30267, 30256, 30246, 30235, 30225, 30214, 30204, 30193, 30182, 30172, 30162,
30151, 30141, 30130, 30120, 30109, 30099, 30089, 30078, 30068, 30057, 30047, 30037, 30026, 30016, 30006, 29995,
29985, 29975, 29965, 29954, 29944, 29934, 29924, 29914, 29903, 29893, 29883, 29873, 29863, 29853, 29842, 29832,
29822, 29812, 29802, 29792, 29782, 29772, 29762, 29752, 29742, 29732, 29722, 29712, 29702, 29692, 29682, 29672,
29662, 29652, 29642, 29632, 29622, 29612, 29602, 29592, 29582, 29572, 29562, 29552, 29542, 29533, 29523, 29513,
29503, 29493, 29483, 29473, 29464, 29454, 29444, 29434, 29424, 29415, 29405, 29395, 29385, 29375, 29366, 29356,
29346, 29336, 29327, 29317, 29307, 29297, 29288, 29278, 29268, 29258, 29249, 29239, 29229, 29220, 29210, 29200,
29191, 29181, 29171, 29162, 29152, 29142, 29133, 29123, 29113, 29104, 29094, 29084, 29075, 29065, 29055, 29046,
29036, 29027, 29017, 29007, 28998, 28988, 28978, 28969, 28959, 28950, 28940, 28930, 28921, 28911, 28902, 28892,
28882, 28873, 28863, 28854, 28844, 28835, 28825, 28815, 28806, 28796, 28787, 28777, 28767, 28758, 28748, 28739,
28729, 28720, 28710, 28700, 28691, 28681, 28672, 28662, 28653, 28643, 28633, 28624, 28614, 28605, 28595, 28586,
28576, 28566, 28557, 28547, 28538, 28528, 28519, 28509, 28499, 28490, 28480, 28471, 28461, 28451, 28442, 28432,
28423, 28413, 28403, 28394, 28384, 28375, 28365, 28355, 28346, 28336, 28327, 28317, 28307, 28298, 28288, 28278,
28269, 28259, 28249, 28240, 28230, 28221, 28211, 28201, 28192, 28182, 28172, 28162, 28153, 28143, 28133, 28124,
28114, 28104, 28095, 28085, 28075, 28065, 28056, 28046, 28036, 28026, 28017, 28007, 27997, 27987, 27978, 27968,
27958, 27948, 27939, 27929, 27919, 27909, 27899, 27889, 27880, 27870, 27860, 27850, 27840, 27830, 27820, 27811,
27801, 27791, 27781, 27771, 27761, 27751, 27741, 27731, 27721, 27711, 27701, 27691, 27681, 27671, 27661, 27651,
27641, 27631, 27621, 27611, 27601, 27591, 27581, 27571, 27561, 27550, 27540, 27530, 27520, 27510, 27500, 27489,
27479, 27469, 27459, 27449, 27438, 27428, 27418, 27408, 27397, 27387, 27377, 27366, 27356, 27346, 27335, 27325,
27314, 27304, 27294, 27283, 27273, 27262, 27252, 27241, 27231, 27220, 27210, 27199, 27189, 27178, 27167, 27157,
27146, 27136, 27125, 27114, 27104, 27093, 27082, 27071, 27061, 27050, 27039, 27028, 27017, 27007, 26996, 26985,
26974, 26963, 26952, 26941, 26930, 26919, 26908, 26897, 26886, 26875, 26864, 26853, 26842, 26831, 26819, 26808,
26797, 26786, 26774, 26763, 26752, 26741, 26729, 26718, 26706, 26695, 26684, 26672, 26661, 26649, 26637, 26626,
26614, 26603, 26591, 26579, 26568, 26556, 26544, 26532, 26521, 26509, 26497, 26485, 26473, 26461, 26449, 26437,
26425, 26413, 26401, 26389, 26377, 26365, 26352, 26340, 26328, 26315, 26303, 26291, 26278, 26266, 26253, 26241,
26228, 26216, 26203, 26190, 26178, 26165, 26152, 26139, 26127, 26114, 26101, 26088, 26075, 26062, 26049, 26035,
26022, 26009, 25996, 25982, 25969, 25956, 25942, 25929, 25915, 25902, 25888, 25874, 25861, 25847, 25833, 25819,
25805, 25791, 25777, 25763, 25749, 25735, 25721, 25707, 25692, 25678, 25663, 25649, 25634, 25620, 25605, 25590,
25575, 25561, 25546, 25531, 25516, 25500, 25485, 25470, 25455, 25439, 25424, 25408, 25393, 25377, 25361, 25345,
25329, 25313, 25297, 25281, 25265, 25249, 25232, 25216, 25199, 25183, 25166, 25149, 25132, 25115, 25098, 25081,
25064, 25046, 25029, 25011, 24993, 24976, 24958, 24940, 24922, 24903, 24885, 24867, 24848, 24829, 24811, 24792,
24773, 24753, 24734, 24715, 24695, 24675, 24656, 24636, 24615, 24595, 24575, 24554, 24533, 24513, 24491, 24470,
24449, 24427, 24406, 24384, 24362, 24339, 24317, 24294, 24271, 24248, 24225, 24201, 24178, 24154, 24130, 24105,
24081, 24056, 24031, 24005, 23979, 23954, 23927, 23901, 23874, 23847, 23820, 23792, 23764, 23736, 23707, 23678,
23648, 23619, 23588, 23558, 23527, 23495, 23464, 23431, 23399, 23365, 23331, 23297, 23262, 23227, 23191, 23154,
23117, 23079, 23041, 23002, 22962, 22921, 22879, 22837, 22794, 22749, 22704, 22658, 22611, 22562, 22513, 22462,
22410, 22356, 22301, 22244, 22186, 22126, 22064, 21999, 21933, 21864, 21792, 21717, 21640, 21559, 21474, 21384,
21290, 21191, 21086, 20973, 20853, 20724, 20584, 20431, 20261, 20072, 19857, 19607, 19307, 18930, 18416, 17582