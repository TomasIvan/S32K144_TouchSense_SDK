/****************************************************************************//*!
*
* @file     main.c
*
* @version  1.0.0.0
*
* @date     September-2017
*
* @brief    Touch sense main for S32K144. Compiler optimization -O3.
*
*******************************************************************************/

/*******************************************************************************
 * This version is compatible with S32DS 2018R1
 *******************************************************************************/
/*******************************************************************************
 * Includes
 *******************************************************************************/
#include "S32K144.h"
#include "main.h"
#include "scg.h"
#include "timer.h"
#include "adc.h"
#include "pcc.h"
#include "lpuart.h"
#include "freemaster.h"
#include "ets.h"
#include "power_mode.h"
#include "ts_cfg.h"
#include "gpio.h"
#include "gpio_inline_fcn2.h"
#include "flextimer.h"
#include "slider.h"

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern uint8_t   electrodeTouchQualified[NUMBER_OF_ELECTRODES];
extern uint8_t   elecNum;
extern uint8_t   sliderElectrodeTouchQualified;
uint8_t  clockMode;

// Low power mode
extern uint8_t  lowPowerModeCtrl, lowPowerModeEnable;

// RGB LED display
uint8_t  electrodeTouchQualifiedDisplay;
uint8_t  sliderElectrodeTouchQualifiedDisplay;

// Backlight PWM duty cycle from 0 to 100
extern uint16_t  backlightPWMDutyCycle;

// ADC0 and ADC1 gain register results after calibration
int16_t calibrationGainADC0;
int16_t calibrationGainADC1;

// Datalog synchronization, PTD1, 4k7 pull-up
//uint8_t datalogON;

/*****************************************************************************
 *
 * Function: void NVIC_Init(void)
 *
 * Description: Init NVIC
 *
 *****************************************************************************/
void NVIC_Init(void)
{
	// Enable LPTMR0 interrupts in NVIC
	NVIC_IRQ_ENABLE(LPTMR0_IRQn);

}

/*****************************************************************************
 *
 * Function: void GPIO_Init(void)
 *
 * Description: Init GPIO
 *
 *****************************************************************************/
void GPIO_Init(void)
{
#ifdef DEBUG_ELECTRODE_SENSE
	// Configure as GPIO pin
	DES_PORT->PCR[DES_PIN] = PORT_PCR_MUX(1);
	// Drive GPIO high
	R_RMW32(&(DES_GPIO->PSOR), DES_PIN, 1);
	// Configure as an output
	R_RMW32(&(DES_GPIO->PDDR), DES_PIN, 1);
#endif

#ifdef DEBUG_ALGORITHM   
	// Configure as GPIO pin
	DA_PORT->PCR[DA_PIN] = PORT_PCR_MUX(1);
	// Drive GPIO high
	R_RMW32(&(DA_GPIO->PSOR), DA_PIN, 1);
	// Configure as an output
	R_RMW32(&(DA_GPIO->PDDR), DA_PIN, 1);
#endif


#if(LOW_POWER_MODE == LPM_DISABLE)
	// LPUART1 pins
	// PTC6, UART1_RX
	PORTC->PCR[6] = PORT_PCR_MUX(0x2);
	// PTC7, UART1_TX
	PORTC->PCR[7] = PORT_PCR_MUX(0x2);
#endif

	// Init RGB LED pins
	RGB_LED_Init();

	// Init backlight LED pins
	Backlight_LED_Init();

	/*  // Datalog pin
    // Configure as GPIO pin
    PORTD->PCR[1] = PORT_PCR_MUX(1);
    // Configure as an input
    //BITBAND_ACCESS32(&(PTD)->PDDR,1) = 0;
    PTD->PDDR &= ~(1 << 1);*/
}

/*****************************************************************************
 *
 * Function: void RGBLED_Ctrl(void)
 *
 * Description: Display touch event
 *
 *****************************************************************************/
void RGBLED_Ctrl(void)
{
	// No touch event
	electrodeTouchQualifiedDisplay = 0xFF;

	// Search for touch event
	for (elecNum = 0; elecNum < NUMBER_OF_TOUCH_ELECTRODES; elecNum++)
	{
		// Electrode touched?
		if (electrodeTouchQualified[elecNum] == 1)
		{
			// Load electrode number
			electrodeTouchQualifiedDisplay = elecNum;

		}
	}

	// Display touch event
	switch(electrodeTouchQualifiedDisplay)
	{
#ifdef ELEC0
	case 0:
	{
		// Turn ON RED LED
		LedRedON();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}
#endif

#ifdef ELEC1
	case 1:
	{
		// Turn ON RED LED
		LedRedON();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}
#endif

#ifdef ELEC2
	case 2:
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}
#endif

#ifdef ELEC3
	case 3:
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}
#endif

#ifdef ELEC4
	case 4:
	{
		// Turn ON RED LED
		LedRedON();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}
#endif

#ifdef ELEC5
	case 5:
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}
#endif

#ifdef ELEC6
	case 6:
	{
		// Turn ON RED LED
		LedRedON();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}
#endif

	case 0xFF:
	{
#if SLIDER_ENABLE
		// Display slider touch position if no touch button was touched as they have priority over slider
		Slider_RGBLED_Ctrl();
#endif

		// If even slider was not touched
		if(sliderElectrodeTouchQualifiedDisplay == 0)
		{
			// RGB LED turn OFF
			// Turn OFF RED LED
			LedRedOFF();
			// Turn OFF GREEN LED
			LedGreenOFF();
			// Turn OFF BLUE LED
			LedBlueOFF();
		}

		break;
	}
	}
}
/*****************************************************************************
 *
 * Function: void  Slider_RGBLED_Ctrl(void)
 *
 * Description: Display slider touch event
 *
 *****************************************************************************/
void Slider_RGBLED_Ctrl(void)
{

	// SLIDER RGB
	// No touch event
	sliderElectrodeTouchQualifiedDisplay = 0;

	// Search for touch event
	// Slider Electrode touched?
	if (sliderElectrodeTouchQualified > 0)
	{
		// Load slider electrode finger position
		sliderElectrodeTouchQualifiedDisplay = sliderElectrodeTouchQualified;
	}

	// Display slider touch event
	switch(sliderElectrodeTouchQualifiedDisplay)
	{

	case 0:// Slider electrode not touched - no light
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}
	case 1:// Slider electrodes touched, sliderDifferenceDataDouble < sliderDiffThreshold[0] - white
	{
		// Turn ON RED LED
		LedRedON();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}

	case 2:// Slider electrodes touched, sliderDiffThreshold[0] < sliderDifferenceDataDouble < sliderDiffThreshold[1]- red
	{
		// Turn ON RED LED
		LedRedON();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}



	case 3:// Slider electrodes touched, sliderDiffThreshold[1] < sliderDifferenceDataDouble < sliderDiffThreshold[2] - yellow
	{
		// Turn ON RED LED
		LedRedON();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}



	case 4:// Slider electrodes touched, sliderDiffThreshold[2]  < sliderDifferenceDataDouble < sliderDiffThreshold[3] - green
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn OFF BLUE LED
		LedBlueOFF();

		break;
	}



	case 5:// Slider electrodes touched, sliderDiffThreshold[3] < sliderDifferenceDataDouble < sliderDiffThreshold[4] - blue
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}



	case 6:// Slider electrodes touched, sliderDiffThreshold[4] < sliderDifferenceDataDouble < sliderDiffThreshold[5] - purple
	{
		// Turn ON RED LED
		LedRedON();
		// Turn OFF GREEN LED
		LedGreenOFF();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}

	case 7:// Slider electrodes touched, sliderDiffThreshold[5] < sliderDifferenceDataDouble < sliderDiffThreshold[6] - azure
	{
		// Turn OFF RED LED
		LedRedOFF();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}
	case 8:// Slider electrodes touched, sliderDifferenceDataDouble > sliderDiffThreshold[6] - white again
	{
		// Turn ON RED LED
		LedRedON();
		// Turn ON GREEN LED
		LedGreenON();
		// Turn ON BLUE LED
		LedBlueON();

		break;
	}

	}

}

/*****************************************************************************
 *
 * Function: void main(void)
 *
 * Description: Main routine
 *
 *****************************************************************************/
void main(void)
{ 
	// Set clock mode
	clockMode = RUN_FIRC;

	// System clock generator init
	SCG_Init(clockMode);

	// Peripheral clock enable
	PCC_Init(clockMode);

	// Flash and enable I/D cache and write buffer
	LMEM->PCCCR = LMEM_PCCCR_GO_MASK | LMEM_PCCCR_INVW1_MASK | \
			LMEM_PCCCR_INVW0_MASK | LMEM_PCCCR_ENCACHE_MASK;

	// Wake-up timer init
	LPTMR0_Init(LPTMR_ELEC_CAL);

#if FREQUENCY_HOPPING
	// (Pre)Init LPIT wake up after 0.33 ms, do not enable yet
	LPIT_Init(ELECTRODES_SENSE_PERIOD_FH);
#endif

	// ADC0 calibration init
	calibrationGainADC0 = ADC0_Calibration();

	// ADC1 calibration init
	calibrationGainADC1 = ADC1_Calibration();

	// ADC0 init (sample time, samples number to average)
	ADC0_Init(14, 0, clockMode);

	// ADC1 init (sample time, samples number to average)
	ADC1_Init(14, 0, clockMode);

	// FTM2 init
	FTM2_Init();

	// GPIO init
	GPIO_Init();

	// Low power mode control disabled
	lowPowerModeCtrl = OFF;

#if(LOW_POWER_MODE == LPM_DISABLE)
	// Init FreeMASTER UART1
	LPUART1_Init(clockMode);

	// Init FreeMASTER, poll driven
	FMSTR_Init();

	// Disable low power mode
	lowPowerModeEnable = NO;
#else
	// Enable low power mode
	lowPowerModeEnable = YES;
#endif

	// Init electrode touch sense
	ElectrodeTouchSenseInit();

#if SLIDER_ENABLE
	// Init slider electrode touch sense
	SliderElectrodeTouchSenseInit();
#endif

	// Init backlight PWM dutycycle
	backlightPWMDutyCycle = BACKLIGHT_PWM_DUTYCYCLE;

	// Init NVIC
	NVIC_Init();

	// Enable interrupts
	EnableInterrupts;

	// Loop forever
	while(1)
	{
		// Control RGB LED - touch events display
		RGBLED_Ctrl();

		// Enable FreeMASTER poll, when low power mode disabled
		if (lowPowerModeEnable == NO)
		{
			FMSTR_Poll();
		}
		// Run low power mode?
		if ((lowPowerModeCtrl == ON) && (lowPowerModeEnable == YES))
		{
			// S32K144EVB Q100 board
			// RUN_FIRC mode typ. 20mA
			// VLPS static mode typ. 30uA

			Run_to_VLPS();
		}
		/*        // Read datalog signal
        datalogON = (PTD->PDIR) & 0x00000002;*/
	}
}
