/*
 * stm32f446xx.h
 *
 *  Created on: Jun 15, 2024
 *      Author: yashvardhan
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

// By default compiler treats these as signed, hence they can either be
// type-casted (uint32_t) or we can use u
#define FLASH_BASEADDR 							0x08000000u		// Flash or Main Memory base address
#define SRAM1_BASEADDR 							0x20000000u		// SRAM base address = SRAM1 base address
#define SRAM2_BASEADDR							0x2001C000u		// SRAM2 base address = SRAM1 base address + 112KB (size of SRAM1)
#define ROM										0x1FFF0000u		// ROM or System Memory base address
#define SRAM 									SRAM1_BASEADDR

// AHBx and APBx Bus Peripheral base addresses
#define PERIPH_BASE								0x40000000u
#define APB1PERIPH_BASE							PERIPH_BASE
#define APB2PERIPH_BASE							0x40010000u
#define AHB1PERIPH_BASE							0x40020000u
#define AHB2PERIPH_BASE							0x50000000u

#endif /* INC_STM32F446XX_H_ */
