/*
 * rcc_driver.h
 *
 *  Created on: Dec 13, 2023
 *      Author: davuo
 */

#ifndef RCC_DRIVER_H_
#define RCC_DRIVER_H_

#ifdef __cplusplus
	extern "C" {
#endif





#include "stm32f401xc.h"



/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_EN()    	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Reset Macros for GPIOx peripherals
 */
#define GPIOA_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR |= ~(1 << 0));} while(0)
#define GPIOB_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR |= ~(1 << 1));} while(0)
#define GPIOC_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR |= ~(1 << 2));} while(0)
#define GPIOD_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR |= ~(1 << 3));} while(0)
#define GPIOE_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR |= ~(1 << 4));} while(0)
#define GPIOH_PCLK_RS()		do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR |= ~(1 << 7));} while(0)


/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void);





#ifdef __cplusplus
}
#endif

#endif /* RCC_DRIVER_H_ */
