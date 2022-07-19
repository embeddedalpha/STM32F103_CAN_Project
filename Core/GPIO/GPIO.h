/**
 ************************************************************************************************
 * @file           : GPIO.h
 * @author         : Kunal Salvi
 * @brief          : Header File for GPIO Driver
 ***********************************************************************************************
 * This is the header file for the GPIO driver and is to be called when a physical pin of the MCU
 * is to be configured.
 ************************************************************************************************
 */



#ifndef _GPIO_H_
#define _GPIO_H_

#include "main.h"


#define GEN_PUSH_PULL_OUTPUT   0b0011
#define GEN_OPEN_DRAIN_OUTPUT  0b0111
#define ALT_PUSH_PULL_OUTPUT   0b1011
#define ALT_OPEN_DRAIN_OUTPUT  0b1111
#define ANALOG_INPUT           0b0000
#define FLOATING_INPUT         0b0100
#define PULL_DOWN_INPUT        0b1000
#define PULL_UP_INPUT          0b1000
#define INPUT_MODE             0b0100

#define Rising_Edge     1
#define Falling_Ege     2
#define Rise_n_Fall_Edge 3


void GPIO_Pin_Setup(GPIO_TypeDef *Port, uint8_t pin, uint8_t function);

void GPIO_Interrupt_Setup(int pin, int edge_select);

#endif
