/*
 * Console.h
 *
 *  Created on: 17-May-2022
 *      Author: Kunal
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "main.h"
#include "GPIO.h"


void Console_Init(int32_t baudrate);
void printConsole(char *msg, ...);

#endif /* CONSOLE_H_ */
