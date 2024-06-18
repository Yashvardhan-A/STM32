/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: Jun 19, 2024
 *      Author: yashvardhan
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_


#include "stm32f446xx.h"

/*
 * Configuration structure for a GPIO pin
 */
typedef struct {
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * Handle structure for a GPIO pin
 */
typedef struct {

	GPIO_RegDef_t *pGPIOx;	/* pointer to hold the base address of the GPIO a particular port */
	GPIO_PinConfig_t GPIO_PinConfig; /* This hold the GPIO's configuration settings */

}GPIO_Handle_t;


/****************************************************************
 * 						API for this driver
 ****************************************************************/

/*
 * Peripheral clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggelOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ config and ISR callback
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQCallback(uint8_t PinNumber);

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */