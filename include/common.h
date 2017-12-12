#ifndef _COMMON_H
#define _COMMON_H

#define APB1_F	(SystemCoreClock >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos])
#define APB2_F	(SystemCoreClock >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos])

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
extern volatile unsigned int ticks;

extern const uint8_t  AHBPrescTable[16];    /*!< AHB prescalers table values */
extern const uint8_t  APBPrescTable[8];     /*!< APB prescalers table values */
#ifdef STM32L4
extern const uint32_t MSIRangeTable[12];    /*!< MSI ranges table values     */
#endif
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);

#endif
