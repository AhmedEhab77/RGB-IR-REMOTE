/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _EXTI_PRIVATE_H_
#define   _EXTI_PRIVATE_H_

typedef struct 
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_TYPE;

#define        EXTI          ((volatile EXTI_TYPE*)0x40010400)





#endif


