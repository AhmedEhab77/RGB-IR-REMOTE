/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "AFIO_interface.h"
#include "AFIO_macros.h"
#include "AFIO_private.h"




void MAFIO_VidSelectExternalLine(u8 Copy_u8Port,u8 Copy_u8LineNum)
{
	if((Copy_u8LineNum <= EXTI_LINE_U8_15))
	{
		if((Copy_u8LineNum <= EXTI_LINE_U8_3))
		{
			AFIO->EXTICR1 	&=	~   ((0b1111)     <<  (Copy_u8LineNum * 4));
			AFIO->EXTICR1 	|=	   ((Copy_u8Port) <<  (Copy_u8LineNum * 4));
		}
		else if( (Copy_u8LineNum >= EXTI_LINE_U8_4) && (Copy_u8LineNum <= EXTI_LINE_U8_7))
		{
			Copy_u8LineNum-=4;
			AFIO->EXTICR2 	&=	~   ((0b1111)     <<  (Copy_u8LineNum * 4));
			AFIO->EXTICR2 	|=	   ((Copy_u8Port) <<  (Copy_u8LineNum * 4));
		}   
		else if( (Copy_u8LineNum >= EXTI_LINE_U8_8) && (Copy_u8LineNum <= EXTI_LINE_U8_11))
		{
			Copy_u8LineNum-=8;
			AFIO->EXTICR3 	&=	~   ((0b1111)     <<  (Copy_u8LineNum * 4));
			AFIO->EXTICR3 	|=	   ((Copy_u8Port) <<  (Copy_u8LineNum * 4));
		}
		else if( (Copy_u8LineNum >= EXTI_LINE_U8_12) && (Copy_u8LineNum <= EXTI_LINE_U8_15))
		{
			Copy_u8LineNum-=12;
			AFIO->EXTICR4 	&=	~   ((0b1111)     <<  (Copy_u8LineNum * 4));
			AFIO->EXTICR4 	|=	   ((Copy_u8Port) <<  (Copy_u8LineNum * 4));
		}
	}
}
