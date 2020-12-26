/*************************************************/
/**               AUTHOR : AHMED EHAB           **/
/**               VERSION : V0.1                **/
/*************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_macros.h"

#include "NVIC_interface.h"
#include "NVIC_macros.h"

#include "SYSTICK_interface.h"
#include "IR_config.h"


/***********GLOBAL VARIABLES********/
 volatile u8 StartFlag=0;
 volatile u8 FrameData=0;
 volatile u8 Counter=0;
 volatile u32 ArrayFrame[33]={0};
 static void  (*Gpfunction)  (void)=NULL;
 static u8 *Gp=NULL;
/***********************************/

void ActionSystick(void)
{
	/*********CHECK THE RANGE OF START BIT***********/
	if((ArrayFrame[0] >=900) && (ArrayFrame[0] <=14000) )
		{
		   for(u8 i=0; i<8 ;i++)
		    {
		    	if(ArrayFrame[17+i] >= 2000)
		    	{
		    		SET_BIT(FrameData,i);
		    	}
		    }
		   *Gp=FrameData;
		   Gpfunction();
			/******RESET VALUES*******/
			StartFlag=0;
			FrameData=0;
			Counter=0;
			ArrayFrame[0]=0;
			/************************/
		}
}

void Get_IRFrame(void)
{
	if(StartFlag == 0)
	{
		MSysTick_VidSetIntervalSingle(SYSTICK_TICKS,ActionSystick);
		StartFlag=1;
	}
	else if(StartFlag == 1)
	{
		ArrayFrame[Counter]=MSysTick_U32GetCountedTicks();
		MSysTick_VidSetIntervalSingle(SYSTICK_TICKS,ActionSystick);
		Counter++;
	}
}

void IR_VidInit(void  (*Pfuction)  (void),u8*Pf)
{
	Gpfunction=Pfuction;
	Gp=Pf;
	/**********EXTI SET CALL BACK ******/
	MEXTI_VidSetCallBack(Get_IRFrame,EXTI_LINE_0);
	/**********SYSTICK SET CALL BACK ******/
	MSysTick_VidSetIntervalSingle(SYSTICK_TICKS,ActionSystick);
	/************SYSTICK INIT**************/
	MSysTick_VidInit();
    /************EXTI INIT**************/
	MEXTI_VidSetSenseMode(EXTI_FALLING,EXTI_LINE_0);
	/************NVIC INIT***************/
	MNVIC_VidInit();
	/***********EXTI ENABLE**************/
	MEXTI_VidEnable(EXTI_LINE_0);
	/***********NVIC ENABLE**************/
	MNVIC_u8Enable(VECT_EXTI0);
}




