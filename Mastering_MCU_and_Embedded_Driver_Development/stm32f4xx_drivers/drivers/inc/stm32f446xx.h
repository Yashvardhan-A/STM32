/*
 * stm32f446xx.h
 *
 *  Created on: Jun 15, 2024
 *      Author: yashvardhan
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define __vo volatile
// By default compiler treats these as signed, hence they can either be
// type-casted (uint32_t) or we can use u
#define FLASH_BASEADDR 							0x08000000u		// Flash or Main Memory base address
#define SRAM1_BASEADDR 							0x20000000u		// SRAM base address = SRAM1 base address
#define SRAM2_BASEADDR							0x2001C000u		// SRAM2 base address = SRAM1 base address + 112KB (size of SRAM1)
#define ROM										0x1FFF0000u		// ROM or System Memory base address
#define SRAM 									SRAM1_BASEADDR

// AHBx and APBx Bus Peripheral base addresses
#define PERIPH_BASE								0x40000000u
#define APB1PERIPH_BASEADDR						PERIPH_BASE
#define APB2PERIPH_BASEADDR						0x40010000u
#define AHB1PERIPH_BASEADDR						0x40020000u
#define AHB2PERIPH_BASEADDR						0x50000000u

// Base Addresses of Peripherals hanging on AHB1 BUS
#define GPIOA_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR							(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR							(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR							(AHB1PERIPH_BASEADDR + 0x3800)

// Base Addresses of Peripherals hanging on APB1 BUS
#define I2C1_BASEADDR							(APB1PERIPH_BASEADDR + 0X5400)
#define I2C2_BASEADDR							(APB1PERIPH_BASEADDR + 0X5800)
#define I2C3_BASEADDR							(APB1PERIPH_BASEADDR + 0X5C00)

#define SPI2_BASEADDR							(APB1PERIPH_BASEADDR + 0X3800)
#define SPI3_BASEADDR							(APB1PERIPH_BASEADDR + 0X3C00)

#define USART2_BASEADDR							(APB1PERIPH_BASEADDR + 0X4400)
#define USART3_BASEADDR							(APB1PERIPH_BASEADDR + 0X4800)
#define UART4_BASEADDR							(APB1PERIPH_BASEADDR + 0X4C00)
#define UART5_BASEADDR							(APB1PERIPH_BASEADDR + 0X5000)

// Base Addresses of Peripherals hanging on APB2 BUS
#define SPI1_BASEADDR							(APB2PERIPH_BASEADDR + 0X3000)
#define USART1_BASEADDR							(APB2PERIPH_BASEADDR + 0X1000)
#define USART6_BASEADDR							(APB2PERIPH_BASEADDR + 0X1400)
#define EXTI_BASEADDR							(APB2PERIPH_BASEADDR + 0X3C00)
#define SYSCFG_BASEADDR							(APB2PERIPH_BASEADDR + 0X3800)


// Peripheral register definition structures

typedef struct {
	__vo uint32_t MODER;						// GPIO port mode register					Addr offset: 0x00
	__vo uint32_t OTYPER;						// GPIO port output type register			Addr offset: 0x04
	__vo uint32_t OSPEEDER;						// GPIO port output speed register			Addr offset: 0x08
	__vo uint32_t PUPDR;						// GPIO port pull-up/pull-down register		Addr offset: 0x0C
	__vo uint32_t IDR;							// GPIO port input data register			Addr offset: 0x10
	__vo uint32_t ODR;							// GPIO port output data register			Addr offset: 0x14
	__vo uint32_t BSRR;							// GPIO port bit set/reset register			Addr offset: 0x18
	__vo uint32_t LCKR;							// GPIO port configuration lock register		Addr offset: 0x1C
	__vo uint32_t AFR[2];						// AFR[0]: GPIO alternate function low register, AFR[1]: GPIO alternate function high register		Addr offset: 0x20, 0x24
}GPIO_RegDef_t;


typedef struct {
	__vo uint32_t CR;							// RCC clock control register									Addr offset: 0x00
	__vo uint32_t PLLCFGR;						// RCC PLL configuration register								Addr offset: 0x04
	__vo uint32_t CFGR;							// RCC clock configuration register								Addr offset: 0x08
	__vo uint32_t CIR;							// RCC clock interrupt register									Addr offset: 0x0C
	__vo uint32_t AHB1RSTR;						// RCC AHB1 peripheral reset register							Addr offset: 0x10
	__vo uint32_t AHB2RSTR;						// RCC AHB2 peripheral reset register							Addr offset: 0x14
	__vo uint32_t AHB3RSTR;						// RCC AHB3 peripheral reset register							Addr offset: 0x18
	__vo uint32_t RESERVED0;					// Reserved														Addr offset: 0x1C
	__vo uint32_t APB1RSTR;						// RCC APB1 peripheral reset register							Addr offset: 0x20
	__vo uint32_t APB2RSTR;						// RCC APB2 peripheral reset register							Addr offset: 0x24
	__vo uint32_t RESERVED1;					// Reserved														Addr offset: 0x28
	__vo uint32_t RESERVED2;					// Reserved														Addr offset: 0x2C
	__vo uint32_t AHB1ENR;						// RCC AHB1 peripheral clock enable register					Addr offset: 0x30
	__vo uint32_t AHB2ENR;						// RCC AHB2 peripheral clock enable register					Addr offset: 0x34
	__vo uint32_t AHB3ENR;						// RCC AHB3 peripheral clock enable register					Addr offset: 0x38
	__vo uint32_t RESERVED3;					// Reserved														Addr offset: 0x3C
	__vo uint32_t APB1ENR;						// RCC APB1 peripheral clock enable register					Addr offset: 0x40
	__vo uint32_t APB2ENR;						// RCC APB2 peripheral clock enable register					Addr offset: 0x44
	__vo uint32_t RESERVED4;					// Reserved														Addr offset: 0x48
	__vo uint32_t RESERVED5;					// Reserved														Addr offset: 0x4C
	__vo uint32_t AHB1LPENR;					// RCC AHB1 peripheral clock enable in low power mode register	Addr offset: 0x50
	__vo uint32_t AHB2LPENR;					// RCC AHB2 peripheral clock enable in low power mode register	Addr offset: 0x54
	__vo uint32_t AHB3LPENR;					// RCC AHB3 peripheral clock enable in low power mode register	Addr offset: 0x58
	__vo uint32_t RESERVED6;					// Reserved														Addr offset: 0x5C
	__vo uint32_t APB1LPENR;					// RCC APB1 peripheral clock enable in low power mode register	Addr offset: 0x60
	__vo uint32_t APB2LPENR;					// RCC APB2 peripheral clock enable in low power mode register	Addr offset: 0x64
	__vo uint32_t RESERVED7;					// Reserved														Addr offset: 0x68
	__vo uint32_t RESERVED8;					// Reserved														Addr offset: 0x6c
	__vo uint32_t BDCR;							// RCC Backup domain control register							Addr offset: 0x70
	__vo uint32_t CSR;							// RCC clock control & status register							Addr offset: 0x74
	__vo uint32_t RESERVED9;					// Reserved														Addr offset: 0x78
	__vo uint32_t RESERVED10;					// Reserved														Addr offset: 0x7C
	__vo uint32_t SSCGR;						// RCC spread spectrum clock generation register				Addr offset: 0x80
	__vo uint32_t PLLI2SCFGR;					// RCC PLLI2S configuration register							Addr offset: 0x84
	__vo uint32_t PLLSAICFGR;					// RCC PLL configuration register								Addr offset: 0x88
	__vo uint32_t DCKCFGR;						// RCC dedicated clock configuration register					Addr offset: 0x8C
	__vo uint32_t CKGATENR;						// RCC clocks gated enable register								Addr offset: 0x90
	__vo uint32_t DCKCFGR2;						// RCC dedicated clocks configuration register 2				Addr offset: 0x94


}RCC_RegDef_t;


// Peripheral definitions
#define GPIOA									((GPIO_RegDef_t *) GPIOA_BASEADDR)
#define GPIOB									((GPIO_RegDef_t *) GPIOB_BASEADDR)
#define GPIOC									((GPIO_RegDef_t *) GPIOC_BASEADDR)
#define GPIOD									((GPIO_RegDef_t *) GPIOD_BASEADDR)
#define GPIOE									((GPIO_RegDef_t *) GPIOE_BASEADDR)
#define GPIOF									((GPIO_RegDef_t *) GPIOF_BASEADDR)
#define GPIOG									((GPIO_RegDef_t *) GPIOG_BASEADDR)
#define GPIOH									((GPIO_RegDef_t *) GPIOH_BASEADDR)

#define RCC										((RCC_RegDef_t *) RCC_BASEADDR)

// Clock enable macros for GPIox peripherals
#define GPIOA_PCLK_EN()							( RCC->AHB1ENR |= (1 << 0) )
#define GPIOB_PCLK_EN()							( RCC->AHB1ENR |= (1 << 1) )
#define GPIOC_PCLK_EN()							( RCC->AHB1ENR |= (1 << 2) )
#define GPIOD_PCLK_EN()							( RCC->AHB1ENR |= (1 << 3) )
#define GPIOE_PCLK_EN()							( RCC->AHB1ENR |= (1 << 4) )
#define GPIOF_PCLK_EN()							( RCC->AHB1ENR |= (1 << 5) )
#define GPIOG_PCLK_EN()							( RCC->AHB1ENR |= (1 << 6) )
#define GPIOH_PCLK_EN()							( RCC->AHB1ENR |= (1 << 7) )

// Clock disable macros for GPIox peripherals
#define GPIOA_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 0) )
#define GPIOB_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 1) )
#define GPIOC_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 2) )
#define GPIOD_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 3) )
#define GPIOE_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 4) )
#define GPIOF_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 5) )
#define GPIOG_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 6) )
#define GPIOH_PCLK_DI()							( RCC->AHB1ENR &= ~(1 << 7) )


// Clock enable and disable macros for I2C peripherals
#define I2C1_PCLK_EN()							( RCC->APB1ENR |= (1 << 21) )
#define I2C2_PCLK_EN()							( RCC->APB1ENR |= (1 << 22) )
#define I2C3_PCLK_EN()							( RCC->APB1ENR |= (1 << 23) )

#define I2C1_PCLK_DI()							( RCC->APB1ENR &= ~(1 << 21) )
#define I2C2_PCLK_DI()							( RCC->APB1ENR &= ~(1 << 22) )
#define I2C3_PCLK_DI()							( RCC->APB1ENR &= ~(1 << 23) )


// Clock enable and disable macros for SPI peripherals
#define SPI1_PCLK_EN()							( RCC->APB2ENR |= (1 << 12) )
#define SPI2_PCLK_EN()							( RCC->APB1ENR |= (1 << 14) )
#define SPI3_PCLK_EN()							( RCC->APB1ENR |= (1 << 15) )

#define SPI1_PCLK_DI()							( RCC->APB2ENR &= ~(1 << 12) )
#define SPI2_PCLK_DI()							( RCC->APB1ENR &= ~(1 << 14) )
#define SPI3_PCLK_DI()							( RCC->APB1ENR &= ~(1 << 15) )


// Clock enable and disable macros for USART/UART peripherals
#define USART1_PCLK_EN()							( (RCC->APB2ENR) |= (1 << 4) )
#define USART2_PCLK_EN()							( (RCC->APB1ENR) |= (1 << 17) )
#define USART3_PCLK_EN()							( (RCC->APB1ENR) |= (1 << 18) )
#define UART4_PCLK_EN()							( (RCC->APB1ENR) |= (1 << 19) )
#define UART5_PCLK_EN()							( (RCC->APB1ENR) |= (1 << 20) )
#define USART6_PCLK_EN()							( (RCC->APB2ENR) |= (1 << 5) )

#define USART1_PCLK_DI()							( (RCC->APB2ENR) &= ~(1 << 4) )
#define USART2_PCLK_DI()							( (RCC->APB1ENR) &= ~(1 << 17) )
#define USART3_PCLK_DI()							( (RCC->APB1ENR) &= ~(1 << 18) )
#define UART4_PCLK_DI()							( (RCC->APB1ENR) &= ~(1 << 19) )
#define UART5_PCLK_DI()							( (RCC->APB1ENR) &= ~(1 << 20) )
#define USART6_PCLK_DI()							( (RCC->APB2ENR) &= ~(1 << 5) )



// Clock enable and disable macros for SYSCFG peripherals
#define SYSCFG_PCLK_EN()							( (RCC->APB2ENR) |= (1 << 14) )
#define SYSCFG_PCLK_DI()							( (RCC->APB2ENR) &= ~(1 << 14) )


#endif /* INC_STM32F446XX_H_ */
