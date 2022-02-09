/*
 * Copyright (C) 2013 Spreadtrum Communications Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *************************************************
 * Automatically generated C header: do not edit *
 *************************************************
 */

/*
 * Regulator (0)Name, Regulator (1)Type, Power Off (2)Ctrl and (3)Bit,
 * Voltage Trimming (4)Ctrl and (5)Bits, Calibration (6)Ctrl and (7)Bits,
 * Voltage (8)Default, Voltage (9)Ctrl and (10)Bits, Voltage Select (11)Count and Voltage (12)List[ ... ...]
 */

    SCI_REGU_REG(vddcore, 0x12, ANA_REG_GLB_LDO_DCDC_PD, BIT(9),
	ANA_REG_GLB_DCDC_CORE_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), ANA_REG_GLB_DCDC_CTRL15, BIT(14)|BIT(16)|BIT(18)|BIT(19),
	900, ANA_REG_GLB_DCDC_CORE_ADI, BIT(5)|BIT(6)|BIT(7), 8, 1100, 700, 800, 900, 1000, 650, 1200, 1300);

    SCI_REGU_REG(vddarm, 0x12, ANA_REG_GLB_LDO_DCDC_PD, BIT(10),
	ANA_REG_GLB_DCDC_ARM_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4), ANA_REG_GLB_DCDC_CTRL15, BIT(13)|BIT(16)|BIT(18)|BIT(19),
	900, ANA_REG_GLB_DCDC_ARM_ADI, BIT(5)|BIT(6)|BIT(7), 8, 1100, 700, 800, 900, 1000, 650, 1200, 1300);

    SCI_REGU_REG(vddmem, 0x12, ANA_REG_GLB_LDO_DCDC_PD, BIT(11),
	ANA_REG_GLB_DCDC_MEM_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9), ANA_REG_GLB_DCDC_CTRL15, BIT(13)|BIT(14)|BIT(16)|BIT(18)|BIT(19),
	1200, 0, 0, 2, 600, 3125);

    SCI_REGU_REG(vddgen, 0x12, ANA_REG_GLB_LDO_DCDC_PD, BIT(12),
	ANA_REG_GLB_DCDC_GEN_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9), ANA_REG_GLB_DCDC_CTRL15, BIT(15)|BIT(16)|BIT(18)|BIT(19),
	2400, 0, 0, 2, 600, 3125);

    SCI_REGU_REG(vddrf, 0x12, ANA_REG_GLB_LDO_DCDC_PD, BIT(13),
	ANA_REG_GLB_DCDC_RF_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9), ANA_REG_GLB_DCDC_CTRL15, BIT(13)|BIT(15)|BIT(16)|BIT(18)|BIT(19),
	1500, 0, 0, 2, 600, 3125);

    SCI_REGU_REG(vddcon, 0x2, ANA_REG_GLB_LDO_PD_CTRL, BIT(13),
	ANA_REG_GLB_DCDC_CON_ADI, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7)|BIT(8)|BIT(9), ANA_REG_GLB_DCDC_CTRL15, BIT(14)|BIT(15)|BIT(16)|BIT(18)|BIT(19),
	1600, 0, 0, 2, 600, 3125);

    SCI_REGU_REG(vddwpa, 0x2, ANA_REG_GLB_LDO_PD_CTRL, BIT(14),
	ANA_REG_GLB_DCDC_WPA_ADI, BIT(0)|BIT(1)|BIT(2), ANA_REG_GLB_DCDC_CTRL15, BIT(13)|BIT(14)|BIT(15)|BIT(16)|BIT(18)|BIT(19),
	0, 0, 0, 0);

    SCI_REGU_REG(vddrf0, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(8),
	ANA_REG_GLB_LDO_V_CTRL0, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(2)|BIT(16)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vddemmccore, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(7),
	ANA_REG_GLB_LDO_V_CTRL7, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(5)|BIT(6)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddgen1, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(6),
	ANA_REG_GLB_LDO_V_CTRL3, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14), ANA_REG_GLB_LDO_V_CTRL11, BIT(0)|BIT(2)|BIT(16)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vddgen0, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(4),
	ANA_REG_GLB_LDO_V_CTRL2, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_LDO_V_CTRL11, BIT(1)|BIT(2)|BIT(16)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vdddcxo, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(5),
	ANA_REG_GLB_LDO_V_CTRL8, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(7)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vdd25, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(3),
	ANA_REG_GLB_LDO_V_CTRL10, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(8)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vdd28, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(2),
	ANA_REG_GLB_LDO_V_CTRL3, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(6)|BIT(7)|BIT(10)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vdd18, 0x10, ANA_REG_GLB_LDO_DCDC_PD, BIT(1),
	ANA_REG_GLB_LDO_V_CTRL9, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14), ANA_REG_GLB_LDO_V_CTRL11, BIT(0)|BIT(16)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vddwifipa, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(11),
	ANA_REG_GLB_LDO_V_CTRL0, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(5)|BIT(10)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	3300, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddsdcore, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(10),
	ANA_REG_GLB_LDO_V_CTRL6, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(5)|BIT(7)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	3000, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddsdio, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(0),
	ANA_REG_GLB_LDO_V_CTRL4, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(3)|BIT(16)|BIT(18)|BIT(19)|BIT(20),
	3000, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddsim0, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(1),
	ANA_REG_GLB_LDO_V_CTRL4, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(8)|BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddsim1, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(2),
	ANA_REG_GLB_LDO_V_CTRL5, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(10)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddsim2, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(3),
	ANA_REG_GLB_LDO_V_CTRL5, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14)|BIT(15), ANA_REG_GLB_LDO_V_CTRL11, BIT(8)|BIT(9)|BIT(17)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddcama, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(4),
	ANA_REG_GLB_LDO_V_CTRL6, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(9)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddcamd, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(5),
	ANA_REG_GLB_LDO_V_CTRL1, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6), ANA_REG_GLB_LDO_V_CTRL11, BIT(1)|BIT(16)|BIT(18)|BIT(20),
	1500, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vddcamio, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(6),
	ANA_REG_GLB_LDO_V_CTRL1, BIT(8)|BIT(9)|BIT(10)|BIT(11)|BIT(12)|BIT(13)|BIT(14), ANA_REG_GLB_LDO_V_CTRL11, BIT(0)|BIT(1)|BIT(16)|BIT(18)|BIT(20),
	1800, 0, 0, 2, 1150, 6250);

    SCI_REGU_REG(vddcammot, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(7),
	ANA_REG_GLB_LDO_V_CTRL7, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(6)|BIT(16)|BIT(17)|BIT(18)|BIT(20),
	2800, 0, 0, 2, 1200, 10000);

    SCI_REGU_REG(vddusb, 0x0, ANA_REG_GLB_LDO_PD_CTRL, BIT(8),
	ANA_REG_GLB_LDO_V_CTRL9, BIT(0)|BIT(1)|BIT(2)|BIT(3)|BIT(4)|BIT(5)|BIT(6)|BIT(7), ANA_REG_GLB_LDO_V_CTRL11, BIT(4)|BIT(16)|BIT(18)|BIT(19)|BIT(20),
	3300, 0, 0, 2, 1200, 10000);

