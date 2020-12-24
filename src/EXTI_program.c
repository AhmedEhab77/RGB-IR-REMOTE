/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "EXTI_macros.h"
#include "EXTI_private.h"

/**GLOBAL ARRAY POINTER TO FUNCTION**/
static void (*Gpfunc[16])(void)={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
/*******************************/

void MEXTI_VidSetSenseMode(u8 Copy_u8SenseMode,u8 Copy_u8LineId)               
{
	/******************TRIGGER SOURCE****************/
	switch (Copy_u8SenseMode)
	{
		case EXTI_FALLING   :SET_BIT(EXTI->FTSR,Copy_u8LineId);
		                     CLR_BIT(EXTI->RTSR,Copy_u8LineId); break;
							 
		case EXTI_RISING    :SET_BIT(EXTI->RTSR,Copy_u8LineId);
                             CLR_BIT(EXTI->FTSR,Copy_u8LineId); break;
							 
		case EXTI_ON_CHANGE :SET_BIT(EXTI->FTSR,Copy_u8LineId);
                             SET_BIT(EXTI->RTSR,Copy_u8LineId); break;

	}
	      
  /*******ENABLE INTERRUPT LINE*******/
	CLR_BIT(EXTI->IMR ,Copy_u8LineId);	
}

void MEXTI_VidEnable (u8 Copy_u8LineId)
{
	SET_BIT(EXTI->IMR ,Copy_u8LineId);
}
void MEXTI_VidDisable(u8 Copy_u8LineId)
{
	CLR_BIT(EXTI->IMR ,Copy_u8LineId);
}
void MEXTI_VidSetSoftwareTrigger(u8 Copy_u8LineId)
{
	SET_BIT(EXTI->SWIER ,Copy_u8LineId);
}
void MEXTI_VidSetCallBack(void (*Lpfunc)(void) , u8 Copy_u8ExternalId)
{
	Gpfunc[Copy_u8ExternalId]=Lpfunc;
}
void EXTI0_IRQHandler(void)    
{
	if(Gpfunc[0] != NULL)
	{
	Gpfunc[0]();
	SET_BIT(EXTI->PR ,EXTI_LINE_0);
	}
}
void EXTI1_IRQHandler(void)    
{
	if(Gpfunc[1] != NULL)
	{
    Gpfunc[1]();
    SET_BIT(EXTI->PR ,EXTI_LINE_1);
    }
}


   

