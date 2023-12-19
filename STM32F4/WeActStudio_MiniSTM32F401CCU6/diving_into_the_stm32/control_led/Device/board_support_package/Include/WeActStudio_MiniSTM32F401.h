/*
 * WeActStudio_MiniSTM32F401.h
 *
 *  Created on: Dec 18, 2023
 *      Author: davuo
 */

#ifndef WEACTSTUDIO_MINISTM32F401_H_
#define WEACTSTUDIO_MINISTM32F401_H_





/* Led */
#define LED_PORT			GPIOC
#define LED_PIN				GPIO_PIN_13
#define LED_ON				GPIO_PIN_RESET
#define LED_OFF				GPIO_PIN_SET

/* Button */
#define BUTTON_PORT			GPIOA
#define BUTTON_PIN			GPIO_PIN_0
#define BUTTON_ACTIVE		GPIO_PIN_RESET
#define BUTTON_DEACTIVE		GPIO_PIN_SET





#endif /* WEACTSTUDIO_MINISTM32F401_H_ */
