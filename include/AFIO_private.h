/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/
#ifndef   _AFIO_PRIVATE_H_
#define   _AFIO_PRIVATE_H_

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 MAPR2;
}AFIO_REG;


/**********************************************************/
#define        AFIO          ((volatile AFIO_REG*)0x40010000)
/**********************************************************/
#endif