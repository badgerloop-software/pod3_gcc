#ifndef __SYSTEM_STM32L4XX_H
#define __SYSTEM_STM32L4XX_H

#include "stm32l4xx.h"

#define HSE_VALUE	8000000U  /* Value of the External oscillator in Hz */
#define MSI_VALUE	4000000U  /* Value of the Internal oscillator in Hz */
#define HSI_VALUE	16000000U /* Value of the Internal oscillator in Hz */

extern uint32_t SystemCoreClock;            /*!< System Clock Frequency (Core Clock) */
extern volatile unsigned int ticks;

extern const uint8_t  AHBPrescTable[16];    /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];     /*!< APB prescalers table values */
extern const uint32_t MSIRangeTable[12];    /*!< MSI ranges table values     */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

#define LED3_PIN	3
#define LED_PORT	GPIOB

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x00 /*!< Vector Table base offset field.
                                   This value must be a multiple of 0x200. */
/******************************************************************************/

#endif
