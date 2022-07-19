/*
 * Console.c
 *
 *  Created on: 17-May-2022
 *      Author: Kunal
 */


#include "Console.h"
#include <stdint.h>
#include "stm32f103xb.h"
#include "stm32f1xx.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "inttypes.h"

char buff[1000];

void Console_Init(int32_t baudrate)
{
	RCC -> APB2ENR |= RCC_APB2ENR_USART1EN ;
	RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;

	GPIOA -> CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9;
    GPIOA -> CRH &= ~GPIO_CRH_CNF9_0;
//	GPIO_Pin_Setup(GPIOA, 10, 0b1011);
	USART1 -> CR1 |= USART_CR1_UE;
	USART1 -> BRR = (int)(SystemCoreClock / (16 * baudrate)) << 4;
	USART1 -> CR1 |= USART_CR1_TE ;
	USART1 -> CR1 |=  USART_CR1_RE  ;
}


void printConsole(char *msg, ...)
{

	va_list args;
	va_start(args, msg);
	vsprintf(buff, msg, args);

	for(int i = 0; i<= strlen(buff)-1; i++)
	{
		USART1 -> DR = buff[i];
		while (!(USART1->SR & USART_SR_TXE));
	}

}
