#include <common.h>
#include <asm/io.h>
#include <asm/arch/sprd_reg.h>
#include "adi_hal_internal.h"
#include <asm/arch/common.h>
#include <otp_helper.h>
#include <sprd_pmic_misc.h>
#include <chipram_env.h>
#include <hwfeature.h>

typedef enum {
	ROC1_AA = 1,
	ROC1_AB = 3,
	ROC1_AD = 4
};

static unsigned int get_chip_id(struct hwfeature *phwf)
{
	int reg_val;

	phwf = phwf;

	reg_val = __raw_readl(REG_AON_APB_AON_VER_ID);

	if (1 == reg_val)
		return ROC1_AA;
	else if (3 == reg_val)
		return ROC1_AB;
	else
		return ROC1_AD;

}

static void fdt_fixup_idle_states_dts(struct hwfeature *phwf)
{
	int err;
	unsigned int value[] = {1000, 500, 2500};
	char *lit_core_member[] = {"entry-latency-us", "exit-latency-us", "min-residency-us"};
	int offset,v_index;
	void *fdt = phwf->fdt;

	typedef enum {
		LIT_ENTRY_LATENCY_US = 0,
		LIT_EXIT_LATENCY_US,
		LIT_MIN_RESIDENCY_US,
		IDLE_STATES_MAX
	} idle_states_type;

	if (get_chip_id(phwf) == ROC1_AA)
		return;

	offset = fdt_path_offset(fdt, "/idle-states");
	if (offset < 0) {
		errorf("cann't find idle-states node\n");
		return;
	}

	offset = fdt_subnode_offset(fdt, offset, "lit_core_pd");
	if (offset == -FDT_ERR_NOTFOUND) {
		errorf("cann't find lit_core_pd node\n");
		return;
	}

	for (v_index = LIT_ENTRY_LATENCY_US; v_index <= LIT_MIN_RESIDENCY_US; v_index++) {
		err = fdt_setprop_u32(fdt, offset, lit_core_member[v_index], value[v_index]);
		if (err < 0) {
			errorf("ERROR: cannot set idle-states node's %s value!\n", lit_core_member[v_index]);
			return;
		}
	}
}

static void late_initcall(struct hwfeature *phwf, void *fdt)
{
	fdt_fixup_idle_states_dts(phwf);
}

/*
	REG_AON_APB_BOND_OPT0  ==> romcode set
	REG_AON_APB_BOND_OPT1  ==> set it later

	!!! notice: these two registers can be set only one time!!!

	B1[0] : B0[0]
	0     : 0     Jtag enable
	0     : 1     Jtag disable
	1     : 0     Jtag enable
	1     : 1     Jtag enable
*/

/*************************************************
* 1 : enable jtag success                        *
* 0 : enable jtag fail                           *
*************************************************/
int sprd_jtag_enable()
{
	return 1;
}

/*************************************************
* 1 : disable jtag success                       *
* 0 : disable jtag fail                          *
*************************************************/
int sprd_jtag_disable()
{
}

static void ap_slp_cp_dbg_cfg()
{
//	*((volatile unsigned int *)(REG_AP_AHB_MCU_PAUSE)) |= BIT_MCU_SLEEP_FOLLOW_APCPU_EN; //when ap sleep, cp can continue debug
}

static void ap_cpll_rel_cfg()
{
}

static void bb_bg_auto_en()
{
	*((volatile unsigned int *)(REG_AON_APB_RES_REG0)) |= 1<<8;
}


static void ap_close_wpll_en()
{
}

static void ap_close_cpll_en()
{
}

static void ap_close_wifipll_en()
{
}


static void bb_ldo_auto_en()
{
	*((volatile unsigned int *)(REG_AON_APB_RES_REG0)) |= 1<<9;
}


#ifdef CONFIG_OF_LIBFDT
void scx35_pmu_reconfig(void)
{
	/* FIXME:
	 * turn on gpu/mm domain for clock device initcall, and then turn off asap.
	 */
	REG32(REG_AON_APB_APB_EB0) |= BIT_AON_APB_GPU_EB;
#ifndef CONFIG_SOC_ROC1
	REG32(REG_AON_APB_APB_EB1) |= BIT_AON_APB_DISP_EB;
	REG32(REG_AON_APB_APB_EB1) |= BIT_AON_APB_CAM_EB;
	REG32(REG_AON_APB_APB_EB1) |= BIT_AON_APB_VSP_EB;
#endif
}

#else
void scx35_pmu_reconfig(void) {}
#endif

#define KLT8	0x6B4C5438
#define KL	0x6B4C0000
#define SHAR	0x53686172
#define E2	0x65320000
#define WHAL	0x5768616C

int sprd_get_chipid(int *chip_id, int *version_id)
{

	unsigned int chip_id0 = 0, chip_id1 = 0;
	int ch_id;
	int ver_id;

	chip_id0 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID0);
	chip_id1 = __raw_readl((void *)REG_AON_APB_AON_CHIP_ID1);

	switch (chip_id1) {
	case SHAR:
		switch (chip_id0) {
		case KL:
			ch_id = 0x9830;
			break;
		case KLT8:
			ch_id = 0x9838;
			break;
		default:
			ch_id = 0;
			break;
		}
		break;

	case WHAL:
		switch (chip_id0) {
		case E2:
			ch_id = 0x9850;
			break;
		default:
			ch_id = 0;
			break;
		}
		break;

	default:
		ch_id = 0;
		break;
	}

	ver_id = __raw_readl((void *)REG_AON_APB_AON_VER_ID);

	if (!chip_id || !version_id) {
		debugf("chip id = 0x%x, VID = 0x%x\n",ch_id, ver_id);
		return 0;
	}

	*chip_id = ch_id;
	*version_id = ver_id;

	return 0;
}

#if defined CONFIG_SMT

void set_smt(void)
{
	if(0x00 == CONFIG_SMT_VALUE){
		__raw_writel(__raw_readl(JVT_MT_CFG) & (~(0x3)),JVT_MT_CFG);/*open smt*/
	}else if(0x01 == CONFIG_SMT_VALUE){
		__raw_writel(__raw_readl(JVT_MT_CFG) | 0x3,JVT_MT_CFG);/*close smt*/
	}else if(0x10 == CONFIG_SMT_VALUE){
		/*get config info from mmc*/
	}
}

#endif

void misc_init()
{
	scx35_pmu_reconfig();
	ap_slp_cp_dbg_cfg();
	ap_cpll_rel_cfg();
#ifndef  CONFIG_SPX15
	ap_close_wpll_en();
	ap_close_cpll_en();
	ap_close_wifipll_en();
#endif
	bb_bg_auto_en();
	bb_ldo_auto_en();

	pmic_misc_init();

	sprd_get_chipid(NULL, NULL);

	hwfeature_hook_get_chipid(get_chip_id);

#if defined CONFIG_SMT
	set_smt();
#endif
	hwfeature_hook_late_initcall(late_initcall);
}

typedef struct mem_cs_info
{
	uint32_t cs_number;
	uint32_t cs0_size;//bytes
	uint32_t cs1_size;//bytes
}mem_cs_info_t;
PUBLIC int get_dram_cs_number(void)
{
	mem_cs_info_t *cs_info_ptr = 0x1C00;
	return cs_info_ptr->cs_number;
}
PUBLIC int get_dram_cs0_size(void)
{
	mem_cs_info_t *cs_info_ptr = 0x1C00;
	return cs_info_ptr->cs0_size;
}

boot_device_t get_bootdevice(void)
{
	unsigned int boot_val = 0;

	boot_val = (* (volatile unsigned int *) (REG_AON_APB_BOOT_MODE)) & 0x3;
	if (boot_val == 0x3)
		return BOOT_DEVICE_EMMC;
	else
		return BOOT_DEVICE_UFS;
}

