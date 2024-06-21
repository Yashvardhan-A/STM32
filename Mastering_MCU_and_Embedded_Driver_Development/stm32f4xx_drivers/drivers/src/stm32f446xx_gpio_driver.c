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
 * Init
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
/*
 * DeInit
 */
/**************************************************************************************************************************
 * @fn				-	GPIO_Deinit
 *
 * @brief			-	De-initialize a GPIO port
 *
 * @param[in]		-	GPIO_RegDef_t: GPIOx of the GPIO port to de-initialize
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx) {

	if(GPIOA == pGPIOx)
			GPIOA_REG_RESET();

		else if(GPIOB == pGPIOx)
			GPIOB_REG_RESET();

		else if(GPIOC == pGPIOx)
			GPIOC_REG_RESET();

		else if(GPIOD == pGPIOx)
			GPIOD_REG_RESET();

		else if(GPIOE == pGPIOx)
			GPIOE_REG_RESET();

		else if(GPIOF == pGPIOx)
			GPIOF_REG_RESET();

		else if(GPIOG == pGPIOx)
			GPIOG_REG_RESET();

		else if(GPIOH == pGPIOx)
			GPIOH_REG_RESET();
}


/*
 * Data read write
 */

/**************************************************************************************************************************
 * @fn				-	GPIO_ReadFromInputPin
 *
 * @brief			-	Read input value from a GPIO pin
 *
 * @param[in]		-	GPIO_RegDef_t: GPIO port to which the pin belongs
 * @param[in]		-	uint8_t: Pin number to read from
 *
 * @return			-	uint8_t: GPIO_PIN_SET or GPIO_PIN_RESET
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}


/**************************************************************************************************************************
 * @fn				-	GPIO_ReadFromInputPort
 *
 * @brief			-	Read input value from a GPIO port
 *
 * @param[in]		-	GPIO_RegDef_t: GPIO port to read from
 *
 * @return			-	uint16_t: value read from GPIO port
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx) {
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}


/**************************************************************************************************************************
 * @fn				-	GPIO_WriteToOutputPin
 *
 * @brief			-	Write value to GPIO pin
 *
 * @param[in]		-	GPIO_RegDef_t: GPIO port to to write to
 * @param[in]		-	uint8_t: Pin number to write to
 * @param[in]		-	uint8_t: Value to write - GPIO_PIN_SET or GPIO_PIN_RESET
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value) {

	if(Value == GPIO_PIN_SET)
		pGPIOx->ODR |= (1 << PinNumber);
	else
		pGPIOx->ODR &= ~(1 << PinNumber);
}


/**************************************************************************************************************************
 * @fn				-	GPIO_WriteToOutputPort
 *
 * @brief			-	Write value to GPIO port
 *
 * @param[in]		-	GPIO_RegDef_t: GPIO port to write to
 * @param[in]		-	uint16_t: Value to write
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value) {

	pGPIOx->ODR = Value;
}


/**************************************************************************************************************************
 * @fn				-	GPIO_ToggelOutputPin
 *
 * @brief			-	Toggle a GPIO output pin
 *
 * @param[in]		-	GPIO_RegDef_t: GPIO port to toggle
 * @param[in]		-	uint8_t: Pin number to toggle
 *
 * @return			-	none
 *
 * @Note			-	none
 *
 ****************************************************************************************************************************/
void GPIO_ToggelOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber) {

	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ config and ISR callback
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi) {

}
void GPIO_IRQCallback(uint8_t PinNumber) {

}
