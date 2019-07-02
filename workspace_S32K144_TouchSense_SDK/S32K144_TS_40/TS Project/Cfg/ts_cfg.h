/*
 * @file     ts_cfg.h
*
* @version  1.0.0.0
*
* @date     January-2019
*
* @brief    Touch sense configuration file which gathers and includes all other cfg files into TS application source codes
*
 */

#ifndef CFG_TS_CFG_H_
#define CFG_TS_CFG_H_
/*******************************************************************************
* Includes
*******************************************************************************/
#include "S32K144.h"
#include "ts_cfg_general.h"

#if (REFERENCE_DESIGN_BOARD == S32K144_2PAD_EVB)
#include "2pad_hw.h"
#include "2pad_app.h"
#elif (REFERENCE_DESIGN_BOARD == S32K144_6PAD_KEYPAD_SLIDER)
#include "6pad_hw.h"
#include "6pad_app.h"
#elif (REFERENCE_DESIGN_BOARD == S32K144_7PAD_KEYPAD)
#include "7pad_hw.h"
#include "7pad_app.h"
#else
#error Please select valid reference design board in ts_cfg_general.h
#endif

/*******************************************************************************
* Modify: Low power mode enable
*         If low power mode is enabled (LPM_ENABLE), the application debug and
*         FreeMASTER data visualization are disabled.
*         If low power mode is disabled (LPM_DISABLE), the application debug and
*         FreeMASTER data visualization are enabled.
******************************************************************************/
#define LOW_POWER_MODE   LPM_DISABLE

/*******************************************************************************
* Modify: Assembly optimization to avoid dependency on -O3 compilation optimization (1-ON, 0-OFF)
* 		  Modify only if lower than -O3 optimization needed
******************************************************************************/
#define TS_ASM_OPTIMIZE     0

/*******************************************************************************
* Modify: If needed, configure debug pins. Uncomment required option.
******************************************************************************/
// Debug electrode sensing cycle
//#define DEBUG_ELECTRODE_SENSE
// Debug application algorithm
//#define DEBUG_ALGORITHM

// Defined?
#ifdef DEBUG_ELECTRODE_SENSE
	// Assign PORT
	#define DES_PORT  PORTE
	// Assign GPIO
	#define DES_GPIO  PTE
	// Assign pin
	#define DES_PIN   10

#endif

// Defined?
#ifdef DEBUG_ALGORITHM
	// Assign PORT
	#define DA_PORT  PORTE
	// Assign GPIO
	#define DA_GPIO  PTE
	// Assign pin
	#define DA_PIN   11
#endif

#endif /* CFG_TS_CFG_H_ */
