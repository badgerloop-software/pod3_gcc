#ifndef _CONFIG__H
#define _CONFIG__H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include "defs.h"

/*****************************************************************************/
/*                           Utility Definitions                             */
/*****************************************************************************/
#define APB1_F	(SystemCoreClock >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE1) >> RCC_CFGR_PPRE1_Pos])
#define APB2_F	(SystemCoreClock >> APBPrescTable[(RCC->CFGR & RCC_CFGR_PPRE2) >> RCC_CFGR_PPRE2_Pos])
#define HCLK	SystemCoreClock
#define NEWLINE_GUARD   (curr == '\n' && prev != '\r') || (curr == '\r' && prev != '\n')
/*****************************************************************************/
/*****************************************************************************/


/*****************************************************************************/
/*                                 Oscillator                                */
/*****************************************************************************/
#define HSE_VALUE	((uint32_t) 8000000) 
#define HSI_VALUE	((uint32_t) 16000000) 
#define LSE_VALUE	((uint32_t)	32768)
/** System Clock source            = PLL (HSE w/ HSE_BYP, 8 MHz)
  * SYSCLK(Hz)                     = 160000000 (160 MHz)
  * HCLK(Hz)                       = 160000000 (160 MHz)
  * AHB, APB1, APB2 Prescalars     = 1, 4, 2
  *
  * Constraints:
  * PLLN[8:0] - 50 <= PLLN <= 432 (f_VCO must be between 100-432 MHz)
  * PLLM[5:0] - 2 <= PLLM <= 63 (f_PLL_in must be 1-2 MHz)
  * PLLP[1:0] - do not exceed 180 MHz (0 = 2, 1 = 4, 2 = 6, 3 = 8)
  * PLLQ[3:0] - 2 <= PLLQ <= 15 goal is to create 48 MHz (USB, SDMMC RNG clock src)
  * PLLR[2:0] - 2 <= PLLR <= 7 DSI clock src 
  */
#define PLLN_VAL (((uint32_t) 320) << RCC_PLLCFGR_PLLN_Pos)	/* f_VCO = f_PLL_in * (PLLN / PLLM) */
#define PLLM_VAL (((uint32_t) 8) << RCC_PLLCFGR_PLLM_Pos)	/* 320 MHz = 8 MHz * (160 / 8)		*/
#define PLLP_VAL (((uint32_t) 0) << RCC_PLLCFGR_PLLP_Pos)	/* f_PLL_out = f_VCO / PLLP	(2)		*/
#define PLLQ_VAL (((uint32_t) 10) << RCC_PLLCFGR_PLLQ_Pos)	/* f_USB_SDMMC_RNG = f_VCO / PLLQ	*/
#define PLLR_VAL (((uint32_t) 5) << RCC_PLLCFGR_PLLR_Pos)	/* f_PLL_DSI_out = f_VCO / PLLR		*/
/*****************************************************************************/
/*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
