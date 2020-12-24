/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _EXTI_INTERFACE_H_
#define   _EXTI_INTERFACE_H_



void MEXTI_VidSetSenseMode(u8 Copy_u8SenseMode,u8 Copy_u8LineId);
/*******************************************************************************/
/*******************************************************************************/
/**	Function Name	: MEXTI_VidSetSenseMode.								  **/
/**	Return Type		: void.					   		   		                  **/
/**	Arguments		: SenseMode(FallingOrRising,External Line Num From 0 to 15**/
/**	Functionality	: Selecting the sense mode of specific line at run time ****/
/*******************************************************************************/
/*******************************************************************************/
void MEXTI_VidEnable (u8 Copy_u8LineId);
/*******************************************************************************/
/*******************************************************************************/
/**	Function Name	: MEXTI_VidEnable.								          **/
/**	Return Type		: void.					   		   		                  **/
/**	Arguments		: External Line Num From 0 to 15                          **/
/**	Functionality	: Enabling the external interrupt for specific line     ****/
/*******************************************************************************/
/*******************************************************************************/
void MEXTI_VidDisable(u8 Copy_u8LineId);
/*******************************************************************************/
/*******************************************************************************/
/**	Function Name	: MEXTI_VidDisable.								          **/
/**	Return Type		: void.					   		   		                  **/
/**	Arguments		: External Line Num From 0 to 15                          **/
/**	Functionality	: Disabling the external interrupt for specific line     ****/
/*******************************************************************************/
/*******************************************************************************/
void MEXTI_VidSetSoftwareTrigger(u8 Copy_u8LineId);
/*******************************************************************************/
/*******************************************************************************/
/**	Function Name	: MEXTI_VidSetSoftwareTrigger.						      **/
/**	Return Type		: void.					   		   		                  **/
/**	Arguments		: External Line Num From 0 to 15                          **/
/**	Functionality	: Making software interrupt using extrnal lines         ****/
/*******************************************************************************/
/*******************************************************************************/
void MEXTI_VidSetCallBack(void (*Lpfunc)(void) , u8 Copy_u8ExternalId);
/*******************************************************************************/
/*******************************************************************************/
/**	Function Name	: MEXTI_VidSetCallBack.						              **/
/**	Return Type		: void.					   		   		                  **/
/**	Arguments		: Local pointer to isr function and external id           **/
/**	Functionality	: Making the call of ISR func in main                   ****/
/*******************************************************************************/
/*******************************************************************************/

#endif

