/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_macros.h"
#include "GPIO_private.h"
#include "GPIO_config.h"





void MGPIO_VidSetPinDirection(u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8 Copy_u8Mode)
{
	/*****Check The Range Of GPIO and PinNum******/
	if(Copy_u8Gpio <= GPIO_U8_C && Copy_u8PinNum <= GPIO_U8_PIN15 )
	{
		switch (Copy_u8Gpio)
		{
			case GPIO_U8_A:
			if(Copy_u8PinNum < GPIO_U8_PIN8)
			{
			/*************BIT MASKING 4BITS FOR THE USED PIN************/	
			GPIOA->CRL 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
			/*************CHOOSING THE MODE OF PIN************/
			GPIOA->CRL 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
			}
			else if (Copy_u8PinNum >= GPIO_U8_PIN8 && Copy_u8PinNum <= GPIO_U8_PIN15)
			{
			Copy_u8PinNum-=8;
			/*************BIT MASKING 4BITS FOR THE USED PIN************/
			GPIOA->CRH 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
            /*************CHOOSING THE MODE OF PIN************/			
			GPIOA->CRH 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
			}
			break;
			
			case GPIO_U8_B:
			if(Copy_u8PinNum < GPIO_U8_PIN8)
			{
			/*************BIT MASKING 4BITS FOR THE USED PIN************/
			GPIOB->CRL 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
			/*************CHOOSING THE MODE OF PIN************/
			GPIOB->CRL 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
            }
            else if (Copy_u8PinNum >= GPIO_U8_PIN8 && Copy_u8PinNum <= GPIO_U8_PIN15)
            {
            Copy_u8PinNum-=8;
            /*************BIT MASKING 4BITS FOR THE USED PIN************/			
            GPIOB->CRH 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
			/*************CHOOSING THE MODE OF PIN************/
            GPIOB->CRH 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
            }	
			break;
			
			case GPIO_U8_C:
		   if(Copy_u8PinNum < GPIO_U8_PIN8)
		   {
			/*************BIT MASKING 4BITS FOR THE USED PIN************/   
		   GPIOC->CRL 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
		   /*************CHOOSING THE MODE OF PIN************/
		   GPIOC->CRL 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
		   }
		   else if (Copy_u8PinNum >= GPIO_U8_PIN8 && Copy_u8PinNum <= GPIO_U8_PIN15)
		   {
		   Copy_u8PinNum-=8;
			/*************BIT MASKING 4BITS FOR THE USED PIN************/
		   GPIOC->CRH 	&=	~((0b1111) <<  (Copy_u8PinNum * 4));
		   /*************CHOOSING THE MODE OF PIN************/
		   GPIOC->CRH 	|=	((Copy_u8Mode) << (Copy_u8PinNum * 4));
		   }
		   break;
		}
	}
}

void MGPIO_VidSetPinValue(u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8 Copy_u8State)
{
	if(Copy_u8Gpio <= GPIO_U8_C && Copy_u8PinNum <= GPIO_U8_PIN15 )
	{
	        switch (Copy_u8Gpio)
	        {
	        	case GPIO_U8_A:
	        	switch (Copy_u8State)
	        	{
	        		case GPIO_U8_HIGH    :GPIOA->BSRR= (1<<Copy_u8PinNum);break;
	        		case GPIO_U8_LOW	 :GPIOA->BRR = (1<<Copy_u8PinNum);break;
	        	}
	        	break;
	        	case GPIO_U8_B:
	        	switch (Copy_u8State)
	        	{
	        		case GPIO_U8_HIGH    :GPIOB->BSRR= (1<<Copy_u8PinNum);break;
	        		case GPIO_U8_LOW	 :GPIOB->BRR = (1<<Copy_u8PinNum);break;
	        	}
	        	break;
	        	case GPIO_U8_C:
	        	switch (Copy_u8State)
	        	{
	        		case GPIO_U8_HIGH   :GPIOC->BSRR= (1<<Copy_u8PinNum);break;
	        		case GPIO_U8_LOW	:GPIOC->BRR = (1<<Copy_u8PinNum);break;
	        	}
	        	break;
	        }
	}
}
void   GPIO_VidGetPinValue(u8 Copy_u8Gpio,u8 Copy_u8PinNum,u8*P_res)
{
	if(Copy_u8Gpio <= GPIO_U8_C)
	{
	    switch (Copy_u8Gpio)
	    {
	    	case GPIO_U8_A:*P_res=( (GPIOA->IDR>>Copy_u8PinNum)&1 );
	    	break;                        
	    	case GPIO_U8_B:*P_res=( (GPIOB->IDR>>Copy_u8PinNum)&1 );
	    	break;                        
	    	case GPIO_U8_C:*P_res=( (GPIOC->IDR>>Copy_u8PinNum)&1 );
        	break;
	    }
	}		
}

void MGPIO_VidSetGpioDirection(u8 Copy_u8Gpio,u64 Copy_u64Value,u8 Copy_u8State)
{
	if(Copy_u8Gpio <= GPIO_U8_C)                                      	
	{				
		switch(Copy_u8State)
		{
			case GPIO_U8_FULLREG:
			switch(Copy_u8Gpio)
			{
				case GPIO_U8_A:GPIOA_CR=Copy_u64Value; break;
				case GPIO_U8_B:GPIOB_CR=Copy_u64Value; break;
				case GPIO_U8_C:GPIOC_CR=Copy_u64Value; break;
			}
			break;
			case GPIO_U8_LOWREG:
			switch(Copy_u8Gpio)
			{
				case GPIO_U8_A:GPIOA->CRL=Copy_u64Value; break;
				case GPIO_U8_B:GPIOB->CRL=Copy_u64Value; break;
				case GPIO_U8_C:GPIOC->CRL=Copy_u64Value; break;
			}
			break;
			case GPIO_U8_HIGHREG:
			switch(Copy_u8Gpio)
			{
				case GPIO_U8_A:GPIOA->CRH=(u32)Copy_u64Value; break;
				case GPIO_U8_B:GPIOB->CRH=(u32)Copy_u64Value; break;
				case GPIO_U8_C:GPIOC->CRH=(u32)Copy_u64Value; break;
			}
			break;	
		}
	    
	}
}

void MGPIO_VidSetGpioValue(u8 Copy_u8Gpio,u32 Copy_u32Value)
{
	if(Copy_u8Gpio <= GPIO_U8_C)
	{
	    switch (Copy_u8Gpio)
	    {
	    	case GPIO_U8_A: GPIOA->ODR=Copy_u32Value;
	    	break;                     
	    	case GPIO_U8_B: GPIOB->ODR=Copy_u32Value;
	    	break;                     
	    	case GPIO_U8_C: GPIOC->ODR=Copy_u32Value;
	    	break;
	    }
	}
}

	
	
	
    	
		
		
		
		

		
	
	
	
	
	
	
	
	
	







