#ifndef STM32F401xC_H
#define STM32F401xC_H

#include <stdint.h>
#include <stdbool.h>

#include "peripheral_memory_map.h"
#include "peripheral_registers_structures.h"





/****************************************************************************************************************************/
/** @addtogroup Peripheral_declaration
  * @{
  */

#define RCC                 ((RCC_TypeDef *) RCC_BASE)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)

/**
  * @}
  */





#endif // STM32F401xC_H
