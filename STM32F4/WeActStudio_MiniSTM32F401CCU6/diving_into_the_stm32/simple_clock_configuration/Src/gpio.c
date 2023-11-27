/*
 * gpio.c
 *
 *  Created on: Nov 23, 2023
 *      Author: davuo
 */

#include "gpio.h"
#include "stm32f401xc.h"

void GPIO_Config(void)
{
    // Enable AHB1 peripheral clock for GPIOA
    RCC->AHB1ENR |= (0b1 << 0);

    // Configure PA8 as MCO1
    GPIOA->MODER |= (0b10 << 16);          // MODER8 = 2, alternate function mode

    GPIOA->AFR[1] |= (0b0000 << 0);        // GPIOA_AFRH8 = AF0, select MCO1 as alternate function
}
