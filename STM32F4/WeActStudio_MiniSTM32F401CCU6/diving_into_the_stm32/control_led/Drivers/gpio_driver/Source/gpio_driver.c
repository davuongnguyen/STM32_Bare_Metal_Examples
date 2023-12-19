/*
 * gpio_driver.c
 *
 *  Created on: Dec 12, 2023
 *      Author: davuo
 */

#include "gpio_driver.h"
#include "rcc_driver.h"


/****************************************************************************************************************************/
#define ENABLE 		true
#define DISABLE		false

#define SET			true
#define RESET		false




/****************************************************************************************************************************/
void GPIO_ClockConfig(GPIO_TypeDef *GPIOx, bool Status);





/****************************************************************************************************************************/
void GPIO_ClockConfig(GPIO_TypeDef *GPIOx, bool Status)
{
	// Enable the GPIO port clock
	if (Status == true)
	{
		if (GPIOx == GPIOA)
			GPIOA_PCLK_EN();
		else if (GPIOx == GPIOB)
			GPIOB_PCLK_EN();
		else if (GPIOx == GPIOC)
			GPIOC_PCLK_EN();
		else if (GPIOx == GPIOE)
			GPIOE_PCLK_EN();
		else if (GPIOx == GPIOH)
			GPIOH_PCLK_EN();
	}
	// Disable the GPIO port clock
	else if (Status == false)
	{
		if (GPIOx == GPIOA)
			GPIOA_PCLK_RS();
		else if (GPIOx == GPIOB)
			GPIOB_PCLK_RS();
		else if (GPIOx == GPIOC)
			GPIOC_PCLK_RS();
		else if (GPIOx == GPIOE)
			GPIOE_PCLK_RS();
		else if (GPIOx == GPIOH)
			GPIOH_PCLK_RS();
	}
}

void GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *GPIO_Init)
{
	uint32_t position = 0;
	uint32_t ioposition = 0;
	uint32_t iocurrent = 0;
	uint32_t temp = 0;

	// Enable the GPIO peripheral clock
	GPIO_ClockConfig(GPIOx, ENABLE);

	/* Configure the port pins */
	for (position = 0; position < 16; position++)
	{
		/* Get the IO position */
		ioposition = 0x01U << position;

		/* Get the current IO position */
		iocurrent = (uint32_t)GPIO_Init->Pin & ioposition;

		if (iocurrent == ioposition)
		{
			/*--------------------- GPIO Pull Configuration ------------------------*/
			if ((GPIO_Init->Mode & GPIO_MODE) != MODE_ANALOG)
			{
				temp = (GPIO_Init->Pull) << (position * 2);				// Get setting
				GPIOx->PUPDR &= ~(0x3 << (position * 2));				// Reset
				GPIOx->PUPDR |= temp;									// Setting
			}


			/*---------------- GPIO Speed, OP Type,... Configuration ---------------*/
			/* In case of Output or Alternate function mode selection */
			if ((GPIO_Init->Mode & GPIO_MODE) == MODE_OUTPUT || (GPIO_Init->Mode & GPIO_MODE) == MODE_AF)
			{
				// Configuration Speed
				temp = (GPIO_Init->Speed) << (position * 2);			// Get setting
				GPIOx->OSPEEDR &= ~(0x3 << (position * 2));				// Reset
				GPIOx->OSPEEDR |= temp;									// Setting

				// Configuration IO Output Type
				temp = ((GPIO_Init->Mode & OUTPUT_TYPE) >> OUTPUT_TYPE_Pos) << position;// Get setting
				GPIOx->OTYPER &= ~(0x1 << position);									// Reset
				GPIOx->OTYPER |= temp;													// Setting
			}

			/* In case of Alternate function mode selection */
			if ((GPIO_Init->Mode & GPIO_MODE) == MODE_AF)
			{
                // Configuration Alternate function
                temp = (GPIO_Init->Alternate) << ((position & 0x7) * 4);		        // Get setting
                GPIOx->AFR[position >> 3] &= ~(0xF << ((position & 0x7) * 4));	        // Reset
                GPIOx->AFR[position >> 3] |= temp;						                // Setting
			}


			/*--------------------- GPIO Mode Configuration ------------------------*/
			/* Configure IO Direction mode (Input, Output, Alternate or Analog) */
			temp = (GPIO_Init->Mode & GPIO_MODE) << (position * 2);		// Get setting
			GPIOx->MODER &= ~(0x3 << (position * 2));					// Reset
			GPIOx->MODER |= temp;										// Setting


			/*--------------------- EXTI Mode Configuration ------------------------*/
			// .................................................................... //
		}
	}
}

void GPIO_DeInit (GPIO_TypeDef *GPIOx)
{
	GPIO_ClockConfig(GPIOx, DISABLE);
}

GPIO_PinState GPIO_ReadPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_PinState states = 0;

	states = (GPIO_PinState)(GPIOx->IDR & GPIO_Pin);

	return states;
}

void GPIO_WritePin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	if (PinState == GPIO_PIN_SET)
		GPIOx->BSRR = GPIO_Pin;
	else
		GPIOx->BSRR = (uint32_t)(GPIO_Pin << 16);
}

void GPIO_TogglePin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	/* get current Output Data Register value */
	uint32_t odr = GPIOx->ODR;

	/* Set selected pins that were at low level, and reset ones that were high */
	GPIOx->BSRR = ((odr & GPIO_Pin) << 16) | (~odr & GPIO_Pin);
}

GPIO_Status GPIO_LockPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	/* Apply lock key write sequence */
	__IO uint32_t tmp = 1 << 16;	// LCKK='1'
	tmp |= GPIO_Pin;				// LCKK='1' + LCK[15-0]

	/* Set LCKx bit(s): LCKK='1' + LCK[15-0] */
	GPIOx->LCKR = tmp;
	/* Reset LCKx bit(s): LCKK='0' + LCK[15-0] */
	GPIOx->LCKR = GPIO_Pin;
	/* Set LCKx bit(s): LCKK='1' + LCK[15-0] */
	GPIOx->LCKR = tmp;
	/* Read LCKR register. This read is mandatory to complete key lock sequence */
	tmp = GPIOx->LCKR;

	/* Read again in order to confirm lock is active */
	if((GPIOx->LCKR & (1 << 16)) != RESET)
		return OK;
	else
		return ERROR;
}
