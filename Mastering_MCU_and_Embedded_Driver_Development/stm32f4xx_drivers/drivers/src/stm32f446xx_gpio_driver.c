/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Jun 19, 2024
 *      Author: yashvardhan
 */


#include "stm32f446xx_gpio_driver.h"


/****************************************************************
 * 						API for this driver
 ****************************************************************/

/*
 * Peripheral clock setup
 */

/**************************************************************************************************************************
 * @fn				-	GPIO_PeriClockCOntrol
 *
 * @brief			-	Enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]		-	Base address of the GPIO peripheral
 * @param[in]		-	ENABLE or DISABLE macro
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi) {

	switch (pGPIOx) {
	case GPIOA:
		EorDi ? GPIOA_PCLK_EN() : GPIOA_PCLK_DI();

	case GPIOB:
			EorDi ? GPIOB_PCLK_EN() : GPIOB_PCLK_DI();

	case GPIOC:
			EorDi ? GPIOC_PCLK_EN() : GPIOC_PCLK_DI();

	case GPIOD:
			EorDi ? GPIOD_PCLK_EN() : GPIOD_PCLK_DI();

	case GPIOE:
			EorDi ? GPIOE_PCLK_EN() : GPIOE_PCLK_DI();

	case GPIOF:
			EorDi ? GPIOF_PCLK_EN() : GPIOF_PCLK_DI();

	case GPIOG:
				EorDi ? GPIOG_PCLK_EN() : GPIOG_PCLK_DI();

	case GPIOH:
				EorDi ? GPIOH_PCLK_EN() : GPIOH_PCLK_DI();
	}

}

/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {

}

/*
 * Data read write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) {

}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value) {

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value) {

}
void GPIO_ToggelOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

}

/*
 * IRQ config and ISR callback
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi) {

}
void GPIO_IRQCallback(uint8_t PinNumber) {

}
