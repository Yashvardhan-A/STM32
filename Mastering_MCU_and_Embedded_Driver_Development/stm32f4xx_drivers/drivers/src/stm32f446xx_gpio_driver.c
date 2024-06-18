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


	if(GPIOA == pGPIOx)
		EnorDi ? GPIOA_PCLK_EN() : GPIOA_PCLK_DI();

	else if(GPIOB == pGPIOx)
		EnorDi ? GPIOB_PCLK_EN() : GPIOB_PCLK_DI();

	else if(GPIOC == pGPIOx)
		EnorDi ? GPIOC_PCLK_EN() : GPIOC_PCLK_DI();

	else if(GPIOD == pGPIOx)
		EnorDi ? GPIOD_PCLK_EN() : GPIOD_PCLK_DI();

	else if(GPIOE == pGPIOx)
		EnorDi ? GPIOE_PCLK_EN() : GPIOE_PCLK_DI();

	else if(GPIOF == pGPIOx)
		EnorDi ? GPIOF_PCLK_EN() : GPIOF_PCLK_DI();

	else if(GPIOG == pGPIOx)
		EnorDi ? GPIOG_PCLK_EN() : GPIOG_PCLK_DI();

	else if(GPIOH == pGPIOx)
		EnorDi ? GPIOH_PCLK_EN() : GPIOH_PCLK_DI();

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
