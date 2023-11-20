/*=================================================================================*/
/*  File        : NVIC_Program.c                                                   */
/*  Description : This Program file includes NVIC program for STM32f103C8T6        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


/*******************************************************************************
*                        		Inclusions                                     *
*******************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stm32f103xx.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		NVIC_u8EnableInterrupt
********************************************************************************/
u8 NVIC_u8EnableInterrupt(u8 Copy_u8InterruptNumber)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber <= 31)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ISER[0] = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 43)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ISER[1] = (1 << (Copy_u8InterruptNumber-32));
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8DisableInterrupt
********************************************************************************/
u8 NVIC_u8DisableInterrupt(u8 Copy_u8InterruptNumber)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber < 32)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ICER[0] = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 43)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ICER[1] = (1 << (Copy_u8InterruptNumber-32));

	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8SetInterruptPending
********************************************************************************/
u8 NVIC_u8SetInterruptPending(u8 Copy_u8InterruptNumber)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber < 32)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ISPR[0] = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 43)
	{
		LocalErrorState = STD_TYPES_OK;
		Copy_u8InterruptNumber -= 32 ;
		NVIC->ISPR[1] = (1 << (Copy_u8InterruptNumber-32));
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8SClearInterruptPending
********************************************************************************/
u8 NVIC_u8SClearInterruptPending(u8 Copy_u8InterruptNumber)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber <= 31)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->ICPR[0] = (1 << Copy_u8InterruptNumber);
	}
	else if(Copy_u8InterruptNumber < 43)
	{
		LocalErrorState = STD_TYPES_OK;
		Copy_u8InterruptNumber -= 32 ;
		NVIC->ICPR[1] = (1 << (Copy_u8InterruptNumber-32));
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8InterruptIsActive
********************************************************************************/
u8 NVIC_u8InterruptIsActive(u8 Copy_u8InterruptNumber, u8* Copy_pu8InterruptStatus)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_pu8InterruptStatus != NULL)
	{
		if(Copy_u8InterruptNumber < 32)
		{
			LocalErrorState = STD_TYPES_OK;
			* Copy_pu8InterruptStatus = GET_BIT(NVIC->IABR[0],Copy_u8InterruptNumber);
		}
		else if(Copy_u8InterruptNumber < 43)
		{
			LocalErrorState = STD_TYPES_OK;
			Copy_u8InterruptNumber -= 32 ;
			* Copy_pu8InterruptStatus = GET_BIT(NVIC->IABR[1],Copy_u8InterruptNumber);
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8SetGroupPriority
********************************************************************************/
u8 NVIC_u8SetGroupPriority(u8 Copy_u8InterruptNumber,u8 Copy_u8GroupPriority)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber < 60 && Copy_u8GroupPriority < 16)
	{
		LocalErrorState = STD_TYPES_OK;
		u8 Local_RegisterNumber = Copy_u8InterruptNumber / 4 ;
		u8 Local_InterruptByte  = Copy_u8InterruptNumber % 4 ;

		SCB_AIRCR = (0xFA05<<16) | (NVIC_u8_GROUPING<<8) ;
		NVIC->IPR[Local_RegisterNumber] &= ~(0b1111<<(Local_InterruptByte * 8 + 4));
		NVIC->IPR[Local_RegisterNumber] |= (Copy_u8GroupPriority<<(Local_InterruptByte * 8 + 4));
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}

/*******************************************************************************
* Function Name:		NVIC_u8GenerateSWInerrupt
********************************************************************************/
u8 NVIC_u8GenerateSWInerrupt(u8 Copy_u8InterruptNumber)
{
	u8 LocalErrorState = STD_TYPES_NOK;

	if(Copy_u8InterruptNumber < 43)
	{
		LocalErrorState = STD_TYPES_OK;
		NVIC->STIR = Copy_u8InterruptNumber;
	}
	else
	{
		/* Do Nothing */
	}

	return LocalErrorState;
}
