#ifndef __STM32L4xx_H
#define __STM32L4xx_H

#define __STM32L4_CMSIS_VERSION_MAIN   (0x01) /*!< [31:24] main version */
#define __STM32L4_CMSIS_VERSION_SUB1   (0x04) /*!< [23:16] sub1 version */
#define __STM32L4_CMSIS_VERSION_SUB2   (0x01) /*!< [15:8]  sub2 version */
#define __STM32L4_CMSIS_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32L4_CMSIS_VERSION        ((__STM32L4_CMSIS_VERSION_MAIN << 24)\
                                       |(__STM32L4_CMSIS_VERSION_SUB1 << 16)\
                                       |(__STM32L4_CMSIS_VERSION_SUB2 << 8 )\
                                       |(__STM32L4_CMSIS_VERSION_RC))

#if defined(STM32L431xx)
#include "stm32l431xx.h"
#elif defined(STM32L432xx)
#include "stm32l432xx.h"
#elif defined(STM32L433xx)
#include "stm32l433xx.h"
#elif defined(STM32L442xx)
#include "stm32l442xx.h"
#elif defined(STM32L443xx)
#include "stm32l443xx.h"
#elif defined(STM32L451xx)
#include "stm32l451xx.h"
#elif defined(STM32L452xx)
#include "stm32l452xx.h"
#elif defined(STM32L462xx)
#include "stm32l462xx.h"
#elif defined(STM32L471xx)
#include "stm32l471xx.h"
#elif defined(STM32L475xx)
#include "stm32l475xx.h"
#elif defined(STM32L476xx)
#include "stm32l476xx.h"
#elif defined(STM32L485xx)
#include "stm32l485xx.h"
#elif defined(STM32L486xx)
#include "stm32l486xx.h"
#elif defined(STM32L496xx)
#include "stm32l496xx.h"
#elif defined(STM32L4A6xx)
#include "stm32l4a6xx.h"
#elif defined(STM32L4R5xx)
#include "stm32l4r5xx.h"
#elif defined(STM32L4R7xx)
#include "stm32l4r7xx.h"
#elif defined(STM32L4R9xx)
#include "stm32l4r9xx.h"
#elif defined(STM32L4S5xx)
#include "stm32l4s5xx.h"
#elif defined(STM32L4S7xx)
#include "stm32l4s7xx.h"
#elif defined(STM32L4S9xx)
#include "stm32l4s9xx.h"
#else
#error "Please select first the target STM32L4xx device used."
#endif

typedef enum {
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum {
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {
  ERROR = 0,
  SUCCESS = !ERROR
} ErrorStatus;

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

#endif
