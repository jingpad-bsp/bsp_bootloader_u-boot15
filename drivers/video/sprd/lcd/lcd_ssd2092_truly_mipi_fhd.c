/*
 * Copyright (C) 2017 Spreadtrum Communications Inc.
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

#include "sprd_panel.h"
#include "sprd_dsi.h"
#include "dsi/mipi_dsi_api.h"
#include "sprd_dphy.h"

#ifdef CONFIG_SC2703_LCD_POWERON
extern void lcd_use_sc2703l_to_power_boost(void);
#endif

static uint8_t init_data[] = {
	0x29, 0x00, 0x00, 0x03, 0xB5, 0x00, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x03, 0x96,
	0x29, 0x00, 0x00, 0x03, 0xB4, 0x21, 0xFF,
	0x29, 0x00, 0x00, 0x03, 0xE1, 0x00, 0x00,
	0x29, 0x00, 0x00, 0x04, 0xE1, 0x03, 0x00, 0x10,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x04, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x07, 0x14,
	0x29, 0x00, 0x00, 0x03, 0xC6, 0x04, 0x2D,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x0E, 0x44,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x0C, 0x26,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x08, 0x99,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x23, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xC2, 0x04, 0x0F,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x11, 0x22,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x12, 0x22,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x13, 0x22,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x19, 0x0B,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x3D, 0xC8,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x0F, 0x20,
	0x29, 0x00, 0x00, 0x02, 0x36, 0x02,
	0x29, 0x00, 0x00, 0x03, 0xC7, 0x01, 0x09,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x15, 0x80,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x1E, 0x02,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x14, 0xC0,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x16, 0x50,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x1C, 0xE4,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x28, 0x09,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x24, 0x19,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x12, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x13, 0x14,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x1A, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x1B, 0x14,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x0D, 0x87,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x0E, 0x87,
	0x29, 0x00, 0x00, 0x17, 0xC3, 0x00, 0x10, 0x2E, 0x3E, 0x48, 0x5E, 0x6B, 0x7A, 0x83, 0x97, 0xA3, 0xA8, 0xA5, 0xAC, 0xAD, 0xB5, 0xC1, 0xC4, 0x4E, 0x4F, 0x59, 0x5A,
	0x29, 0x00, 0x00, 0x17, 0xC3, 0x15, 0x10, 0x2E, 0x3E, 0x48, 0x5E, 0x6B, 0x7A, 0x83, 0x97, 0xA3, 0xA8, 0xA5, 0xAC, 0xAD, 0xB5, 0xC1, 0xC4, 0x4E, 0x4F, 0x59, 0x5A,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x01, 0x8A,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x02, 0x23,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x03, 0xBC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x04, 0xC0,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x05, 0x19,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x06, 0x37,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x07, 0xEE,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x08, 0xDD,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x09, 0xCC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0A, 0x36,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0B, 0x70,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0C, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0D, 0x8A,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0E, 0x23,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x0F, 0xBC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x10, 0xC0,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x11, 0x18,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x12, 0xA7,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x13, 0xEE,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x14, 0xDD,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x15, 0xCC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x16, 0x36,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x17, 0x70,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x18, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x31, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x00, 0xF0,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x01, 0xF0,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x02, 0xF0,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x03, 0xF0,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x1A, 0x02,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x1B, 0x24,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x1D, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x1E, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x21, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x1F, 0x79,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x20, 0x14,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x22, 0x89,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x23, 0x13,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x24, 0x35,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x26, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x27, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2A, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x28, 0x79,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x29, 0x14,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2B, 0x89,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2C, 0x33,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2D, 0x33,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2E, 0x11,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x2F, 0x11,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x31, 0x22,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x32, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x33, 0x04,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x34, 0x11,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x35, 0x11,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x37, 0x22,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x38, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x39, 0x04,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x3A, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x3B, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x3C, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x3D, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x40, 0xAA,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x42, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x43, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x44, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x45, 0x1E,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x48, 0xAA,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x02, 0x05,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x03, 0x01,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x1E, 0x71,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x24, 0x83,
	0x29, 0x00, 0x00, 0x03, 0xB8, 0x03, 0xA9,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x15, 0x41,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x19, 0x8A,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1A, 0x32,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1B, 0xBC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1C, 0xC2,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1D, 0x39,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1E, 0x37,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x1F, 0xEE,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x20, 0xDD,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x21, 0xCC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x22, 0x36,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x23, 0x70,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x24, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x25, 0x8A,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x26, 0x32,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x27, 0xBC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x28, 0xC2,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x29, 0x38,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2A, 0xA7,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2B, 0xEE,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2C, 0xDD,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2D, 0xCC,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2E, 0x36,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x2F, 0x70,
	0x29, 0x00, 0x00, 0x03, 0xBB, 0x30, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB8, 0x15, 0xA2,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x39, 0x00,
	0x29, 0x00, 0x00, 0x04, 0xC6, 0x00, 0x03, 0x40,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x18, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x17, 0x28,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x23, 0x15,
	0x29, 0x00, 0x00, 0x03, 0xB0, 0x06, 0x2C,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x17, 0x28,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x23, 0x15,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x16, 0x00,
	0x29, 0x00, 0x00, 0x04, 0xBA, 0x28, 0x02, 0x02,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x0F, 0x8C,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x10, 0x0C,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x11, 0x23,
	0x29, 0x00, 0x00, 0x05, 0xBA, 0x12, 0x9D, 0x9D, 0x9D,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x25, 0x22,
	0x29, 0x00, 0x00, 0x04, 0xBA, 0x0D, 0x40, 0x02,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x2F, 0x8C,
	0x29, 0x00, 0x00, 0x03, 0xC2, 0x04, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xC2, 0x05, 0xC0,
	0x29, 0x00, 0x00, 0x0b, 0xB9, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x15, 0x33,
	0x29, 0x00, 0x00, 0x06, 0xB9, 0x00, 0x5F, 0x5F, 0x61, 0x0A,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x08, 0x07,
	0x29, 0x00, 0x00, 0x03, 0xBD, 0x09, 0x07,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x03, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x04, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x05, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x07, 0x10,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x08, 0x10,
	0x29, 0x00, 0x00, 0x03, 0xBC, 0x09, 0x10,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x11, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x12, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x13, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x1D, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x1E, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x1F, 0x00,
	0x29, 0x00, 0x00, 0x03, 0xC2, 0x00, 0x07,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x0B, 0x1F,
	0x29, 0x00, 0x00, 0x03, 0xB1, 0x05, 0x2F,
	0x29, 0x00, 0x00, 0x02, 0x35, 0x00,
	0x29, 0x00, 0x00, 0x04, 0xB0, 0x01, 0x08, 0x70,
	0x29, 0x00, 0x00, 0x03, 0xB9, 0x25, 0xA0,
	0x29, 0x00, 0x00, 0x03, 0xBA, 0x2F, 0xCC,
	0x29, 0x00, 0x00, 0x03, 0xC1, 0x02, 0xB0,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x1C, 0xC4,
	0x29, 0x00, 0x00, 0x03, 0xB3, 0x1D, 0x80,
	0x29, 0x00, 0x00, 0x04, 0xBD, 0x11, 0x02, 0x22,
	0x29, 0x00, 0x00, 0x02, 0x36, 0x0A,
	0x39, 0x00, 0x00, 0x02, 0x51, 0xFF,
	0x39, 0x00, 0x00, 0x02, 0x53, 0x2C,
	0x39, 0x00, 0x00, 0x02, 0x55, 0x00,
	0x05, 0x14, 0x00, 0x01, 0x11,
	0x05, 0x64, 0x00, 0x01, 0x29,
	CMD_END
};

static int mipi_dsi_send_cmds(struct sprd_dsi *dsi, void *data)
{
	uint16_t len;
	struct dsi_cmd_desc *cmds = data;

	if ((cmds == NULL) || (dsi == NULL))
		return -1;

	for (; cmds->data_type != CMD_END;) {
		len = (cmds->wc_h << 8) | cmds->wc_l;
		mipi_dsi_gen_write(dsi, cmds->payload, len);
		if (cmds->wait)
			msleep(cmds->wait);
		cmds = (struct dsi_cmd_desc *)(cmds->payload + len);
	}
	return 0;
}

static int ssd2092_init(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	struct sprd_dphy *dphy = &dphy_device;

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_send_cmds(dsi, init_data);
	mipi_dsi_set_work_mode(dsi, SPRD_MIPI_MODE_VIDEO);
	mipi_dsi_state_reset(dsi);
	mipi_dphy_hs_clk_en(dphy, true);

	return 0;
}

static int ssd2092_readid(void)
{
	struct sprd_dsi *dsi = &dsi_device;
	uint8_t read_buf[3] = {0xff, 0xff, 0xff};
	uint8_t read_buf1[1] = {0xff};

	mipi_dsi_lp_cmd_enable(dsi, true);
	mipi_dsi_set_max_return_size(dsi, 3);
	mipi_dsi_dcs_read(dsi, 0x04, read_buf, 3);
	mipi_dsi_dcs_read(dsi, 0xA1, read_buf1, 1);

	if (((0x00 == read_buf[0]) && (0x00 == read_buf[1]) &&
	     (0xb2 == read_buf[2])) ||
	    ((0x00 == read_buf[0]) && (0x00 == read_buf[1]) &&
	     (0x00 == read_buf[2]) && (0x01 == read_buf1[0]))) {
		pr_info("ssd2092 read id success!\n");
	#ifdef CONFIG_SC2703_LCD_POWERON
		pr_info("ssd2092 need boost avdd/avee to 5.8v\n");
		lcd_use_sc2703l_to_power_boost();
	#endif
		return 0;
        }
	pr_err("read_buf[0] = 0x%x, read_buf[1] = 0x%x, read_buf[2] = 0x%x\n", read_buf[0], read_buf[1], read_buf[2]);
	return -1;
}

static int ssd2092_power(int on)
{

	if (on) {
#ifdef CONFIG_LCM_GPIO_AVDDEN
                sprd_gpio_request(NULL, CONFIG_LCM_GPIO_AVDDEN);
                sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_AVDDEN, 1);
                mdelay(10);
#endif
#ifdef CONFIG_LCM_GPIO_AVEEEN
                sprd_gpio_request(NULL, CONFIG_LCM_GPIO_AVEEEN);
                sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_AVEEEN, 1);
                mdelay(20);
#endif

		sprd_gpio_request(NULL, CONFIG_LCM_GPIO_RSTN);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 1);
		mdelay(20);
	} else {
		sprd_gpio_direction_output(NULL, CONFIG_LCM_GPIO_RSTN, 0);
		mdelay(5);
	}

	return 0;
}

static struct panel_ops ssd2092_ops = {
	.init = ssd2092_init,
	.read_id = ssd2092_readid,
	.power = ssd2092_power,
};

static struct panel_info ssd2092_info = {
	/* common parameters */
	.lcd_name = "lcd_ssd2092_truly_mipi_fhd",
	.type = SPRD_PANEL_TYPE_MIPI,
	.bpp = 24,
//	.fps = 60,
	.width = 1080,
	.height = 2160,

	/* DPI specific parameters */
	.pixel_clk = 153600000, /*Hz*/
	.rgb_timing = {
		.hfp = 20,
		.hbp = 20,
		.hsync = 4,
		.vfp = 76,
		.vbp = 43,
		.vsync = 1,
	},

	/* MIPI DSI specific parameters */
	.phy_freq = 1100000,
	.lane_num = 4,
	.work_mode = SPRD_MIPI_MODE_VIDEO,
	.burst_mode = VIDEO_BURST_WITH_SYNC_PULSES,
	.nc_clk_en = false,
};

struct panel_driver ssd2092_truly_driver = {
	.info = &ssd2092_info,
	.ops = &ssd2092_ops,
};
