/*
 * @file     7pad_hw.h
*
* @version  1.0.0.0
*
* @date     January-2019
*
* @brief    Hardware configuration file for 7pad keypad reference design
*
 */

#ifndef CFG_7PAD_7PAD_HW_H_
#define CFG_7PAD_7PAD_HW_H_

/*******************************************************************************
* Includes
*******************************************************************************/
#include "S32K144.h"
#include "ts_cfg_general.h"

#if (REFERENCE_DESIGN_BOARD == S32K144_7PAD_KEYPAD)
/*******************************************************************************
* Modify: Define number of electrodes
******************************************************************************/
// Number of touch button electrodes from 1 to 7
#define NUMBER_OF_TOUCH_ELECTRODES   7
// YES (WAKE_ELEC_YES) or NO (WAKE_ELEC_NO) optional wake-up electrode
// If YES, an additional electrode defined, assigned the highest number
#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_YES

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
	#define ELEC0_ADC             ADC0         // Modify: ADC module
	#define ELEC0_ADC_CHANNEL     15           // Modify: Cext ADC channel
	#define ELEC0_PORT            PORTC        // Modify: Electrode and Cext PORT
	#define ELEC0_GPIO            PTC          // Modify: Electrode and Cext GPIO
	#define ELEC0_ELEC_GPIO_PIN   16           // Modify: Electrode GPIO pin
	#define ELEC0_CEXT_GPIO_PIN   17		   // Modify: Cext GPIO pin
	#define ELEC0_PORT_MASK       (1 << ELEC0_ELEC_GPIO_PIN) | (1 << ELEC0_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 1 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 1)
	#define ELEC1
	#define ELEC1_ADC             ADC1
	#define ELEC1_ADC_CHANNEL     1
	#define ELEC1_PORT            PORTA
	#define ELEC1_GPIO            PTA
	#define ELEC1_ELEC_GPIO_PIN   2
	#define ELEC1_CEXT_GPIO_PIN   3
	#define ELEC1_PORT_MASK       (1 << ELEC1_ELEC_GPIO_PIN) | (1 << ELEC1_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 2 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 2)
	#define ELEC2
	#define ELEC2_ADC             ADC0
	#define ELEC2_ADC_CHANNEL     3
	#define ELEC2_PORT            PORTA
	#define ELEC2_GPIO            PTA
	#define ELEC2_ELEC_GPIO_PIN   6
	#define ELEC2_CEXT_GPIO_PIN   7
	#define ELEC2_PORT_MASK       (1 << ELEC2_ELEC_GPIO_PIN) | (1 << ELEC2_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 3 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 3)
	#define ELEC3
	#define ELEC3_ADC             ADC1
	#define ELEC3_ADC_CHANNEL     13
	#define ELEC3_PORT            PORTA
	#define ELEC3_GPIO            PTA
	#define ELEC3_ELEC_GPIO_PIN   15
	#define ELEC3_CEXT_GPIO_PIN   16
	#define ELEC3_PORT_MASK       (1 << ELEC3_ELEC_GPIO_PIN) | (1 << ELEC3_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 4 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 4)
	#define ELEC4
	#define ELEC4_ADC             ADC0
	#define ELEC4_ADC_CHANNEL     7
	#define ELEC4_PORT            PORTB
	#define ELEC4_GPIO            PTB
	#define ELEC4_ELEC_GPIO_PIN   2
	#define ELEC4_CEXT_GPIO_PIN   3
	#define ELEC4_PORT_MASK       (1 << ELEC4_ELEC_GPIO_PIN) | (1 << ELEC4_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 5 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 5)
	#define ELEC5
	#define ELEC5_ADC             ADC0
	#define ELEC5_ADC_CHANNEL     5
	#define ELEC5_PORT            PORTB
	#define ELEC5_GPIO            PTB
	#define ELEC5_ELEC_GPIO_PIN   0
	#define ELEC5_CEXT_GPIO_PIN   1
	#define ELEC5_PORT_MASK       (1 << ELEC5_ELEC_GPIO_PIN) | (1 << ELEC5_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 6 defines
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 6)
	#define ELEC6
	#define ELEC6_ADC             ADC0
	#define ELEC6_ADC_CHANNEL     1
	#define ELEC6_PORT            PORTA
	#define ELEC6_GPIO            PTA
	#define ELEC6_ELEC_GPIO_PIN   0
	#define ELEC6_CEXT_GPIO_PIN   1
	#define ELEC6_PORT_MASK       (1 << ELEC6_ELEC_GPIO_PIN) | (1 << ELEC6_CEXT_GPIO_PIN)
#endif

/*******************************************************************************
* Modify: Electrode 7 defines - wake up EGS
******************************************************************************/
#if (NUMBER_OF_ELECTRODES > 7)
	#define ELEC7
	#define ELEC7_ADC             ADC1
	#define ELEC7_ADC_CHANNEL     8
	#define ELEC7_PORT            PORTB
	#define ELEC7_GPIO            PTB
	#define ELEC7_ELEC_GPIO_PIN   12
	#define ELEC7_CEXT_GPIO_PIN   13
	#define ELEC7_PORT_MASK       (1 << ELEC7_ELEC_GPIO_PIN) | (1 << ELEC7_CEXT_GPIO_PIN)
#endif
#endif

#endif /* CFG_7PAD_7PAD_HW_H_ */
