/*
 * rcc_driver.c
 *
 *  Created on: Dec 13, 2023
 *      Author: davuo
 */

#include "rcc_driver.h"

void SystemClock_Config(void)
{
    // Configure PLL clock source and multiplication factor
    RCC->CR |= (0b1 << 0);                          // HSION = 1, turn on HSI oscillator
    while((RCC->CR & (0b1 << 1)) != (0b1 << 1));    // Wait until HSI is ready

    RCC->CFGR |= (0b00 << 0);                       // SW = 0b00, select HSI as system clock
}
