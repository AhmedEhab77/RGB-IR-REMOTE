/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"


/***********************GLOBAL POINTER TO FUNCTION****************/
static   void (*Gpfunc) (void)=NULL;
/*****************************************************************/
/*********************SOFTWARE GLOBAL FLAG************************/
static volatile u8 Sys_u8IntervalFlag=0;
/*****************************************************************/
/*********************GLOBAL VARIABLES************************/
static  volatile u8 Loc_u8Temp=0;
/*****************************************************************/

void   MSysTick_VidInit(void)
{
	/*******CHOOSING CLOCK SOURCE--DISABLE ALL SysTick SYSTEM AT FIRST******************/
	#if      MSYSTICK_CLOCK_SOURCE == MSYSTICK_SOURCE_AHB
	Sys -> CTRL=0x00000004;
	#elif    MSYSTICK_CLOCK_SOURCE == MSYSTICK_SOURCE_AHB_8
	Sys -> CTRL=0x00000000;
	#endif
	/************************************************************************************/	
}


void   MSysTick_VidSetBusyWaitDelay_Ms(u32 Copy_u32Ticks)
{
	/*****************LOAD DESIRED TICKS AT LOAD REG ***************/
	Sys -> LOAD = Copy_u32Ticks;
	/****************START THE SYSTICK COUNT************************/
	SET_BIT(Sys -> CTRL,0);
	/****************POLLING ON FLAG********************************/
	while (GET_BIT(Sys -> CTRL,16) != 1);
	/***************STOP THE SYSTICK *******************************/
	CLR_BIT(Sys -> CTRL,0);
	Sys -> LOAD =0;
	Sys -> VALUE =0;
}

void   MSysTick_VidSetBusyWaitDelay_ms(u32 Copy_u32Ticks)
{
	/*****************LOAD DESIRED TICKS AT LOAD REG ***************/
	Sys -> LOAD = Copy_u32Ticks * 1000 ;
	/****************START THE SYSTICK COUNT************************/
	SET_BIT(Sys -> CTRL,0);
	/****************POLLING ON FLAG********************************/
	while (GET_BIT(Sys -> CTRL,16) != 1);
	/***************STOP THE SYSTICK *******************************/
	CLR_BIT(Sys -> CTRL,0);
	Sys -> LOAD =0;
	Sys -> VALUE =0;
}

void   MSysTick_VidSetIntervalSingle(u32 Copy_u32Ticks,void (*Lpfunc)(void))
{
	/*****************MAKE VALUE = 0 *****************************/
	Sys -> VALUE = 0;
	/*****************LOAD DESIRED TICKS AT LOAD REG ***************/
	Sys -> LOAD = Copy_u32Ticks;
    /****************START THE SYSTICK COUNT************************/
    SET_BIT(Sys -> CTRL,0);
	/********************ASSIGN LP_FUNCTION TO GP_FUNCTION**********/
	Gpfunc=Lpfunc;
	/*********************SET INTERVAL MODE*************************/
	 Sys_u8IntervalFlag=0;	
	/********************ENABLE SYSTICK INTERRUPT*******************/
	SET_BIT(Sys -> CTRL,1);
	
}




void   MSysTick_VidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Lpfunc)(void))
{
	/*****************LOAD DESIRED TICKS AT LOAD REG ***************/
	Sys -> LOAD = Copy_u32Ticks;
   /****************START THE SYSTICK COUNT*************************/
    SET_BIT(Sys -> CTRL,0);
	/********************ASSIGN LP_FUNCTION TO GP_FUNCTION**********/
	Gpfunc=Lpfunc;
	/*********************SET INTERVAL MODE*************************/
	Sys_u8IntervalFlag=1;	
	/********************ENABLE SYSTICK INTERRUPT*******************/
	SET_BIT(Sys -> CTRL,1);
	
}


void   MSysTick_VidStopSystick(void)
{
	/******************STOP THE SYSTICK ******************************/
	CLR_BIT(Sys -> CTRL,0);
	Sys -> LOAD =0;
	Sys -> VALUE =0;
}
void   MSysTick_VidSartSystick(u32 Copy_u32Ticks)
{

	/*****************LOAD DESIRED TICKS AT LOAD REG ***************/
    Sys -> LOAD = Copy_u32Ticks;
	Sys -> VALUE =0;
	 /****************START THE SYSTICK COUNT*************************/
	SET_BIT(Sys -> CTRL,0);
}


u32  MSysTick_U32GetCountedTicks(void)
{
	u32 Copy_u32ReturnValue=0;
	Copy_u32ReturnValue= ((Sys -> LOAD) - (Sys -> VALUE));
	return Copy_u32ReturnValue;	
}


u32  MSysTick_U32GetRemainingTicksToInterruptFunction(void)
{
	u32 Copy_u32ReturnValue=0;
	Copy_u32ReturnValue= (Sys -> VALUE);
	return Copy_u32ReturnValue;
}

/********************SysTick ISR FUNCTION***********************/
void SysTick_Handler(void)
{

	if(Sys_u8IntervalFlag == 0)
	{

		/***************STOP THE SYSTICK ******************************/
		CLR_BIT(Sys -> CTRL,0);
		Sys -> LOAD =0;
		Sys -> VALUE =0;
		/*****************CALLBACK FUNCTION NOTIFICATION*************/
		Gpfunc();	
		/****************CLEARING FLAG BY READING ONLY THE FLAG**************************/
		 Loc_u8Temp = (GET_BIT(Sys -> CTRL,16));
	}
	else if (Sys_u8IntervalFlag == 1)
	{
		Gpfunc();
	}
	
}
