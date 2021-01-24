/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include<stdint.h>
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_BASE_ADDR 			0x40021000UL // This got from Memory and bus architecture
#define RCC_CFGR_REG_OFFSET 	0x08UL // this got from RCC->Clock Configuration register
#define RCC_CR_REG_OFFSET    	0x00UL
#define RCC_CFGR_REG_ADDR		(RCC_BASE_ADDR+RCC_CFGR_REG_OFFSET)
#define RCC_CR_REG_ADDR			(RCC_BASE_ADDR+RCC_CR_REG_OFFSET)
#define GPIO_BASE_ADDR			0x50000000UL

int main(void)
{
    /* Loop forever */
	//1st RCC Configuration Register to be configured to initiate MC01

	uint32_t *pRccCfrReg=(uint32_t *)RCC_CFGR_REG_ADDR;
	// in this register, bit 27 to 24 is used to select HSI16 clock to PA8
	*pRccCfrReg&=~(0xff<<24);

	//2 -  Enabling peripheral Clock to GPIOA for which need to have
	// I/O Port Clock enable register

	uint32_t *pRccRn2GPIO=(uint32_t *)(RCC_BASE_ADDR+0x34);
	*pRccRn2GPIO|=(1<<0);

	//3- GPIO - Mode register
	// GPIO-Port mode register (GPIOx_MODER)
	// the PA8 which is in 8th pin
	//MODE8 has 17 &16 th bit
	// need to configure mode to Alternative  1,0

	uint32_t *pGPIOAModSel=(uint32_t*)(GPIO_BASE_ADDR+0x00);
	*pGPIOAModSel&=~(0x03<<16);//clearing Bit
	*pGPIOAModSel|=(0x02<<16);//Setting the pit to Alternative function

	//

	//4- Making PORTA has an Alternative function
	// pA8 --a is x & 8 is Y
	//comes under GPIO alternative function high register (GPIOx_AFRH);
	//A to F
	//AFSEL8  -- {3:0]
	// MCO Comes in AF0 in port A8th Pin

	uint32_t *pGPIOALFHighAMcoHSI=(uint32_t*)(GPIO_BASE_ADDR+0X24);
	*pGPIOALFHighAMcoHSI&=~(0xFF<<0);//clearing
	*pGPIOALFHighAMcoHSI|=(0x00<<0);

	for(;;);
}
