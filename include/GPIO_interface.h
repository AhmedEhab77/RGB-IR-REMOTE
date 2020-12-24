/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _GPIO_INTERFACE_H_
#define   _GPIO_INTERFACE_H_

void MGPIO_VidSetPinDirection(u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8 Copy_u8Mode);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MGPIO_VidSetPinDirection.								**/
/**	Return Type		: void.					   		   		                **/
/**	Arguments		: Gpio,Pin number and Status(Output or Input + Config ) **/
/**	Functionality	: Setting the dirction of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/

void MGPIO_VidSetPinValue     (u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8 Copy_u8State);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MGPIO_VidSetPinValue								    **/
/**	Return Type		: void.					   		   		                **/
/**	Arguments		: Gpio , Pin number and Status(HIGH or LOW).	        **/
/**	Functionality	: Setting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/

void MGPIO_VidGetPinValue     (u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8*P_res);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MGPIO_VidGetPinValue.								    **/
/**	Return Type		: void.					   		   		                **/
/**	Arguments		: Gpio,Pin number and Pointer has the return of func    **/
/**	Functionality	: Getting the value of specific pin at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/

void MGPIO_VidSetGpioValue(u8 Copy_u8Gpio,u32 Copy_u32Value);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MGPIO_VidSetGpioValue								    **/
/**	Return Type		: void.					   		   		                **/
/**	Arguments		: Gpio number,Value of the whole Port                	**/
/**	Functionality	: Setting the value of specific port at run time.	    **/
/*****************************************************************************/
/*****************************************************************************/

void MGPIO_VidSetGpioDirection(u8 Copy_u8Gpio,u64 Copy_u64Value,u8 Copy_u8State);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MGPIO_VidSetGpioDirection							    **/
/**	Return Type		: void.					   		   		                **/
/**	Arguments		: Gpio number,Value of the whole Port,Long of accessing **/
/**	Functionality	: Setting the direction of specific port at run time.   **/
/*****************************************************************************/
/*****************************************************************************/


#endif