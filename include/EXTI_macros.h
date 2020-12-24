/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _EXTI_MACROS_H_
#define   _EXTI_MACROS_H_


/*********************EXTERNAL LINES NUMBERS***********************/
typedef enum 
{
     EXTI_LINE_0,                            
     EXTI_LINE_1,                            
     EXTI_LINE_2,                            
     EXTI_LINE_3,                            
     EXTI_LINE_4,                            
     EXTI_LINE_5,                            
     EXTI_LINE_6,                            
     EXTI_LINE_7,                            
     EXTI_LINE_8,                            
     EXTI_LINE_9,                            
     EXTI_LINE_10,                            
     EXTI_LINE_11,                            
     EXTI_LINE_12,                            
     EXTI_LINE_13,                            
     EXTI_LINE_14,                            
     EXTI_LINE_15
}EXTI_LINES;
/********************************************************************/


/***OPTIONS OF CLOCK SOURCE***/
typedef enum{
   EXTI_FALLING  ,     
   EXTI_RISING   ,     
   EXTI_ON_CHANGE
}SENSE_MODES;   
/*****************************/







#endif
