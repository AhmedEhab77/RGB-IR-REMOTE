/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _GPIO_PRIVATE_H_
#define   _GPIO_PRIVATE_H_



typedef struct
{
	volatile u32 CRL  ;
	volatile u32 CRH  ;
	volatile u32 IDR  ;
	volatile u32 ODR  ;
	volatile u32 BSRR ;
	volatile u32 BRR  ;
	volatile u32 LCKR ;
}GPIO_REG;

   /*********************GPIOS BASE ADRESSES*****************/
#define    GPIOA_BASE_ADDRESS             0x40010800
#define    GPIOB_BASE_ADDRESS             0x40010C00
#define    GPIOC_BASE_ADDRESS             0x40011000
   /*********************************************************/
   
   /*****************************************************************/
#define        GPIOA          ((volatile GPIO_REG*)GPIOA_BASE_ADDRESS)
#define        GPIOB          ((volatile GPIO_REG*)GPIOB_BASE_ADDRESS)
#define        GPIOC          ((volatile GPIO_REG*)GPIOC_BASE_ADDRESS)
/********************************************************************/


/*****************************************************************/
#define        GPIOA_CR          *((volatile u64*)GPIOA_BASE_ADDRESS)
#define        GPIOB_CR          *((volatile u64*)GPIOB_BASE_ADDRESS)
#define        GPIOC_CR          *((volatile u64*)GPIOC_BASE_ADDRESS)
/******************************************************************/








   






#endif
