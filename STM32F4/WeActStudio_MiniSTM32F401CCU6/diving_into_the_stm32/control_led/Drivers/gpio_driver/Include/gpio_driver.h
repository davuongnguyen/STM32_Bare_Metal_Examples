/*
 * gpio_driver.h
 *
 *  Created on: Dec 12, 2023
 *      Author: davuo
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#ifdef __cplusplus
	extern "C" {
#endif





#include "stm32f401xc.h"

/****************************************************************************************************************************/

/** 
 * @defgroup GPIO_Exported_Constants GPIO Exported Constants
 * @{
 */

/** 
 * @defgroup GPIO_pins_define GPIO pins define
 * @{
 */
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_PIN_MASK              0x0000FFFFU /* PIN mask for assert test */
/**
 * @}
 */

/** 
 * @defgroup GPIO_Private_Constants GPIO Private Constants
 * @{
 */
#define GPIO_MODE_Pos                           0U
#define GPIO_MODE                               (0x3UL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0UL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1UL << GPIO_MODE_Pos)
#define MODE_AF                                 (0x2UL << GPIO_MODE_Pos)
#define MODE_ANALOG                             (0x3UL << GPIO_MODE_Pos)
#define OUTPUT_TYPE_Pos                         4U
#define OUTPUT_TYPE                             (0x1UL << OUTPUT_TYPE_Pos)
#define OUTPUT_PP                               (0x0UL << OUTPUT_TYPE_Pos)
#define OUTPUT_OD                               (0x1UL << OUTPUT_TYPE_Pos)
/**
 * @}
 */

/** 
 * @defgroup GPIO_mode_define GPIO mode define
 * @brief GPIO Configuration Mode
 * @{
 */
#define  GPIO_MODE_INPUT                        MODE_INPUT							/*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP                    (MODE_OUTPUT | OUTPUT_PP)			/*!< Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD                    (MODE_OUTPUT | OUTPUT_OD)			/*!< Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP                        (MODE_AF | OUTPUT_PP)				/*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD                        (MODE_AF | OUTPUT_OD)				/*!< Alternate Function Open Drain Mode    */
/**
 * @}
 */

/** 
 * @defgroup GPIO_speed_define  GPIO speed define
 * @brief GPIO Output Maximum frequency
 * @{
 */
#define  GPIO_SPEED_FREQ_LOW         0x00000000U  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_MEDIUM      0x00000001U  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define  GPIO_SPEED_FREQ_HIGH        0x00000002U  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define  GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
/**
 * @}
 */

/** 
 * @defgroup GPIO_pull_define GPIO pull define
 * @brief GPIO Pull-Up or Pull-Down Activation
 * @{
 */
#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation                */
/**
 * @}
 */

/**
 * @defgroup GPIO_alternate_function GPIO Alternate define
 * @brief GPIO Alternate Activation
 * 		  Please refer to the datasheet for more information
 * @{
 */
#define AF0 	0000
#define AF1 	0001
#define AF2 	0010
#define AF3 	0011
#define AF4 	0100
#define AF5 	0101
#define AF6 	0110
#define AF7 	0111
#define AF8 	1000
#define AF9 	1001
#define AF10 	1010
#define AF11 	1011
#define AF12 	1100
#define AF13 	1101
#define AF14 	1110
#define AF15 	1111
/**
 * @}
 */

/**
* @}
*/



/****************************************************************************************************************************/
/**
 * @brief This is a Configuration structure for a GPIO pin
 */
typedef struct
{
	uint32_t Pin; 		/*!< Specifies the GPIO pins to be configured.
							 This parameter can be any value of @ref GPIO_pins_define */
	uint32_t Mode; 		/*!< Specifies the operating mode for the selected pins.
							 This parameter can be a value of @ref GPIO_mode_define */
	uint32_t Pull; 		/*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
							 This parameter can be a value of @ref GPIO_pull_define */
	uint32_t Speed; 	/*!< Specifies the speed for the selected pins.
							 This parameter can be a value of @ref GPIO_speed_define */
	uint32_t Alternate; /*!< Peripheral to be connected to the selected pins.
							 This parameter can be a value of @ref GPIO_Alternate_function_selection */
} GPIO_PinConfig_t;

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
	GPIO_PIN_RESET = 0,
	GPIO_PIN_SET
} GPIO_PinState;

/**
 * @defgroup GPIO_Status
 * @brief  Status structures definition
 * @{
 */
typedef enum
{
	OK       = 0x00U,
	ERROR    = 0x01U,
	BUSY     = 0x02U,
	TIMEOUT  = 0x03U
} GPIO_Status;
/**
 * @}
 */



/****************************************************************************************************************************/
/**
 * @brief  Initializes the GPIOx peripheral according to the specified parameters in the GPIO_Init.
 * @param  GPIOx where x can be A, B,...
 * @param  GPIO_Init pointer to a GPIO_PinConfig_t structure that contains
 *         the configuration information for the specified GPIO peripheral.
 * @retval None
 */
void GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *GPIO_Init);

/**
 * @brief  De-initializes the GPIOx peripheral registers to their default reset values.
 * @param  GPIOx where x can be A, B,...
 * @retval None
 */
void GPIO_DeInit (GPIO_TypeDef *GPIOx);

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx where x can be A, B,...
 * @param  GPIO_Pin specifies the port bit to read.
 *         This parameter can be GPIO_PIN_x where x can be (0..15).
 * @retval The input port pin value.
 */
GPIO_PinState GPIO_ReadPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Sets or clears the selected data port bit.
 * @note   This function uses GPIOx_BSRR register to allow atomic read/modify
 *         accesses. In this way, there is no risk of an IRQ occurring between
 *         the read and the modify access.
 * @param  GPIOx where x can be A, B,...
 * @param  GPIO_Pin specifies the port bit to be written.
 *         This parameter can be one of GPIO_PIN_x where x can be (0..15).
 * @param  PinState specifies the value to be written to the selected bit.
 *         This parameter can be one of the GPIO_PinState enum values:
 *         @arg GPIO_PIN_RESET: to clear the port pin
 *         @arg GPIO_PIN_SET: to set the port pin
 * @retval None
 */
void GPIO_WritePin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

/**
 * @brief  Toggles the specified GPIO pins.
 * @param  GPIOx Where x can be A, B,...
 * @param  GPIO_Pin Specifies the pins to be toggled.
 * @retval None
 */
void GPIO_TogglePin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
 * @brief  Locks GPIO Pins configuration registers.
 * @note   The locked registers are GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR,
 *         GPIOx_PUPDR, GPIOx_AFRL and GPIOx_AFRH.
 * @note   The configuration of the locked GPIO pins can no longer be modified
 *         until the next reset.
 * @param  GPIOx where x can be A, B,...
 * @param  GPIO_Pin specifies the port bit to be locked.
 *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15).
 * @retval GPIO status.
 * 		   This parameter can be a value of @ref GPIO_Status
 */
GPIO_Status GPIO_LockPin (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);





#ifdef __cplusplus
}
#endif

#endif /* GPIO_DRIVER_H_ */
