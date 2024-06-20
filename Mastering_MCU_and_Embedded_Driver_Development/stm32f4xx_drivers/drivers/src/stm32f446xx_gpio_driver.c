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
/**************************************************************************************************************************
 * @fn				-	GPIO_Init
 *
 * @brief			-	Initialize a GPIO pin with its mode, speed, pull up - pull down settings, optype, and alt function configuration
 *
 * @param[in]		-	GPIO_Handle_t struct with the required pin configuration filled up
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle) {

	// temporary register
	uint32_t temp = 0;

	// Configure GPIO mode
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG) {
		// non interrupt mode
		temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
		pGPIOHandle->pGPIOx->MODER |= temp;
	} else {
		// interrupt mode
	}

	// Configure GPIO speed
	temp = 0;
	pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDER |= temp;

	// Configure the pupd settings
	temp = 0;
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	// Configure the optype
	temp = 0;
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //clearing
	temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	// Configure the alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN) {

		// Configure the alt function registers
		uint8_t temp1, temp2;

		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8);
		temp2 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8);
		temp = pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2);
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2)); //clearing
		pGPIOHandle->pGPIOx->AFR[temp1] |= temp;
	}




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
