/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _SYSTICK_INTERFACE_H_
#define   _SYSTICK_INTERFACE_H_




void   MSysTick_VidInit(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_VidInit.								        **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Choosing the clock source of the SysTick	            **/
/*****************************************************************************/
void   MSysTick_VidSetBusyWaitDelay_ms(u32 Copy_u32Ticks);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_VidSetBusyWaitDelay_ms.                      **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: Desired time in ms                                    **/
/**	Functionality	: Function to delay time in ms using polling          	**/
/*****************************************************************************/
void   MSysTick_VidSetBusyWaitDelay_Ms(u32 Copy_u32Ticks);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_VidSetBusyWaitDelay_ms.                      **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: Desired time in ms                                    **/
/**	Functionality	: Function to delay time in ms using polling          	**/
/*****************************************************************************/
void   MSysTick_VidSetIntervalPeriodic(u32 Copy_u32Ticks,void (*Lpfunc)(void));
/********************************************************************************/
/********************************************************************************/
/**	Function Name	: MSysTick_VidSetIntervalPeriodic                          **/
/**	Return Type		: void					   		   		                   **/
/**	Arguments		: Number of ticks anld Pointer to function                 **/
/**	Functionality	: Function to delay time in ms using interrupt periodic**/
/********************************************************************************/
void   MSysTick_VidSetIntervalSingle(u32 Copy_u32Ticks,void (*Lpfunc)(void));
/********************************************************************************/
/********************************************************************************/
/**	Function Name	: MSysTick_VidSetIntervalPeriodic                          **/
/**	Return Type		: void					   		   		                   **/
/**	Arguments		: Number of ticks anld Pointer to function                 **/
/**	Functionality	: Function to delay time in ms using interrupt for one time**/
/********************************************************************************/
void   MSysTick_VidStopSystick(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_VidStopSystick        .                      **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Function to stop SysTick              	            **/
/*****************************************************************************/
u32    MSysTick_U32GetCountedTicks(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_U32GetCountedTicks.                          **/
/**	Return Type		: u32					   		   		                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Function to get counter ticks            	            **/
/*****************************************************************************/
u32    MSysTick_U32GetRemainingTicksToInterruptFunction(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	:  MSysTick_U32GetRemainingTicksToInterruptFunction     **/
/**	Return Type		: u32   		   		                                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Function to get remaining counts to reach zero        **/
/*****************************************************************************/
void   MSysTick_VidSartSystick(u32 Copy_u32Ticks);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MSysTick_VidStartSystick        .                      **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Function to start SysTick              	            **/
/*****************************************************************************/
#endif
