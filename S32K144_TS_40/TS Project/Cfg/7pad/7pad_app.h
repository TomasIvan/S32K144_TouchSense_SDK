/*
  * @file     7pad_app.h
*
* @version  1.0.0.0
*
* @date     January-2019
*
* @brief    Application configuration file for 7pad keypad reference design
*
 */

#ifndef CFG_7PAD_7PAD_APP_H_
#define CFG_7PAD_7PAD_APP_H_

/*******************************************************************************
* Includes
*******************************************************************************/
#include "ts_cfg_general.h"
#include "7pad_hw.h"

#if (REFERENCE_DESIGN_BOARD == S32K144_7PAD_KEYPAD)
/*******************************************************************************
* Modify: Number of following electrode pre-cycles per single sample
******************************************************************************/
// Value from 1 to 2
#define NUMBER_OF_ELECTRODE_SENSING_PRECYCLES_PER_SAMPLE    1

/*******************************************************************************
* Modify: Number of following electrode cycles per single sample
******************************************************************************/
// IDLE MODE, when EGS/touch buttons are not touched
// Value from 1 to 4  to achieve MCU 70uA max average current consumption
#define NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_IDLE   4

// ACTIVE MODE, when EGS/touch buttons are touched
// Define value as the multiply of NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_IDLE
// Value must be a power of two
// The NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_MULTIPLY * NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_IDLE
// Result of multiplication must be below or equal 128
#define NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_MULTIPLY  4

/*******************************************************************************
* Do not modify!
******************************************************************************/
// Calculate number of samples, when module in active mode, max value 128
#define NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_ACTIVE  (NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_MULTIPLY * NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_IDLE)

/*******************************************************************************
* Do not modify!
******************************************************************************/
// Required for IIR filter correct operation.
// SHIFT_NUMBER = (2^31 / (2^12 * NUMBER_OF_ELECTRODE_SENSING_CYCLES_PER_SAMPLE_IDLE))
// Go to: https://www.wolframalpha.com/
// Calculate: IIR_FILTER_VALUE_SHIFT = round down [log2(SHIFT_NUMBER)]
// Calculated for max 128 samples
#define IIR_FILTER_VALUE_SHIFT  12

#if (NUMBER_OF_ELECTRODES > 0)
	/*******************************************************************************
	* Modify: Jittering ON/OFF and jittering bits
	******************************************************************************/
	// YES (JITTERING_ON) or NO (JITTERING_OFF) optional jittering sample rate control
	#define JITTERING JITTERING_OFF

		#if JITTERING
			// Modify: Define jittering option: 1 - jitter at the beginning of IRQ handler, 2 - jitter in between each following ADC sample scan
			#define JITTERING_OPTION 2

			// Modify: Value of 2 to 8
			#define NUMBER_OF_JITTERING_BITS 3

			// Do not modify!: the jittering_mask_macro
			#define JITTERING_MASK ((1 << NUMBER_OF_JITTERING_BITS)-1)
		#endif

	/*******************************************************************************
	* Modify: Frequency hopping ON/OFF
	******************************************************************************/
	// YES (FREQUENCY_HOPPING_ON) or NO (FREQUENCY_HOPPING_OFF) optional frequency hopping
	#define FREQUENCY_HOPPING FREQUENCY_HOPPING_OFF

		#if FREQUENCY_HOPPING
			// Do not modify!: 1 core scanning period/frequency (30ms) + 1 extra scanning period/frequency
			// SW written for maximum of 2 scanning periods/frequencies only
			#define NUMBER_OF_HOPPING_FREQUENCIES 2

			// Modify: Extra scanning period/frequency 330us after the core period
			// (LPIT fed by 48 MHz clock => Value 48 000 equals delay 1 ms)
			#define ELECTRODES_SENSE_PERIOD_FH   15840

			// Modify: Frequency hopping filter factor addition for DCTracker
			#define FH_DCTRACKER_FILTER_FACTOR 1
		#else
			// Do not modify!: 1 core scanning period/frequency (30ms)
			#define NUMBER_OF_HOPPING_FREQUENCIES 1

			// Do not Modify!: Frequency hopping disabled - no filter factor addition for DCTracker
			#define FH_DCTRACKER_FILTER_FACTOR 0
		#endif

	/*******************************************************************************
	* Modify: Decimation filter ON/OFF
	******************************************************************************/
	// YES (DECIMATION_FILTER_ON) or NO (DECIMATION_FILTER_OFF) optional decimation filter
	#define DECIMATION_FILTER DECIMATION_FILTER_OFF

		#if DECIMATION_FILTER
			// Modify: LPTMR new wake-up period - 3 ms
			// Value between 3 and 30
			#define ELECTRODES_SENSE_PERIOD_DF 3

			// Modify: Decimation filter filter factor addition for DCTracker
			#define DF_DCTRACKER_FILTER_FACTOR (3 - FH_DCTRACKER_FILTER_FACTOR)

			#if (TS_RAW_DATA_CALCULATION == OVERSAMPLING)
				// Modify: Decimation filter step
				#define DECIMATION_STEP 10
			#elif (TS_RAW_DATA_CALCULATION == AVERAGING)
				// Modify: Decimation filter step
				#define DECIMATION_STEP 1
			#else
				#error Please select valid demo hardware in ts_cfg_general.h
			#endif
		#else
			// Do not Modify!: Decimation filter disabled - no filter factor addition for DCTracker
			#define DF_DCTRACKER_FILTER_FACTOR 0
		#endif
#else
	// Do not Modify!
	#define FH_DCTRACKER_FILTER_FACTOR 0
	#define DF_DCTRACKER_FILTER_FACTOR 0
	#define NUMBER_OF_HOPPING_FREQUENCIES 1

#endif

/*******************************************************************************
* Modify: Define application mode, select only one option designed for 7 electrode keyboard:
*         MODE_REACTION_TIME_90MS and MODE_CUSTOM
*
* Note: Response time stands for period of electrodes sensing (scan period)
*       Reaction time stands for period between electrode touch and application report "electrode touched"
******************************************************************************/
// If "#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_YES": MCU response time 30ms, MCU reaction time 90ms, MCU average current consumption 70uA
// If "#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_NO": MCU response time 30ms, MCU reaction time 90ms, MCU average current consumption 130uA
#define MODE_REACTION_TIME_90MS

// Custom settings:
// Preset to same operation as in case of MODE_REACTION_TIME_90MS
// If "#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_YES": MCU response time 30ms, MCU reaction time 90ms, MCU average current consumption 70uA
// If "#define OPTIONAL_WAKE_UP_ELECTRODE   WAKE_ELEC_NO": MCU response time 30ms, MCU reaction time 90ms, MCU average current consumption 130uA
//#define MODE_CUSTOM

/*******************************************************************************
* Modify: Define electrodes sensing (scanning) cycle in milliseconds [ms].
*         Value from 1 to 65535.
******************************************************************************/
#if (OPTIONAL_WAKE_UP_ELECTRODE == WAKE_ELEC_YES)
	#ifdef MODE_REACTION_TIME_90MS
		#define ELECTRODES_SENSE_PERIOD   30
	#endif
	#ifdef MODE_CUSTOM
		#define ELECTRODES_SENSE_PERIOD   30
	#endif
#else
	#ifdef MODE_REACTION_TIME_90MS
		#define ELECTRODES_SENSE_PERIOD   30
	#endif
	#ifdef MODE_CUSTOM
		#define ELECTRODES_SENSE_PERIOD   30
	#endif
#endif

/*******************************************************************************
* Modify: Define filter parameters.
*         Coefficients B0, B1 and A0 are dependent on filter cutoff frequency [Hz]
*         and electrode sensing period, see ELECTRODES_SENSE_PERIOD above.
*         Coefficient for filter are calculated with:
*         http://engineerjs.com/?sidebar=docs/iir.html
*
******************************************************************************/
#if (OPTIONAL_WAKE_UP_ELECTRODE == WAKE_ELEC_YES)
	#ifdef MODE_REACTION_TIME_90MS
		#if DECIMATION_FILTER
			// Define electrodes IIR filter parameters
			// ELECTRODES_SENSE_PERIOD   30
			#define FILTER_1                   0
			// Cutoff frequency in Hertz [Hz]
			#define FILTER_1_CUTOFF_FREQ_HZ    1
			// Coefficient B0
			#define FILTER_1_COEF_B0          0.059190703818405
			// Coefficient B1
			#define FILTER_1_COEF_B1          0.059190703818405
			// Coefficient A0
			#define FILTER_1_COEF_A0         -0.881618592363189

			// Define EGS IIR filter parameters
			#define FILTER_2                   1
			#define FILTER_2_CUTOFF_FREQ_HZ    1
			#define FILTER_2_COEF_B0           0.086364027013762
			#define FILTER_2_COEF_B1           0.086364027013762
			#define FILTER_2_COEF_A0           -0.827271945972476
		#else
			// Define electrodes IIR filter parameters
			// ELECTRODES_SENSE_PERIOD   30
			#define FILTER_1                   0
			// Cutoff frequency in Hertz [Hz]
			#define FILTER_1_CUTOFF_FREQ_HZ    1
			// Coefficient B0
			#define FILTER_1_COEF_B0           0.086364027013762
			// Coefficient B1
			#define FILTER_1_COEF_B1           0.086364027013762
			// Coefficient A0
			#define FILTER_1_COEF_A0           -0.827271945972476

			// Define EGS IIR filter parameters
			#define FILTER_2                   1
			#define FILTER_2_CUTOFF_FREQ_HZ    1
			#define FILTER_2_COEF_B0           0.086364027013762
			#define FILTER_2_COEF_B1           0.086364027013762
			#define FILTER_2_COEF_A0           -0.827271945972476
		#endif
	#endif
		#ifdef MODE_CUSTOM
			// Define electrodes IIR filter parameters
			// ELECTRODES_SENSE_PERIOD   30
			#define FILTER_1                   0
			// Cutoff frequency in Hertz [Hz]
			#define FILTER_1_CUTOFF_FREQ_HZ    1
			// Coefficient B0
			#define FILTER_1_COEF_B0           0.086364027013762
			// Coefficient B1
			#define FILTER_1_COEF_B1           0.086364027013762
			// Coefficient A0
			#define FILTER_1_COEF_A0           -0.827271945972476

			// Define EGS IIR filter parameters
			#define FILTER_2                   1
			#define FILTER_2_CUTOFF_FREQ_HZ    1
			#define FILTER_2_COEF_B0           0.086364027013762
			#define FILTER_2_COEF_B1           0.086364027013762
			#define FILTER_2_COEF_A0           -0.827271945972476
		#endif

		// Number of used filters
		#define NUMBER_OF_FILTERS_USED     2

#else
		#ifdef MODE_REACTION_TIME_90MS
			#if DECIMATION_FILTER
				// Define electrodes IIR filter parameters
				// ELECTRODES_SENSE_PERIOD   30
				#define FILTER_1                   0
				// Cutoff frequency in Hertz [Hz]
				#define FILTER_1_CUTOFF_FREQ_HZ    1
				// Coefficient B0
				#define FILTER_1_COEF_B0          0.059190703818405
				// Coefficient B1
				#define FILTER_1_COEF_B1          0.059190703818405
				// Coefficient A0
				#define FILTER_1_COEF_A0         -0.881618592363189
			#else
				// Define electrodes IIR filter parameters
				// ELECTRODES_SENSE_PERIOD   30
				#define FILTER_1                   0
				// Cutoff frequency in Hertz [Hz]
				#define FILTER_1_CUTOFF_FREQ_HZ    1
				// Coefficient B0
				#define FILTER_1_COEF_B0           0.086364027013762
				// Coefficient B1
				#define FILTER_1_COEF_B1           0.086364027013762
				// Coefficient A0
				#define FILTER_1_COEF_A0           -0.827271945972476
			#endif
		#endif
		#ifdef MODE_CUSTOM
				// Define electrodes IIR filter parameters
				// ELECTRODES_SENSE_PERIOD   30
				#define FILTER_1                   0
				// Cutoff frequency in Hertz [Hz]
				#define FILTER_1_CUTOFF_FREQ_HZ    1
				// Coefficient B0
				#define FILTER_1_COEF_B0           0.086364027013762
				// Coefficient B1
				#define FILTER_1_COEF_B1           0.086364027013762
				// Coefficient A0
				#define FILTER_1_COEF_A0           -0.827271945972476
		#endif

		// Number of used filters
		#define NUMBER_OF_FILTERS_USED     1
#endif

/*******************************************************************************
* Modify: Electrode 0 to 6 common defines
******************************************************************************/
#if(TS_RAW_DATA_CALCULATION == AVERAGING)
	// DC tracker response, when in Idle mode
	// Value 5 equals 1s at 30ms sampling period
	#define ELEC_DCTRACKER_FILTER_FACTOR_IDLE     5
	// DC tracker response, when in Active mode
	// Value 5 equals 1s at 30ms sampling period
	#define ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE   (5 + DF_DCTRACKER_FILTER_FACTOR + FH_DCTRACKER_FILTER_FACTOR)
	// Electrode touch threshold relative to DC tracker value
	#define ELEC_TOUCH_THRESHOLD_DELTA       22
	// Electrode release threshold relative to DC tracker value
	#define ELEC_RELEASE_THRESHOLD_DELTA     20
#elif (TS_RAW_DATA_CALCULATION == OVERSAMPLING)
	#ifdef WAKE_UP_ELECTRODE
		// DC tracker response, when in Idle mode
		// Value 5 equals 1s at 30ms sampling period
		#define ELEC_DCTRACKER_FILTER_FACTOR_IDLE     1
		// DC tracker response, when in Active mode
		// Value 5 equals 1s at 30ms sampling period
		#define ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE   (3 + DF_DCTRACKER_FILTER_FACTOR + FH_DCTRACKER_FILTER_FACTOR)
	#else
		// DC tracker response, when in Idle mode
		// Value 5 equals 1s at 30ms sampling period
		#define ELEC_DCTRACKER_FILTER_FACTOR_IDLE     5
		// DC tracker response, when in Active mode
		// Value 5 equals 1s at 30ms sampling period
		#define ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE   (5 + DF_DCTRACKER_FILTER_FACTOR + FH_DCTRACKER_FILTER_FACTOR)
	#endif
	// Electrode touch threshold relative to DC tracker value
	#define ELEC_TOUCH_THRESHOLD_DELTA            200
	// Electrode release threshold relative to DC tracker value
	#define ELEC_RELEASE_THRESHOLD_DELTA          180
#else
	#error Please select valid TS method in ts_cfg_general.h
#endif

/*******************************************************************************
* Modify: Electrode 0 defines
******************************************************************************/
#ifdef ELEC0
	// DC tracker response, the highest number, the slower response.
	// Select values from 1 to 8
	// Value 5 equals 1s at 30ms sampling period
	#define ELEC0_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	// IIR1 LP filter selection
	#define ELEC0_LPFILTER_TYPE               FILTER_1
	// Electrode touch threshold relative to DC tracker value
	#define ELEC0_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	// Electrode release threshold relative to DC tracker value
	#define ELEC0_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 1 defines
******************************************************************************/
#ifdef ELEC1
	#define ELEC1_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC1_LPFILTER_TYPE               FILTER_1
	#define ELEC1_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC1_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 2 defines
******************************************************************************/
#ifdef ELEC2
	#define ELEC2_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC2_LPFILTER_TYPE               FILTER_1
	#define ELEC2_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC2_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 3 defines
******************************************************************************/
#ifdef ELEC3
	#define ELEC3_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC3_LPFILTER_TYPE               FILTER_1
	#define ELEC3_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC3_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 4 defines
******************************************************************************/
#ifdef ELEC4
	#define ELEC4_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC4_LPFILTER_TYPE               FILTER_1
	#define ELEC4_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC4_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 5 defines
******************************************************************************/
#ifdef ELEC5
	#define ELEC5_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC5_LPFILTER_TYPE               FILTER_1
	#define ELEC5_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC5_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 6 defines
******************************************************************************/
#ifdef ELEC6
	#define ELEC6_DCTRACKER_FILTER_FACTOR     ELEC_DCTRACKER_FILTER_FACTOR_ACTIVE
	#define ELEC6_LPFILTER_TYPE               FILTER_1
	#define ELEC6_TOUCH_THRESHOLD_DELTA       ELEC_TOUCH_THRESHOLD_DELTA
	#define ELEC6_RELEASE_THRESHOLD_DELTA     ELEC_RELEASE_THRESHOLD_DELTA
#endif

/*******************************************************************************
* Modify: Electrode 7 defines (EGS)
******************************************************************************/
#ifdef ELEC7
	#define ELEC7_DCTRACKER_FILTER_FACTOR     5
	#define ELEC7_LPFILTER_TYPE               FILTER_2

	#if(TS_RAW_DATA_CALCULATION == AVERAGING)
		// Electrode touch threshold relative to DC tracker value
		#define ELEC7_TOUCH_THRESHOLD_DELTA       6
		// Electrode release threshold relative to DC tracker value
		#define ELEC7_RELEASE_THRESHOLD_DELTA     4
	#elif (TS_RAW_DATA_CALCULATION == OVERSAMPLING)
		// Electrode touch threshold relative to DC tracker value
		#define ELEC7_TOUCH_THRESHOLD_DELTA       15
		// Electrode release threshold relative to DC tracker value
		#define ELEC7_RELEASE_THRESHOLD_DELTA     10
	#else
		#error Please select valid TS method in ts_cfg_general.h
	#endif

#endif

/*******************************************************************************
* Modify: Virtual EGS Electrode touch threshold (for samples switching)
******************************************************************************/
#ifndef WAKE_UP_ELECTRODE
	#if(TS_RAW_DATA_CALCULATION == AVERAGING)
		// Virtual EGS touch threshold relative to DC tracker value
		#define VIRTUAL_EGS_TOUCH_THRESHOLD_DELTA 3
	#elif (TS_RAW_DATA_CALCULATION == OVERSAMPLING)
		// Virtual EGS touch threshold relative to DC tracker value
		#define VIRTUAL_EGS_TOUCH_THRESHOLD_DELTA 15
	#else
		#error Please select valid TS method in ts_cfg_general.h
	#endif
#endif

/*******************************************************************************
* Modify: Keypad backlight PWM dutycycle from 0 to 100
******************************************************************************/
#define BACKLIGHT_PWM_DUTYCYCLE    30

/*******************************************************************************
* Modify: Keypad backlight ON period in seconds
******************************************************************************/
#define BACKLIGHT_ON_PERIOD    3

#endif
#endif /* CFG_7PAD_7PAD_APP_H_ */
