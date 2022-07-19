/**
 ************************************************************************************************
 * @file           : GPIO.c
 * @author         : Kunal Salvi
 * @brief          : Source File for GPIO Driver
 ***********************************************************************************************
 * This is the source file for the GPIO driver and contains all the functions that the user can
 * use to configure the physical pins of the MCU.
 ************************************************************************************************
 */


#include "GPIO.h"



void GPIO_Pin_Setup(GPIO_TypeDef *Port, uint8_t pin, uint8_t function)
{
	if(Port == GPIOA)
	{
		if((function == ALT_OPEN_DRAIN_OUTPUT) || (function == ALT_PUSH_PULL_OUTPUT))
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
		}
		else
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
		}

		if(pin < 8)
		{
			Port -> CRL |= function << (4*pin);
		}
		else
		{
			Port -> CRH |= function << (4*(pin - 8));
		}
	}


	if(Port == GPIOB)
	{
		if((function == ALT_OPEN_DRAIN_OUTPUT) || (function == ALT_PUSH_PULL_OUTPUT))
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_AFIOEN;
		}
		else
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
		}

		if(pin < 8)
		{
			Port -> CRL |= function << (4*pin);
		}
		else
		{
			Port -> CRH |= function << (4*(pin - 8));
		}
	}

	if(Port == GPIOC)
	{
		if((function == ALT_OPEN_DRAIN_OUTPUT) || (function == ALT_PUSH_PULL_OUTPUT))
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
		}
		else
		{
			RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
		}

		if(pin < 8)
		{
			Port -> CRL |= function << (4*pin);
		}
		else
		{
			Port -> CRH |= function << (4*(pin - 8));
		}
	}
}

void GPIO_Interrupt_Setup(int pin, int edge_select)
{
	EXTI ->IMR |= 1 << pin;
	switch (edge_select) {
		case 0:
			EXTI ->RTSR |= 1 << pin;
			break;
		case 1:
			EXTI ->FTSR |= 1 << pin;
			break;
		case 2:
			EXTI ->RTSR |= 1 << pin;
			EXTI ->FTSR |= 1 << pin;
			break;
	}

	NVIC_SetPriority(EXTI0_IRQn,0);
	NVIC_EnableIRQ(EXTI0_IRQn);
}
