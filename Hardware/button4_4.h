#ifndef __BUTTON4_4_H
#define	__BUTTON4_4_H
#include "stm32f10x.h"
#include "delay.h"
#include "math.h"

#define		BUTTON_GPIO_CLK										RCC_APB2Periph_GPIOA
#define 	BUTTON_ROW1_GPIO_PORT								GPIOB
#define 	BUTTON_ROW1_GPIO_PIN							    GPIO_Pin_12
#define 	BUTTON_ROW2_GPIO_PORT								GPIOB
#define 	BUTTON_ROW2_GPIO_PIN								GPIO_Pin_13
#define 	BUTTON_ROW3_GPIO_PORT								GPIOB
#define 	BUTTON_ROW3_GPIO_PIN								GPIO_Pin_14
#define 	BUTTON_ROW4_GPIO_PORT								GPIOB
#define 	BUTTON_ROW4_GPIO_PIN								GPIO_Pin_15

#define 	BUTTON_COL1_GPIO_PORT								GPIOA
#define 	BUTTON_COL1_GPIO_PIN								GPIO_Pin_8
#define 	BUTTON_COL2_GPIO_PORT								GPIOA
#define 	BUTTON_COL2_GPIO_PIN								GPIO_Pin_9
#define 	BUTTON_COL3_GPIO_PORT								GPIOA
#define 	BUTTON_COL3_GPIO_PIN								GPIO_Pin_10
#define 	BUTTON_COL4_GPIO_PORT								GPIOA
#define 	BUTTON_COL4_GPIO_PIN								GPIO_Pin_11

	
/*********************END**********************/

void Button4_4_Init(void);
int Button4_4_Scan(void);

#endif
