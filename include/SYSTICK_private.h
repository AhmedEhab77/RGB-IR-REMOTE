/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _SYSTICK_PRIVATE_H_
#define   _SYSTICK_PRIVATE_H_


typedef struct 
{
	u32 volatile CTRL  ;
	u32 volatile LOAD  ;
	u32 volatile VALUE ;
	u32 volatile CALIB ;

}SYSTICK_REG;

#define           Sys                      ((SYSTICK_REG*)(0xE000E010))



/************************SYSTICK CLOCK SOURCE******************/
#define        MSYSTICK_SOURCE_AHB                      0
#define        MSYSTICK_SOURCE_AHB_8                    1
/**************************************************************/

#endif



