/*
 * @file     2pad_hw.h
*
* @version  1.0.0.0
*
* @date     January-2019
*
* @brief    Hardware configuration file for 2pad EVB demo
*
 */

#ifndef CFG_2PAD_EVB_2PAD_HW_H_
#define CFG_2PAD_EVB_2PAD_HW_H_

/*******************************************************************************
* Includes
*******************************************************************************/
#include "S32K144.h"
#include "ts_cfg_general.h"

#if (REFERENCE_DESIGN_BOARD == S32K144_2PAD_EVB)
/*******************************************************************************
* Do not modify!: Define number of electrodes
******************************************************************************/
// Number of touch button electrodes from 1 to 2
#define NUMBER_OF_TOUCH_ELECTRODES   2
// YES (WAKE_ELEC_YES) or NO (WAKE_ELEC_NO) optional wake-up electrode
// There is no EGS available on EVB
#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_NO

/*******************************************************************************
* Do not modify !
******************************************************************************/
#if (OPTIONAL_WAKE_UP_ELECTRODE == WAKE_ELEC_YES)
	// Add an extra electrode for wake-up function
	#define NUMBER_OF_ELECTRODES   (NUMBER_OF_TOUCH_ELECTRODES + 1)
	// Wake-up electrode number assignment
	#define WAKE_UP_ELECTRODE      (NUMBER_OF_ELECTRODES - 1)
#endif

#if (OPTIONAL_WAKE_UP_ELECTRODE == WAKE_ELEC_NO)
	// Application uses touch electrodes only
	#define NUMBER_OF_ELECTRODES   NUMBER_OF_TOUCH_ELECTRODES
#endif

/*******************************************************************************
* Modify: Electrode 0 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 0)
	#define ELEC0
	#define ELEC0_ADC             ADC0      // Modify: ADC module
	#define ELEC0_ADC_CHANNEL     8         // Modify: Cext ADC channel
	#define ELEC0_PORT            PORTC     // Modify: Electrode and Cext PORT
	#define ELEC0_GPIO            PTC       // Modify: Electrode and Cext GPIO
	#define ELEC0_ELEC_GPIO_PIN   2         // Modify: Electrode GPIO pin
	#define ELEC0_CEXT_GPIO_PIN   0         // Modify: Cext GPIO pin
	#define ELEC0_PORT_MASK       (1 << ELEC0_ELEC_GPIO_PIN) | (1 << ELEC0_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 1 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 1)
	#define ELEC1
	#define ELEC1_ADC             ADC0
	#define ELEC1_ADC_CHANNEL     11
	#define ELEC1_PORT            PORTC
	#define ELEC1_GPIO            PTC
	#define ELEC1_ELEC_GPIO_PIN   1
	#define ELEC1_CEXT_GPIO_PIN   3
	#define ELEC1_PORT_MASK       (1 << ELEC1_ELEC_GPIO_PIN) | (1 << ELEC1_CEXT_GPIO_PIN)
#endif

#endif

#endif /* CFG_2PAD_EVB_2PAD_HW_H_ */
