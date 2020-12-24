/*
 * main.c
 *
 *  Created on: Dec 23, 2020
 *      Author: Ahmed Ehab
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_macros.h"

#include "RCC_interface.h"
#include "RCC_macros.h"

#include "AFIO_interface.h"
#include "AFIO_macros.h"

#include "IR_interface.h"


u8 Data =0;
void PlayFunction(void)
{
	switch (Data)
	{
	case ZER0_BUTTON   :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN8,GPIO_U8_HIGH);break;
	case ONE_BUTTON    :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN9,GPIO_U8_HIGH);break;
	case TWO_BUTTON    :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN10,GPIO_U8_HIGH);break;
	case THREE_BUTTON  :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN11,GPIO_U8_HIGH);break;
	case FOUR_BUTTON   :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN12,GPIO_U8_HIGH);break;
	case FIVE_BUTTON   :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN13,GPIO_U8_HIGH);break;
	case SIX_BUTTON    :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN14,GPIO_U8_HIGH);break;
	case SEVEN_BUTTON  :MGPIO_VidSetPinValue(GPIO_U8_B,GPIO_U8_PIN15,GPIO_U8_HIGH);break;
	case POWER_BUTTON  :MGPIO_VidSetGpioValue(GPIO_U8_B,0);break;
	}
}





int main (void)
{

	/************RCC INIT**************/
	MRCC_VidInit();
	/************RCC ENABLE CLOCK************/
	MRCC_VidEnableClock(RCC_APB2,AFIO_RCC);
	MRCC_VidEnableClock(RCC_APB2,GPIOA_RCC);
	MRCC_VidEnableClock(RCC_APB2,GPIOB_RCC);
	 /************AFIO INIT**************/
	MAFIO_VidSelectExternalLine(EXT_U8_A,EXTI_LINE_U8_0);
	/***********SET PIN DIRCTION**********/
	MGPIO_VidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN0,GPIO_INPUT_FLOATING);
	MGPIO_VidSetGpioDirection(GPIO_U8_B,HALF_GPIO_OUTPUT_2MHZ_PP,GPIO_U8_HIGHREG);
	/***********IR INIT**********************/
	IR_VidInit(PlayFunction);
	while(1)
	{

	}
	return 0;

}
