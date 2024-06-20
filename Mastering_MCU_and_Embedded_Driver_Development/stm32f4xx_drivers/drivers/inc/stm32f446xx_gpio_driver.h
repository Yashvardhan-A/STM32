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
	uint8_t GPIO_PinNumber;				/*!< possible values from @GPIO_PIN_NO > */
	uint8_t GPIO_PinMode;				/*!< possible values from @GPIO_PIN_MODES > */
	uint8_t GPIO_PinSpeed;				/*!< possible values from @GPIO_PIN_SPEED > */
	uint8_t GPIO_PinPuPdControl;		/*!< possible values from @GPIO_PIN_PUPD_CFG > */
	uint8_t GPIO_PinOPType;				/*!< possible values from @GPIO_PIN_OP_TYPE > */
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


/*
 * Handle structure for a GPIO pin
 */
typedef struct {

	GPIO_RegDef_t *pGPIOx;	/* pointer to hold the base address of the GPIO a particular port */
	GPIO_PinConfig_t GPIO_PinConfig; /* This hold the GPIO's configuration settings */

}GPIO_Handle_t;


/*
 * @GPIO_PIN_NO
 * GPIO Pin numbers
 */
#define GPIO_PIN_NO_0			0
#define GPIO_PIN_NO_1			1
#define GPIO_PIN_NO_2			2
#define GPIO_PIN_NO_3			3
#define GPIO_PIN_NO_4			4
#define GPIO_PIN_NO_5			5
#define GPIO_PIN_NO_6			6
#define GPIO_PIN_NO_7			7
#define GPIO_PIN_NO_8			8
#define GPIO_PIN_NO_9			9
#define GPIO_PIN_NO_10			10
#define GPIO_PIN_NO_11			11
#define GPIO_PIN_NO_12			12
#define GPIO_PIN_NO_13			13
#define GPIO_PIN_NO_14			14
#define GPIO_PIN_NO_15			15

/*
 * @GPIO_PIN_MODES
 * GPIO modes
 */
#define GPIO_MODE_IN			0
#define GPIO_MODE_OUT			1
#define GPIO_MODE_ALTFN			2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_IT_FT			4	// Used for interrupt GPIO falling edge
#define GPIO_MODE_IT_RT			5	// Used for interrupt GPIO rising edge
#define GPIO_MODE_IT_RFT		6	// Used for interrupt GPIO rising and falling edge

/*
 * @GPIO_PIN_OP_TYPE
 * GPIO output types
 */
#define GPIO_OP_TYPE_PP			0	// PUsh-pull
#define GPIO_OP_TYPE_OD			1	// Open-drain

/*
 * @GPIO_PIN_SPEED
 * GPIO Speed output speeds
 */
#define GPIO_SPEED_LOW			0	//
#define GPIO_SPEED_MEDIUM		1	//
#define GPIO_SPEED_FAST			2	//
#define GPIO_SPEED_HIGH			3	//

/*
 * @GPIO_PIN_PUPD_CFG
 * GPIO pull-up, pull-down configurations
 */
#define GPIO_NO_PUPD			0	//
#define GPIO_PIN_PU				1	//
#define GPIO_PIN_PD				2	//



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
