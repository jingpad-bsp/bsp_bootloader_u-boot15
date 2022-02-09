/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 *Version SP9861-1_E-IA_V1.1.0_Pinmap  The version of pinlist was modified
 */

#include <asm/io.h>
#include <asm/arch/pinmap.h>
#include <power/sprd_pmic/sprd_2731_pinmap.h>

#define BIT_PIN_SLP_ALL  (BIT_PIN_SLP_AP|BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_AGCP)
#define BIT_SLP_ALL  (BIT_SLP_AP|BIT_SLP_PUBCP|BIT_SLP_WTLCP|BIT_SLP_AGCP)


#define BIT_PIN_SLP_ALL_CP  (BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_AGCP)
#define BIT_SLP_ALL_CP  (BIT_SLP_PUBCP|BIT_SLP_WTLCP|BIT_SLP_AGCP)


static pinmap_t pinmap[]={
{REG_PIN_CTRL0,0x0}, //NOT USED
{REG_PIN_CTRL1,0x0},
{REG_PIN_CTRL2,0x04408200}, // uart0->bt;  uart1->ap'uart1; uart2->cp'uart0; uart3->gps; uart4->tgdsp'uart0
{REG_PIN_CTRL3,0x00038000},
{REG_PIN_CTRL4,0x00000200}, // I2C2 for CM4     I2C0/I2C4 of AP
{REG_PIN_CTRL5,0x03a00000}, // CM4 GPIO:GPIO28/GPIO30/GPIO31/GPIO32
{REG_PIN_CTRL6,0x0},
{REG_PIN_CTRL7,0x0},
// CFIO                      Function | Sleep mode | Drive strength | Func WPU/WPUS/WPUS2/WPD/WPD2/NUL | Sleep WPU/WPD/NUL | Sleep OE/IE/Z
//G1 pad
{REG_PIN_RFCTL32,                 BITS_AF(3)},
{REG_PIN_RFCTL32_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//FTID_RSTN
{REG_PIN_RFCTL33,                 BITS_AF(3)},
{REG_PIN_RFCTL33_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//HAPTIC_DRV_EN
{REG_PIN_RFCTL34,                 BITS_AF(0)},
{REG_PIN_RFCTL34_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL35,                 BITS_AF(0)},
{REG_PIN_RFCTL35_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL36,                 BITS_AF(0)},
{REG_PIN_RFCTL36_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL37,                 BITS_AF(3)},
{REG_PIN_RFCTL37_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//VDDCAMA_EN
{REG_PIN_SPI0_CSN,                BITS_AF(0)},
{REG_PIN_SPI0_CSN_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_CS
{REG_PIN_SPI0_DO,                 BITS_AF(0)},
{REG_PIN_SPI0_DO_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_DI
{REG_PIN_SPI0_DI,                 BITS_AF(0)},
{REG_PIN_SPI0_DI_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_DO
{REG_PIN_SPI0_CLK,                BITS_AF(0)},
{REG_PIN_SPI0_CLK_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//FTID_SPI_CLK
{REG_PIN_USB30_CC_SWITCH,         BITS_AF(3)},
{REG_PIN_USB30_CC_SWITCH_MISC,    BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_Z},//EXT_DCDC_EN    USB30_CC_SWITCH
{REG_PIN_U1TXD,                   BITS_AF(0)},
{REG_PIN_U1TXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U1TXD
{REG_PIN_U1RXD,                   BITS_AF(0)},
{REG_PIN_U1RXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U1RXD
{REG_PIN_IIS1DI,                  BITS_AF(3)},
{REG_PIN_IIS1DI_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//WB_TX_REQ(WB_RTS)
{REG_PIN_IIS1DO,                  BITS_AF(3)},
{REG_PIN_IIS1DO_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//WB_RX_REQ(WB_CTS)   Marlin2 REQ TO BB  HIGH ACTIVE
{REG_PIN_IIS1CLK,                 BITS_AF(3)},
{REG_PIN_IIS1CLK_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//M_DRDY
{REG_PIN_IIS1LRCK,                BITS_AF(3)},
{REG_PIN_IIS1LRCK_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//WB_CHIP_EN
{REG_PIN_U2TXD,                   BITS_AF(0)},
{REG_PIN_U2TXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U2TXD
{REG_PIN_U2RXD,                   BITS_AF(0)},
{REG_PIN_U2RXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U2RXD
{REG_PIN_IIS3CLK,                 BITS_AF(3)},
{REG_PIN_IIS3CLK_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_IIS3LRCK,                BITS_AF(3)},
{REG_PIN_IIS3LRCK_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_IIS3DI,                  BITS_AF(3)},
{REG_PIN_IIS3DI_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_IIS3DO,                  BITS_AF(3)},
{REG_PIN_IIS3DO_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_U4TXD,                   BITS_AF(0)},
{REG_PIN_U4TXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BB_U4TXD
{REG_PIN_U4RXD,                   BITS_AF(0)},
{REG_PIN_U4RXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//BB_U4RXD
{REG_PIN_DCDC_ARM_EN1,            BITS_AF(0)},
{REG_PIN_DCDC_ARM_EN1_MISC,       BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDCPU1_EN
{REG_PIN_SENSOR_HUB_ACTION,       BITS_AF(0)},
{REG_PIN_SENSOR_HUB_ACTION_MISC,  BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//XTL_BUF_EN1
{REG_PIN_PTEST,                   BITS_AF(0)},
{REG_PIN_PTEST_MISC,              BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//GND
{REG_PIN_ANA_INT,                 BITS_AF(0)},
{REG_PIN_ANA_INT_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//ANA_INT
{REG_PIN_EXT_RST_B,               BITS_AF(0)},
{REG_PIN_EXT_RST_B_MISC,          BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//EXT_RST_B
{REG_PIN_AUD_SCLK,                BITS_AF(2)},
{REG_PIN_AUD_SCLK_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_SCLK
{REG_PIN_DCDC_ARM_EN0,            BITS_AF(0)},
{REG_PIN_DCDC_ARM_EN0_MISC,       BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDCPU0_EN
{REG_PIN_CLK_32K,                 BITS_AF(0)},
{REG_PIN_CLK_32K_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//CLK_32K
{REG_PIN_CHIP_SLEEP,              BITS_AF(0)},
{REG_PIN_CHIP_SLEEP_MISC,         BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CHIP_SLEEP
{REG_PIN_AUD_ADD0,                BITS_AF(2)},
{REG_PIN_AUD_ADD0_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//AUD_ADD0
{REG_PIN_AUD_DAD0,                BITS_AF(2)},
{REG_PIN_AUD_DAD0_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DAD0
{REG_PIN_AUD_ADD1,                BITS_AF(2)},
{REG_PIN_AUD_ADD1_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//AUD_ADSYNC
{REG_PIN_AUD_DAD1,                BITS_AF(2)},
{REG_PIN_AUD_DAD1_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DAD1
{REG_PIN_AUD_SYNC,                BITS_AF(2)},
{REG_PIN_AUD_SYNC_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//AUD_DASYNC
{REG_PIN_ADI_SCLK,                BITS_AF(0)},
{REG_PIN_ADI_SCLK_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//ADI_SCLK
{REG_PIN_ADI_D,                   BITS_AF(0)},
{REG_PIN_ADI_D_MISC,              BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//ADI_D
{REG_PIN_MTCK_ARM,                BITS_AF(0)},
{REG_PIN_MTCK_ARM_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//MTCK
{REG_PIN_MTMS_ARM,                BITS_AF(0)},
{REG_PIN_MTMS_ARM_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTMS
{REG_PIN_MTRST_N_ARM,             BITS_AF(0)},
{REG_PIN_MTRST_N_ARM_MISC,        BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTRSTN
{REG_PIN_MTDO_ARM,                BITS_AF(0)},
{REG_PIN_MTDO_ARM_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//MTDO
{REG_PIN_MTDI_ARM,                BITS_AF(0)},
{REG_PIN_MTDI_ARM_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPD|BIT_SLP_Z},//MTDI
{REG_PIN_EXTINT16,                BITS_AF(3)},
{REG_PIN_EXTINT16_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//FTID_INT
//G6
{REG_PIN_IIS0DI,                  BITS_AF(0)},
{REG_PIN_IIS0DI_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_POC|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//BT_PCM_OUT
{REG_PIN_IIS0DO,                  BITS_AF(0)},
{REG_PIN_IIS0DO_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//BT_PCM_IN
{REG_PIN_IIS0CLK,                 BITS_AF(0)},
{REG_PIN_IIS0CLK_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BT_PCM_CLK
{REG_PIN_IIS0LRCK,                BITS_AF(0)},
{REG_PIN_IIS0LRCK_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BT_PCM_SYNC
{REG_PIN_U3TXD,                   BITS_AF(0)},
{REG_PIN_U3TXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//GPS_U0RXD
{REG_PIN_U3RXD,                   BITS_AF(0)},
{REG_PIN_U3RXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//GPS_U0TXD
//G7
{REG_PIN_U3CTS,                   BITS_AF(0)},
{REG_PIN_U3CTS_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//GPS_U0RTS
{REG_PIN_U3RTS,                   BITS_AF(0)},
{REG_PIN_U3RTS_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPU|BIT_SLP_Z},//GPS_U0CTS
{REG_PIN_U0TXD,                   BITS_AF(3)},
{REG_PIN_U0TXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_U0RXD,                   BITS_AF(3)},
{REG_PIN_U0RXD_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_OE},//VDDDDRPLL_EN
{REG_PIN_U0CTS,                   BITS_AF(3)},
{REG_PIN_U0CTS_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_U0RTS,                   BITS_AF(3)},
{REG_PIN_U0RTS_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//NC
{REG_PIN_CLK_AUX0,                BITS_AF(0)},
{REG_PIN_CLK_AUX0_MISC,           BITS_DEF(0x75)|BIT_SLP_ALL|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CON_32K_IN
{REG_PIN_RFCTL39,                 BITS_AF(1)},
{REG_PIN_RFCTL39_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//WB_WCI_2_TXD
{REG_PIN_RFCTL38,                 BITS_AF(1)},
{REG_PIN_RFCTL38_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//WB_WCI_2_RXD
{REG_PIN_WIFI_COEXIST,            BITS_AF(0)},
{REG_PIN_WIFI_COEXIST_MISC,       BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//WF_COEXIST
{REG_PIN_BEIDOU_COEXIST,          BITS_AF(3)},
{REG_PIN_BEIDOU_COEXIST_MISC,     BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPU|BIT_SLP_Z},//VDDGPU_EN
{REG_PIN_EXTINT12,                BITS_AF(3)},
{REG_PIN_EXTINT12_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//CHG_INT
{REG_PIN_EXTINT11,                BITS_AF(3)},
{REG_PIN_EXTINT11_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//M_INT
{REG_PIN_EXTINT10,                BITS_AF(3)},
{REG_PIN_EXTINT10_MISC,           BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//PRE_INT
{REG_PIN_EXTINT9,                 BITS_AF(3)},
{REG_PIN_EXTINT9_MISC,            BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//PROX_INT
{REG_PIN_EXTINT8,                 BITS_AF(3)},
{REG_PIN_EXTINT8_MISC,            BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//AG_INT1
{REG_PIN_EXTINT7,                 BITS_AF(3)},
{REG_PIN_EXTINT7_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//SIM0_DET
{REG_PIN_EXTINT6,                 BITS_AF(3)},
{REG_PIN_EXTINT6_MISC,            BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//AG_INT0
{REG_PIN_EXTINT5,                 BITS_AF(3)},
{REG_PIN_EXTINT5_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPU|BIT_SLP_WPU|BIT_SLP_IE},//TF_DET
{REG_PIN_DSI_TE,                  BITS_AF(0)},
{REG_PIN_DSI_TE_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_IE},//LCM_FMARK
{REG_PIN_LCM_RSTN,                BITS_AF(3)},
{REG_PIN_LCM_RSTN_MISC,           BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_RSTN
{REG_PIN_PWMA,                    BITS_AF(0)},
{REG_PIN_PWMA_MISC,               BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_BL_PWM
{REG_PIN_SCL2,                    BITS_AF(0)},
{REG_PIN_SCL2_MISC,               BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C2_SCL        CM4
{REG_PIN_SDA2,                    BITS_AF(0)},
{REG_PIN_SDA2_MISC,               BITS_DEF(0x75)|BIT_SLP_NONE|BITS_STR(1)|BIT_WPUS|BIT_SLP_WPU|BIT_SLP_Z},//I2C2_SDA        CM4
//G9
{REG_PIN_CMPD1,                   BITS_AF(3)},
{REG_PIN_CMPD1_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_PWDN1
{REG_PIN_CMPD0,                   BITS_AF(3)},
{REG_PIN_CMPD0_MISC,              BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_PWDN0
{REG_PIN_CMRST1,                  BITS_AF(3)},
{REG_PIN_CMRST1_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_RST1
{REG_PIN_CMRST0,                  BITS_AF(3)},
{REG_PIN_CMRST0_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_RST0
{REG_PIN_CMMCLK1,                 BITS_AF(0)},
{REG_PIN_CMMCLK1_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_MCLK1
{REG_PIN_CMMCLK,                  BITS_AF(0)},
{REG_PIN_CMMCLK_MISC,             BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAM_MCLK0
{REG_PIN_RFSEN0,                  BITS_AF(0)},
{REG_PIN_RFSEN0_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSEN
{REG_PIN_RFSCK0,                  BITS_AF(0)},
{REG_PIN_RFSCK0_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSCK
{REG_PIN_RFSDA0,                  BITS_AF(0)},
{REG_PIN_RFSDA0_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFSDA
{REG_PIN_RFSEN1,                  BITS_AF(0)},
{REG_PIN_RFSEN1_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSEN
{REG_PIN_RFSCK1,                  BITS_AF(0)},
{REG_PIN_RFSCK1_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSCK
{REG_PIN_RFSDA1,                  BITS_AF(0)},
{REG_PIN_RFSDA1_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFSDA
{REG_PIN_RFCTL27,                 BITS_AF(0)},
{REG_PIN_RFCTL27_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL26,                 BITS_AF(0)},
{REG_PIN_RFCTL26_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
//G10
{REG_PIN_RFCTL31,                 BITS_AF(3)},
{REG_PIN_RFCTL31_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_SOURCE_AVEEEN
{REG_PIN_RFCTL30,                 BITS_AF(3)},
{REG_PIN_RFCTL30_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//LCM_SOURCE_AVDDEN
{REG_PIN_RF_LVDS0_ADC_ON,         BITS_AF(0)},
{REG_PIN_RF_LVDS0_ADC_ON_MISC,    BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RF_LVDS0_DAC_ON,         BITS_AF(0)},
{REG_PIN_RF_LVDS0_DAC_ON_MISC,    BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RF_LVDS1_ADC_ON,         BITS_AF(0)},
{REG_PIN_RF_LVDS1_ADC_ON_MISC,    BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RF_LVDS1_DAC_ON,         BITS_AF(0)},
{REG_PIN_RF_LVDS1_DAC_ON_MISC,    BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_SDA4,                    BITS_AF(0)},
{REG_PIN_SDA4_MISC,               BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C4_SDA
{REG_PIN_SCL4,                    BITS_AF(0)},
{REG_PIN_SCL4_MISC,               BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C4_SCL
{REG_PIN_SDA0,                    BITS_AF(0)},
{REG_PIN_SDA0_MISC,               BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C0_SDA
{REG_PIN_SCL0,                    BITS_AF(0)},
{REG_PIN_SCL0_MISC,               BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C0_SCL
{REG_PIN_RFCTL29,                 BITS_AF(0)},
{REG_PIN_RFCTL29_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL28,                 BITS_AF(0)},
{REG_PIN_RFCTL28_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFFE0_SDA0,              BITS_AF(0)},
{REG_PIN_RFFE0_SDA0_MISC,         BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFFE_SDA0
{REG_PIN_RFFE0_SCK0,              BITS_AF(0)},
{REG_PIN_RFFE0_SCK0_MISC,         BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//PCC_RFFE_SCK0
{REG_PIN_RFFE1_SDA0,              BITS_AF(0)},
{REG_PIN_RFFE1_SDA0_MISC,         BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_WPD|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFFE_SDA0
{REG_PIN_RFFE1_SCK0,              BITS_AF(0)},
{REG_PIN_RFFE1_SCK0_MISC,         BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_WPD|BIT_SLP_Z},//SCC_RFFE_SCK0
{REG_PIN_RFCTL0,                  BITS_AF(0)},
{REG_PIN_RFCTL0_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//APT_DCDC_BYPASS_EN
{REG_PIN_RFCTL1,                  BITS_AF(0)},
{REG_PIN_RFCTL1_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//APT_DCDC_FSEL
//G11
{REG_PIN_RFCTL2,                  BITS_AF(0)},
{REG_PIN_RFCTL2_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_POC|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//APT_DCDC_EN
{REG_PIN_RFCTL3,                  BITS_AF(0)},
{REG_PIN_RFCTL3_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL3
{REG_PIN_RFCTL4,                  BITS_AF(0)},
{REG_PIN_RFCTL4_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL4
{REG_PIN_RFCTL5,                  BITS_AF(0)},
{REG_PIN_RFCTL5_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL5
{REG_PIN_RFCTL6,                  BITS_AF(0)},
{REG_PIN_RFCTL6_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//RFCTL6
{REG_PIN_RFCTL7,                  BITS_AF(0)},
{REG_PIN_RFCTL7_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL8,                  BITS_AF(0)},
{REG_PIN_RFCTL8_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC(GPIO15)
{REG_PIN_RFCTL9,                  BITS_AF(0)},
{REG_PIN_RFCTL9_MISC,             BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC(GPIO16)
{REG_PIN_RFCTL10,                 BITS_AF(0)},
{REG_PIN_RFCTL10_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL11,                 BITS_AF(3)},
{REG_PIN_RFCTL11_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID3
{REG_PIN_RFCTL12,                 BITS_AF(0)},
{REG_PIN_RFCTL12_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL13,                 BITS_AF(0)},
{REG_PIN_RFCTL13_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL14,                 BITS_AF(0)},
{REG_PIN_RFCTL14_MISC,            BITS_DEF(0x75)|BIT_SLP_ALL_CP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//NC
{REG_PIN_RFCTL15,                 BITS_AF(3)},
{REG_PIN_RFCTL15_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID2
{REG_PIN_RFCTL16,                 BITS_AF(3)},
{REG_PIN_RFCTL16_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//GPS_GPIO0
{REG_PIN_RFCTL17,                 BITS_AF(3)},
{REG_PIN_RFCTL17_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAMERA_FLASH_EN1
{REG_PIN_RFCTL18,                 BITS_AF(3)},
{REG_PIN_RFCTL18_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//IRLED_EN
{REG_PIN_RFCTL19,                 BITS_AF(3)},
{REG_PIN_RFCTL19_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID1
{REG_PIN_RFCTL20,                 BITS_AF(3)},
{REG_PIN_RFCTL20_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//CAMERA_FLASH_EN0
{REG_PIN_RFCTL21,                 BITS_AF(3)},
{REG_PIN_RFCTL21_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//BOARD_ID0
{REG_PIN_RFCTL22,                 BITS_AF(3)},
{REG_PIN_RFCTL22_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_OE},//VDDGPU_EN
{REG_PIN_RFCTL23,                 BITS_AF(2)},
{REG_PIN_RFCTL23_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C5_SCL
{REG_PIN_RFCTL24,                 BITS_AF(2)},
{REG_PIN_RFCTL24_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_WPUS2|BIT_SLP_WPU|BIT_SLP_Z},//I2C5_SDA
{REG_PIN_RFCTL25,                 BITS_AF(3)},
{REG_PIN_RFCTL25_MISC,            BITS_DEF(0x75)|BIT_SLP_AP|BITS_STR(1)|BIT_NUL|BIT_SLP_NUL|BIT_SLP_IE},//GPIO166

// SPRD 
//G1
{REG_PIN_SD2_CMD,                 BITS_PIN_AF(3)},
{REG_PIN_SD2_CMD_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D0,                  BITS_PIN_AF(3)},
{REG_PIN_SD2_D0_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D1,                  BITS_PIN_AF(3)},
{REG_PIN_SD2_D1_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_CLK,                 BITS_PIN_AF(3)},
{REG_PIN_SD2_CLK_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D2,                  BITS_PIN_AF(3)},
{REG_PIN_SD2_D2_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SD2_D3,                  BITS_PIN_AF(3)},
{REG_PIN_SD2_D3_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
//G2
{REG_PIN_KEYOUT0,                 BITS_PIN_AF(3)},
{REG_PIN_KEYOUT0_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//WB_RST
{REG_PIN_KEYOUT1,                 BITS_PIN_AF(3)},
{REG_PIN_KEYOUT1_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_KEYOUT2,                 BITS_PIN_AF(3)},
{REG_PIN_KEYOUT2_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//WB_INT
{REG_PIN_KEYIN0,                  BITS_PIN_AF(1)},
{REG_PIN_KEYIN0_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN0
{REG_PIN_KEYIN1,                  BITS_PIN_AF(1)},
{REG_PIN_KEYIN1_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN1
{REG_PIN_KEYIN2,                  BITS_PIN_AF(3)},
{REG_PIN_KEYIN2_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//SIM1_DET 
//G3
{REG_PIN_SD0_D0,                  BITS_PIN_AF(0)},
{REG_PIN_SD0_D0_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D0    14mA
{REG_PIN_SD0_D1,                  BITS_PIN_AF(0)},
{REG_PIN_SD0_D1_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D1
{REG_PIN_SD0_CLK0,                BITS_PIN_AF(0)},
{REG_PIN_SD0_CLK0_MISC,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//TF_SD0_CLK0
{REG_PIN_SD0_CMD,                 BITS_PIN_AF(0)},
{REG_PIN_SD0_CMD_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_CMD
{REG_PIN_SD0_D2,                  BITS_PIN_AF(0)},
{REG_PIN_SD0_D2_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D2
{REG_PIN_SD0_D3,                  BITS_PIN_AF(0)},
{REG_PIN_SD0_D3_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(6)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D3
//G5
{REG_PIN_SIMCLK2,                 BITS_PIN_AF(3)},
{REG_PIN_SIMCLK2_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMDA2,                  BITS_PIN_AF(3)},
{REG_PIN_SIMDA2_MISC,             BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMRST2,                 BITS_PIN_AF(3)},
{REG_PIN_SIMRST2_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SIMCLK1,                 BITS_PIN_AF(0)},
{REG_PIN_SIMCLK1_MISC,            BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_CLK
{REG_PIN_SIMDA1,                  BITS_PIN_AF(0)},
{REG_PIN_SIMDA1_MISC,             BIT_PIN_SLP_PUBCP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM1_DA
{REG_PIN_SIMRST1,                 BITS_PIN_AF(0)},
{REG_PIN_SIMRST1_MISC,            BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_RST
{REG_PIN_SIMCLK0,                 BITS_PIN_AF(0)},
{REG_PIN_SIMCLK0_MISC,            BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_CLK
{REG_PIN_SIMDA0,                  BITS_PIN_AF(0)},
{REG_PIN_SIMDA0_MISC,             BIT_PIN_SLP_PUBCP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM0_DA
{REG_PIN_SIMRST0,                 BITS_PIN_AF(0)},
{REG_PIN_SIMRST0_MISC,            BIT_PIN_SLP_PUBCP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_RST
//G6
{REG_PIN_EMMC_CLK,                BITS_PIN_AF(0)},
{REG_PIN_EMMC_CLK_MISC,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_CLK
{REG_PIN_EMMC_RSTB,               BITS_PIN_AF(0)},
{REG_PIN_EMMC_RSTB_MISC,          BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_RST
{REG_PIN_EMMC_CMD,                BITS_PIN_AF(0)},
{REG_PIN_EMMC_CMD_MISC,           BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_CMD
{REG_PIN_EMMC_D0,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D0_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D0
{REG_PIN_EMMC_D1,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D1_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D1
{REG_PIN_EMMC_D2,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D2_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D2
{REG_PIN_EMMC_D3,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D3_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D3
{REG_PIN_EMMC_D4,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D4_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D4
{REG_PIN_EMMC_D5,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D5_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D5
{REG_PIN_EMMC_D6,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D6_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D6
{REG_PIN_EMMC_D7,                 BITS_PIN_AF(0)},
{REG_PIN_EMMC_D7_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D7
{REG_PIN_EMMC_STROBE,             BITS_PIN_AF(0)},
{REG_PIN_EMMC_STROBE_MISC,        BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPD|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//EMMC_RLCK
{REG_PIN_SD1_CMD,                 BITS_PIN_AF(0)},
{REG_PIN_SD1_CMD_MISC,            BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_CMD
{REG_PIN_SD1_D0,                  BITS_PIN_AF(0)},
{REG_PIN_SD1_D0_MISC,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D0
{REG_PIN_SD1_D1,                  BITS_PIN_AF(0)},
{REG_PIN_SD1_D1_MISC,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D1
{REG_PIN_SD1_CLK,                 BITS_PIN_AF(0)},
{REG_PIN_SD1_CLK_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(5)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//WF_SD1_CLK
{REG_PIN_SD1_D2,                  BITS_PIN_AF(0)},
{REG_PIN_SD1_D2_MISC,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D2
{REG_PIN_SD1_D3,                  BITS_PIN_AF(0)},
{REG_PIN_SD1_D3_MISC,             BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//WF_SD1_D3
//G7
{REG_PIN_SDA1,                    BITS_PIN_AF(0)},
{REG_PIN_SDA1_MISC,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//CTP_SDA
{REG_PIN_SCL1,                    BITS_PIN_AF(0)},
{REG_PIN_SCL1_MISC,               BIT_PIN_SLP_AP|BIT_PIN_WPUS|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//CTP_SCL
{REG_PIN_EXTINT1,                 BITS_PIN_AF(3)},
{REG_PIN_EXTINT1_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_NUL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CTP_RST
{REG_PIN_EXTINT0,                 BITS_PIN_AF(3)},
{REG_PIN_EXTINT0_MISC,            BIT_PIN_SLP_AP|BIT_PIN_NULL|BITS_PIN_DS(1)|BIT_PIN_WPU|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//CTP_INT
};



/*here is the adie pinmap such as 2731*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//VR_INT        VOICE-DSP-ALC5512  Active High
{REG_PIN_ANA_EXT_XTL_EN1,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//XTL_BUF_EN0
{REG_PIN_ANA_EXT_XTL_EN2,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//XTL_BUF_EN1
{REG_PIN_ANA_EXT_XTL_EN3,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//WB_CLK_REQ    BCM43455 Active High when BT need host to turn on reference clock
};

int  pin_init_a0chip(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, CTL_PIN_BASE + pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	return 0;
}

