/*
 * cs42xx8.h - Cirrus Logic CS42448/CS42888 Audio CODEC driver header file
 *
 * Copyright (C) 2014 Freescale Semiconductor, Inc.
 *
 * Author: Nicolin Chen <Guangyu.Chen@freescale.com>
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#ifndef _CS42XX8_H
#define _CS42XX8_H

struct cs42xx8_driver_data {
	char name[32];
	int num_adcs;
};

extern const struct dev_pm_ops cs42xx8_pm;
extern const struct cs42xx8_driver_data cs42448_data;
extern const struct cs42xx8_driver_data cs42888_data;
extern const struct regmap_config cs42xx8_regmap_config;
int cs42xx8_probe(struct device *dev, struct regmap *regmap, struct cs42xx8_driver_data *drvdata);

/* CS42888 register map */
#define CS42XX8_CHIPID				0x01	/* Chip ID */
#define CS42XX8_PWRCTL				0x02	/* Power Control */
#define CS42XX8_FUNCMOD				0x03	/* Functional Mode */
#define CS42XX8_INTF				0x04	/* Interface Formats */
#define CS42XX8_ADCCTL				0x05	/* ADC Control */
#define CS42XX8_TXCTL				0x06	/* Transition Control */
#define CS42XX8_DACMUTE				0x07	/* DAC Mute Control */
#define CS42XX8_VOLAOUT1			0x08	/* Volume Control AOUT1 */
#define CS42XX8_VOLAOUT2			0x09	/* Volume Control AOUT2 */
#define CS42XX8_VOLAOUT3			0x0A	/* Volume Control AOUT3 */
#define CS42XX8_VOLAOUT4			0x0B	/* Volume Control AOUT4 */
#define CS42XX8_VOLAOUT5			0x0C	/* Volume Control AOUT5 */
#define CS42XX8_VOLAOUT6			0x0D	/* Volume Control AOUT6 */
#define CS42XX8_VOLAOUT7			0x0E	/* Volume Control AOUT7 */
#define CS42XX8_VOLAOUT8			0x0F	/* Volume Control AOUT8 */
#define CS42XX8_DACINV				0x10	/* DAC Channel Invert */
#define CS42XX8_VOLAIN1				0x11	/* Volume Control AIN1 */
#define CS42XX8_VOLAIN2				0x12	/* Volume Control AIN2 */
#define CS42XX8_VOLAIN3				0x13	/* Volume Control AIN3 */
#define CS42XX8_VOLAIN4				0x14	/* Volume Control AIN4 */
#define CS42XX8_VOLAIN5				0x15	/* Volume Control AIN5 */
#define CS42XX8_VOLAIN6				0x16	/* Volume Control AIN6 */
#define CS42XX8_ADCINV				0x17	/* ADC Channel Invert */
#define CS42XX8_STATUSCTL			0x18	/* Status Control */
#define CS42XX8_STATUS				0x19	/* Status */
#define CS42XX8_STATUSM				0x1A	/* Status Mask */
#define CS42XX8_MUTEC				0x1B	/* MUTEC Pin Control */

#define CS42XX8_FIRSTREG			CS42XX8_CHIPID
#define CS42XX8_LASTREG				CS42XX8_MUTEC
#define CS42XX8_NUMREGS				(CS42XX8_LASTREG - CS42XX8_FIRSTREG + 1)
#define CS42XX8_I2C_INCR			0x80

/* Chip I.D. and Revision Register (Address 01h) */
#define CS42XX8_CHIPID_CHIP_ID_MASK		0xF0
#define CS42XX8_CHIPID_REV_ID_MASK		0x0F

/* Power Control (Address 02h) */
#define CS42XX8_PWRCTL_PDN_ADC3_SHIFT		7
#define CS42XX8_PWRCTL_PDN_ADC3_MASK		(1 << CS42XX8_PWRCTL_PDN_ADC3_SHIFT)
#define CS42XX8_PWRCTL_PDN_ADC3			(1 << CS42XX8_PWRCTL_PDN_ADC3_SHIFT)
#define CS42XX8_PWRCTL_PDN_ADC2_SHIFT		6
#define CS42XX8_PWRCTL_PDN_ADC2_MASK		(1 << CS42XX8_PWRCTL_PDN_ADC2_SHIFT)
#define CS42XX8_PWRCTL_PDN_ADC2			(1 << CS42XX8_PWRCTL_PDN_ADC2_SHIFT)
#define CS42XX8_PWRCTL_PDN_ADC1_SHIFT		5
#define CS42XX8_PWRCTL_PDN_ADC1_MASK		(1 << CS42XX8_PWRCTL_PDN_ADC1_SHIFT)
#define CS42XX8_PWRCTL_PDN_ADC1			(1 << CS42XX8_PWRCTL_PDN_ADC1_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC4_SHIFT		4
#define CS42XX8_PWRCTL_PDN_DAC4_MASK		(1 << CS42XX8_PWRCTL_PDN_DAC4_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC4			(1 << CS42XX8_PWRCTL_PDN_DAC4_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC3_SHIFT		3
#define CS42XX8_PWRCTL_PDN_DAC3_MASK		(1 << CS42XX8_PWRCTL_PDN_DAC3_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC3			(1 << CS42XX8_PWRCTL_PDN_DAC3_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC2_SHIFT		2
#define CS42XX8_PWRCTL_PDN_DAC2_MASK		(1 << CS42XX8_PWRCTL_PDN_DAC2_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC2			(1 << CS42XX8_PWRCTL_PDN_DAC2_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC1_SHIFT		1
#define CS42XX8_PWRCTL_PDN_DAC1_MASK		(1 << CS42XX8_PWRCTL_PDN_DAC1_SHIFT)
#define CS42XX8_PWRCTL_PDN_DAC1			(1 << CS42XX8_PWRCTL_PDN_DAC1_SHIFT)
#define CS42XX8_PWRCTL_PDN_SHIFT		0
#define CS42XX8_PWRCTL_PDN_MASK			(1 << CS42XX8_PWRCTL_PDN_SHIFT)
#define CS42XX8_PWRCTL_PDN			(1 << CS42XX8_PWRCTL_PDN_SHIFT)

/* Functional Mode (Address 03h) */
#define CS42XX8_FUNCMOD_DAC_FM_SHIFT		6
#define CS42XX8_FUNCMOD_DAC_FM_WIDTH		2
#define CS42XX8_FUNCMOD_DAC_FM_MASK		(((1 << CS42XX8_FUNCMOD_DAC_FM_WIDTH) - 1) << CS42XX8_FUNCMOD_DAC_FM_SHIFT)
#define CS42XX8_FUNCMOD_DAC_FM(v)		((v) << CS42XX8_FUNCMOD_DAC_FM_SHIFT)
#define CS42XX8_FUNCMOD_ADC_FM_SHIFT		4
#define CS42XX8_FUNCMOD_ADC_FM_WIDTH		2
#define CS42XX8_FUNCMOD_ADC_FM_MASK		(((1 << CS42XX8_FUNCMOD_ADC_FM_WIDTH) - 1) << CS42XX8_FUNCMOD_ADC_FM_SHIFT)
#define CS42XX8_FUNCMOD_ADC_FM(v)		((v) << CS42XX8_FUNCMOD_ADC_FM_SHIFT)
#define CS42XX8_FUNCMOD_xC_FM_MASK(x)		((x) ? CS42XX8_FUNCMOD_DAC_FM_MASK : CS42XX8_FUNCMOD_ADC_FM_MASK)
#define CS42XX8_FUNCMOD_xC_FM(x, v)		((x) ? CS42XX8_FUNCMOD_DAC_FM(v) : CS42XX8_FUNCMOD_ADC_FM(v))
#define CS42XX8_FUNCMOD_MFREQ_SHIFT		1
#define CS42XX8_FUNCMOD_MFREQ_WIDTH		3
#define CS42XX8_FUNCMOD_MFREQ_MASK		(((1 << CS42XX8_FUNCMOD_MFREQ_WIDTH) - 1) << CS42XX8_FUNCMOD_MFREQ_SHIFT)
#define CS42XX8_FUNCMOD_MFREQ_256(s)		((0 << CS42XX8_FUNCMOD_MFREQ_SHIFT) >> (s >> 1))
#define CS42XX8_FUNCMOD_MFREQ_384(s)		((1 << CS42XX8_FUNCMOD_MFREQ_SHIFT) >> (s >> 1))
#define CS42XX8_FUNCMOD_MFREQ_512(s)		((2 << CS42XX8_FUNCMOD_MFREQ_SHIFT) >> (s >> 1))
#define CS42XX8_FUNCMOD_MFREQ_768(s)		((3 << CS42XX8_FUNCMOD_MFREQ_SHIFT) >> (s >> 1))
#define CS42XX8_FUNCMOD_MFREQ_1024(s)		((4 << CS42XX8_FUNCMOD_MFREQ_SHIFT) >> (s >> 1))

#define CS42XX8_FM_SINGLE			0
#define CS42XX8_FM_DOUBLE			1
#define CS42XX8_FM_QUAD				2
#define CS42XX8_FM_AUTO				3

/* Interface Formats (Address 04h) */
#define CS42XX8_INTF_FREEZE_SHIFT		7
#define CS42XX8_INTF_FREEZE_MASK		(1 << CS42XX8_INTF_FREEZE_SHIFT)
#define CS42XX8_INTF_FREEZE			(1 << CS42XX8_INTF_FREEZE_SHIFT)
#define CS42XX8_INTF_AUX_DIF_SHIFT		6
#define CS42XX8_INTF_AUX_DIF_MASK		(1 << CS42XX8_INTF_AUX_DIF_SHIFT)
#define CS42XX8_INTF_AUX_DIF			(1 << CS42XX8_INTF_AUX_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_SHIFT		3
#define CS42XX8_INTF_DAC_DIF_WIDTH		3
#define CS42XX8_INTF_DAC_DIF_MASK		(((1 << CS42XX8_INTF_DAC_DIF_WIDTH) - 1) << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_LEFTJ		(0 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_I2S		(1 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_RIGHTJ		(2 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_RIGHTJ_16		(3 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_ONELINE_20		(4 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_ONELINE_24		(5 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_DAC_DIF_TDM		(6 << CS42XX8_INTF_DAC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_SHIFT		0
#define CS42XX8_INTF_ADC_DIF_WIDTH		3
#define CS42XX8_INTF_ADC_DIF_MASK		(((1 << CS42XX8_INTF_ADC_DIF_WIDTH) - 1) << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_LEFTJ		(0 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_I2S		(1 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_RIGHTJ		(2 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_RIGHTJ_16		(3 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_ONELINE_20		(4 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_ONELINE_24		(5 << CS42XX8_INTF_ADC_DIF_SHIFT)
#define CS42XX8_INTF_ADC_DIF_TDM		(6 << CS42XX8_INTF_ADC_DIF_SHIFT)

/* ADC Control & DAC De-Emphasis (Address 05h) */
#define CS42XX8_ADCCTL_ADC_HPF_FREEZE_SHIFT	7
#define CS42XX8_ADCCTL_ADC_HPF_FREEZE_MASK	(1 << CS42XX8_ADCCTL_ADC_HPF_FREEZE_SHIFT)
#define CS42XX8_ADCCTL_ADC_HPF_FREEZE		(1 << CS42XX8_ADCCTL_ADC_HPF_FREEZE_SHIFT)
#define CS42XX8_ADCCTL_DAC_DEM_SHIFT		5
#define CS42XX8_ADCCTL_DAC_DEM_MASK		(1 << CS42XX8_ADCCTL_DAC_DEM_SHIFT)
#define CS42XX8_ADCCTL_DAC_DEM			(1 << CS42XX8_ADCCTL_DAC_DEM_SHIFT)
#define CS42XX8_ADCCTL_ADC1_SINGLE_SHIFT	4
#define CS42XX8_ADCCTL_ADC1_SINGLE_MASK		(1 << CS42XX8_ADCCTL_ADC1_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_ADC1_SINGLE		(1 << CS42XX8_ADCCTL_ADC1_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_ADC2_SINGLE_SHIFT	3
#define CS42XX8_ADCCTL_ADC2_SINGLE_MASK		(1 << CS42XX8_ADCCTL_ADC2_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_ADC2_SINGLE		(1 << CS42XX8_ADCCTL_ADC2_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_ADC3_SINGLE_SHIFT	2
#define CS42XX8_ADCCTL_ADC3_SINGLE_MASK		(1 << CS42XX8_ADCCTL_ADC3_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_ADC3_SINGLE		(1 << CS42XX8_ADCCTL_ADC3_SINGLE_SHIFT)
#define CS42XX8_ADCCTL_AIN5_MUX_SHIFT		1
#define CS42XX8_ADCCTL_AIN5_MUX_MASK		(1 << CS42XX8_ADCCTL_AIN5_MUX_SHIFT)
#define CS42XX8_ADCCTL_AIN5_MUX			(1 << CS42XX8_ADCCTL_AIN5_MUX_SHIFT)
#define CS42XX8_ADCCTL_AIN6_MUX_SHIFT		0
#define CS42XX8_ADCCTL_AIN6_MUX_MASK		(1 << CS42XX8_ADCCTL_AIN6_MUX_SHIFT)
#define CS42XX8_ADCCTL_AIN6_MUX			(1 << CS42XX8_ADCCTL_AIN6_MUX_SHIFT)

/* Transition Control (Address 06h) */
#define CS42XX8_TXCTL_DAC_SNGVOL_SHIFT		7
#define CS42XX8_TXCTL_DAC_SNGVOL_MASK		(1 << CS42XX8_TXCTL_DAC_SNGVOL_SHIFT)
#define CS42XX8_TXCTL_DAC_SNGVOL		(1 << CS42XX8_TXCTL_DAC_SNGVOL_SHIFT)
#define CS42XX8_TXCTL_DAC_SZC_SHIFT		5
#define CS42XX8_TXCTL_DAC_SZC_WIDTH		2
#define CS42XX8_TXCTL_DAC_SZC_MASK		(((1 << CS42XX8_TXCTL_DAC_SZC_WIDTH) - 1) << CS42XX8_TXCTL_DAC_SZC_SHIFT)
#define CS42XX8_TXCTL_DAC_SZC_IC		(0 << CS42XX8_TXCTL_DAC_SZC_SHIFT)
#define CS42XX8_TXCTL_DAC_SZC_ZC		(1 << CS42XX8_TXCTL_DAC_SZC_SHIFT)
#define CS42XX8_TXCTL_DAC_SZC_SR		(2 << CS42XX8_TXCTL_DAC_SZC_SHIFT)
#define CS42XX8_TXCTL_DAC_SZC_SRZC		(3 << CS42XX8_TXCTL_DAC_SZC_SHIFT)
#define CS42XX8_TXCTL_AMUTE_SHIFT		4
#define CS42XX8_TXCTL_AMUTE_MASK		(1 << CS42XX8_TXCTL_AMUTE_SHIFT)
#define CS42XX8_TXCTL_AMUTE			(1 << CS42XX8_TXCTL_AMUTE_SHIFT)
#define CS42XX8_TXCTL_MUTE_ADC_SP_SHIFT		3
#define CS42XX8_TXCTL_MUTE_ADC_SP_MASK		(1 << CS42XX8_TXCTL_MUTE_ADC_SP_SHIFT)
#define CS42XX8_TXCTL_MUTE_ADC_SP		(1 << CS42XX8_TXCTL_MUTE_ADC_SP_SHIFT)
#define CS42XX8_TXCTL_ADC_SNGVOL_SHIFT		2
#define CS42XX8_TXCTL_ADC_SNGVOL_MASK		(1 << CS42XX8_TXCTL_ADC_SNGVOL_SHIFT)
#define CS42XX8_TXCTL_ADC_SNGVOL		(1 << CS42XX8_TXCTL_ADC_SNGVOL_SHIFT)
#define CS42XX8_TXCTL_ADC_SZC_SHIFT		0
#define CS42XX8_TXCTL_ADC_SZC_MASK		(((1 << CS42XX8_TXCTL_ADC_SZC_WIDTH) - 1) << CS42XX8_TXCTL_ADC_SZC_SHIFT)
#define CS42XX8_TXCTL_ADC_SZC_IC		(0 << CS42XX8_TXCTL_ADC_SZC_SHIFT)
#define CS42XX8_TXCTL_ADC_SZC_ZC		(1 << CS42XX8_TXCTL_ADC_SZC_SHIFT)
#define CS42XX8_TXCTL_ADC_SZC_SR		(2 << CS42XX8_TXCTL_ADC_SZC_SHIFT)
#define CS42XX8_TXCTL_ADC_SZC_SRZC		(3 << CS42XX8_TXCTL_ADC_SZC_SHIFT)

/* DAC Channel Mute (Address 07h) */
#define CS42XX8_DACMUTE_AOUT(n)			(0x1 << n)
#define CS42XX8_DACMUTE_ALL			0xff

/* Status Control (Address 18h)*/
#define CS42XX8_STATUSCTL_INI_SHIFT		2
#define CS42XX8_STATUSCTL_INI_WIDTH		2
#define CS42XX8_STATUSCTL_INI_MASK		(((1 << CS42XX8_STATUSCTL_INI_WIDTH) - 1) << CS42XX8_STATUSCTL_INI_SHIFT)
#define CS42XX8_STATUSCTL_INT_ACTIVE_HIGH	(0 << CS42XX8_STATUSCTL_INI_SHIFT)
#define CS42XX8_STATUSCTL_INT_ACTIVE_LOW	(1 << CS42XX8_STATUSCTL_INI_SHIFT)
#define CS42XX8_STATUSCTL_INT_OPEN_DRAIN	(2 << CS42XX8_STATUSCTL_INI_SHIFT)

/* Status (Address 19h)*/
#define CS42XX8_STATUS_DAC_CLK_ERR_SHIFT	4
#define CS42XX8_STATUS_DAC_CLK_ERR_MASK		(1 << CS42XX8_STATUS_DAC_CLK_ERR_SHIFT)
#define CS42XX8_STATUS_ADC_CLK_ERR_SHIFT	3
#define CS42XX8_STATUS_ADC_CLK_ERR_MASK		(1 << CS42XX8_STATUS_ADC_CLK_ERR_SHIFT)
#define CS42XX8_STATUS_ADC3_OVFL_SHIFT		2
#define CS42XX8_STATUS_ADC3_OVFL_MASK		(1 << CS42XX8_STATUS_ADC3_OVFL_SHIFT)
#define CS42XX8_STATUS_ADC2_OVFL_SHIFT		1
#define CS42XX8_STATUS_ADC2_OVFL_MASK		(1 << CS42XX8_STATUS_ADC2_OVFL_SHIFT)
#define CS42XX8_STATUS_ADC1_OVFL_SHIFT		0
#define CS42XX8_STATUS_ADC1_OVFL_MASK		(1 << CS42XX8_STATUS_ADC1_OVFL_SHIFT)

/* Status Mask (Address 1Ah) */
#define CS42XX8_STATUS_DAC_CLK_ERR_M_SHIFT	4
#define CS42XX8_STATUS_DAC_CLK_ERR_M_MASK	(1 << CS42XX8_STATUS_DAC_CLK_ERR_M_SHIFT)
#define CS42XX8_STATUS_ADC_CLK_ERR_M_SHIFT	3
#define CS42XX8_STATUS_ADC_CLK_ERR_M_MASK	(1 << CS42XX8_STATUS_ADC_CLK_ERR_M_SHIFT)
#define CS42XX8_STATUS_ADC3_OVFL_M_SHIFT	2
#define CS42XX8_STATUS_ADC3_OVFL_M_MASK		(1 << CS42XX8_STATUS_ADC3_OVFL_M_SHIFT)
#define CS42XX8_STATUS_ADC2_OVFL_M_SHIFT	1
#define CS42XX8_STATUS_ADC2_OVFL_M_MASK		(1 << CS42XX8_STATUS_ADC2_OVFL_M_SHIFT)
#define CS42XX8_STATUS_ADC1_OVFL_M_SHIFT	0
#define CS42XX8_STATUS_ADC1_OVFL_M_MASK		(1 << CS42XX8_STATUS_ADC1_OVFL_M_SHIFT)

/* MUTEC Pin Control (Address 1Bh) */
#define CS42XX8_MUTEC_MCPOLARITY_SHIFT		1
#define CS42XX8_MUTEC_MCPOLARITY_MASK		(1 << CS42XX8_MUTEC_MCPOLARITY_SHIFT)
#define CS42XX8_MUTEC_MCPOLARITY_ACTIVE_LOW	(0 << CS42XX8_MUTEC_MCPOLARITY_SHIFT)
#define CS42XX8_MUTEC_MCPOLARITY_ACTIVE_HIGH	(1 << CS42XX8_MUTEC_MCPOLARITY_SHIFT)
#define CS42XX8_MUTEC_MUTEC_ACTIVE_SHIFT	0
#define CS42XX8_MUTEC_MUTEC_ACTIVE_MASK		(1 << CS42XX8_MUTEC_MUTEC_ACTIVE_SHIFT)
#define CS42XX8_MUTEC_MUTEC_ACTIVE		(1 << CS42XX8_MUTEC_MUTEC_ACTIVE_SHIFT)
#endif /* _CS42XX8_H */