/*
 * mco.c
 *
 *  Created on: Nov 23, 2023
 *      Author: davuo
 */

#include "mco.h"
#include "stm32f401xc.h"

void MCO_Config(void)
{
    // MC01 clock = HSI clock / MCO1PRE = 24MHz / 4 = 6MHz
    RCC->CFGR |= (0b00 << 21);              // MCO1 = 0b11, select HSI as MCO1 source
    RCC->CFGR |= (0b110 << 24);             // MCO1PRE = 0b110, divide PLL clock by 4
}
