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
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ADC_BASE_ADDR 			0x40012400UL
#define ADC_CR1_OFFSET 				0x08UL
#define ADC_SCAND_ENABLE 		(ADC_BASE_ADDR+ADC_CR1_OFFSET)

#define RCC_BASE_APB1 			0x40021000UL
#define RCC_CLOCK_ADC_OFFSET    0x40UL
#define RCC_APB_CLOCK			(RCC_CLOCK_ADC_OFFSET+RCC_BASE_APB1)

int main(void)
{
	uint32_t *pADCCtrlReg=(uint32_t *) ADC_SCAND_ENABLE;
	uint32_t *pRCCCtrl=(uint32_t *) RCC_APB_CLOCK;
	*pRCCCtrl |= ( 1 << 20 );
	*pADCCtrlReg |=( 1 << 2 );
    /* Loop forever */
	for(;;);
}
