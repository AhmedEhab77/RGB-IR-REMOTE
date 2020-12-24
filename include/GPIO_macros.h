/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _GPIO_MACROS_H_
#define   _GPIO_MACROS_H_



  /******************GPIO PINS************/
  typedef enum
  {
 			GPIO_U8_PIN0,				
 			GPIO_U8_PIN1,				
 			GPIO_U8_PIN2,				
 			GPIO_U8_PIN3,				
 			GPIO_U8_PIN4,				
 			GPIO_U8_PIN5,				
 			GPIO_U8_PIN6,				
 			GPIO_U8_PIN7,				
 			GPIO_U8_PIN8,				
 			GPIO_U8_PIN9,				
 			GPIO_U8_PIN10,				
 			GPIO_U8_PIN11,				
 			GPIO_U8_PIN12,				
 			GPIO_U8_PIN13,				
 			GPIO_U8_PIN14,				
 			GPIO_U8_PIN15
  }GPIO_PINS;			
  /****************************************/
  
  /*******************GPIOS****************/
  #define			GPIO_U8_A					0
  #define			GPIO_U8_B					1
  #define			GPIO_U8_C					2
 /*****************************************/
 
  /*******************MODES OF INPUT **********/
#define			GPIO_INPUT_ANALOG			0b0000
#define			GPIO_INPUT_FLOATING			0b0100
#define			GPIO_INPUT_PULL_UP_DOWN		0b1000
 /*******************************************/
 
  /*******************MODES OF OUTPUT 10MHZ **********/
#define			GPIO_OUTPUT_10MHZ_PP		0b0001
#define			GPIO_OUTPUT_10MHZ_OD		0b0101
#define			GPIO_OUTPUT_10MHZ_AFPP		0b1001
#define			GPIO_OUTPUT_10MHZ_AFOD		0b1101
 /*****************************************/
 
   /*******************MODES OF OUTPUT 2MHZ **********/
#define			GPIO_OUTPUT_2MHZ_PP		    0b0010
#define			GPIO_OUTPUT_2MHZ_OD		    0b0110
#define			GPIO_OUTPUT_2MHZ_AFPP		0b1010
#define			GPIO_OUTPUT_2MHZ_AFOD		0b1110
 /*****************************************/
 
   /*******************MODES OF OUTPUT 50MHZ **********/
#define			GPIO_OUTPUT_50MHZ_PP		0b0011
#define			GPIO_OUTPUT_50MHZ_OD		0b0111
#define			GPIO_OUTPUT_50MHZ_AFPP		0b1011
#define			GPIO_OUTPUT_50MHZ_AFOD		0b1111
 /*****************************************/
	 
	   /*******************MODES OF GPIO PIN **********/
 #define	        GPIO_U8_HIGH				1
 #define			GPIO_U8_LOW					0
     /*****************************************/


	/********************MODES OF ACCESSING WHOLE REG****************/
#define			ALL_GPIO_OUTPUT_10MHZ_PP		0x1111111111111111
#define			ALL_GPIO_OUTPUT_10MHZ_OD		0x5555555555555555
#define			ALL_GPIO_OUTPUT_10MHZ_AFPP		0x9999999999999999
#define			ALL_GPIO_OUTPUT_10MHZ_AFOD		0xDDDDDDDDDDDDDDDD

#define			HALF_GPIO_OUTPUT_10MHZ_PP 		0x11111111
#define			HALF_GPIO_OUTPUT_10MHZ_OD		0x55555555
#define		    HALF_GPIO_OUTPUT_10MHZ_AFPP		0x99999999
#define		    HALF_GPIO_OUTPUT_10MHZ_AFOD		0xDDDDDDDD



#define			ALL_GPIO_OUTPUT_2MHZ_PP		    0x2222222222222222
#define			ALL_GPIO_OUTPUT_2MHZ_OD		    0x6666666666666666
#define			ALL_GPIO_OUTPUT_2MHZ_AFPP		0xAAAAAAAAAAAAAAAA
#define			ALL_GPIO_OUTPUT_2MHZ_AFOD		0xEEEEEEEEEEEEEEEE

#define			HALF_GPIO_OUTPUT_2MHZ_PP		0x22222222
#define			HALF_GPIO_OUTPUT_2MHZ_OD		0x66666666
#define			HALF_GPIO_OUTPUT_2MHZ_AFPP		0xAAAAAAAA
#define			HALF_GPIO_OUTPUT_2MHZ_AFOD		0xEEEEEEEE

	
#define			ALL_GPIO_OUTPUT_50MHZ_PP		0x3333333333333333
#define			ALL_GPIO_OUTPUT_50MHZ_OD		0x7777777777777777
#define			ALL_GPIO_OUTPUT_50MHZ_AFPP		0xBBBBBBBBBBBBBBBB
#define			ALL_GPIO_OUTPUT_50MHZ_AFOD		0xFFFFFFFFFFFFFFFF

#define			HALF_GPIO_OUTPUT_50MHZ_PP		0x33333333
#define			HALF_GPIO_OUTPUT_50MHZ_OD		0x77777777
#define			HALF_GPIO_OUTPUT_50MHZ_AFPP		0xBBBBBBBB
#define			HALF_GPIO_OUTPUT_50MHZ_AFOD		0xFFFFFFFF

/*****************************************************************/

/***********************MODES OF GPIO DIRCTION STATE***************/
 #define			GPIO_U8_FULLREG					0
 #define			GPIO_U8_LOWREG					1
 #define			GPIO_U8_HIGHREG					2
 /*****************************************************************/





#endif
