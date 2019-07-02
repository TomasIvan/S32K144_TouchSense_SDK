/****************************************************************************//*!
*
* @file     timer.h
*
* @version  1.0.0.0
*
* @date     September-2017
*
* @brief    Timer routines header file
*
*******************************************************************************/
#ifndef __TIMER_H
#define __TIMER_H

/*******************************************************************************
* Includes
*******************************************************************************/
#include "ts_cfg.h"

/*******************************************************************************
* Defines LPTMR
******************************************************************************/
// Init LPTMR0 (num + 1 [ms])
#define LPTMR_ELEC_CAL      0  // 1ms timeout period
#define LPTMR_ELEC_SENSE    (ELECTRODES_SENSE_PERIOD - 1)

#if DECIMATION_FILTER
#define LPTMR_ELEC_SENSE_DF   (ELECTRODES_SENSE_PERIOD_DF - 1)
#endif
/*******************************************************************************
* Function prototypes
******************************************************************************/
void LPTMR0_Init(uint32_t timeout);
void Jitter(int32_t jitter);

void LPIT_Init(uint32_t timeout);
void LPIT_Enable(void);
void LPIT_Disable(void);

#endif /* __TIMER_H */
