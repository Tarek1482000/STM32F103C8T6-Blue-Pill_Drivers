/*=================================================================================*/
/*  File        : SERVO Program.c                                                  */
/*  Description : This Program file includes SERVO program                         */
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

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/TIMER1/TIMER1_interface.h"
#include "../../MCAL/GPT/GPT_interface.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

/*******************************************************************************
*                      Functions Definitions                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		SERVO_u8init
********************************************************************************/
u8 SERVO_u8init(SERVO_initStruct_t * Copy_PstrServoInit)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	GPIO_u8SetPinMode(Copy_PstrServoInit->SERVO_u8_PORT, Copy_PstrServoInit->SERVO_u8_PIN \
			, GPIO_u8_OUTPUT_AF_PP_50MHZ);
	switch(Copy_PstrServoInit->SERVO_u8_TIMER)
	{
	case TIMER_u8_1:
		TIMER1_u8InitPwmChannel(Copy_PstrServoInit->SERVO_u8_PWM_CHANNEL);
		break;

	case TIMER_u8_2:
	case TIMER_u8_3:
	case TIMER_u8_4:
		GPT_u8InitPwmChannel(Copy_PstrServoInit->SERVO_u8_TIMER, Copy_PstrServoInit->SERVO_u8_PWM_CHANNEL);
		break;

	default:
		Local_u8ErrorState = STD_TYPES_NOK;
		break;
	}

	return Local_u8ErrorState;
}

/*******************************************************************************
* Function Name:		SERVO_u8rotate
********************************************************************************/
u8 SERVO_u8rotate(SERVO_initStruct_t * Copy_PstrServoInit , u8 Copy_u8Angle)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(Copy_u8Angle >= SERVO_MIN_DEGREE && Copy_u8Angle <= SERVO_MAX_DEGREE)
	{
		f32 Local_f32DutyCycle = SERVO_MIN_DUTY + Copy_u8Angle * (((float)SERVO_MAX_DUTY-SERVO_MIN_DUTY) \
				/(SERVO_MAX_DEGREE - SERVO_MIN_DEGREE)) ;
		switch(Copy_PstrServoInit->SERVO_u8_TIMER)
		{
		case TIMER_u8_1:
			TIMER1_u8SetPWM(Copy_PstrServoInit->SERVO_u8_PWM_CHANNEL, SERVO_FREQUENCY, Local_f32DutyCycle);
			break;

		case TIMER_u8_2:
		case TIMER_u8_3:
		case TIMER_u8_4:
			GPT_u8SetPWM(Copy_PstrServoInit->SERVO_u8_TIMER, Copy_PstrServoInit->SERVO_u8_PWM_CHANNEL \
					, SERVO_FREQUENCY, Local_f32DutyCycle);
			break;

		default:
			Local_u8ErrorState = STD_TYPES_NOK;
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}

	return Local_u8ErrorState;
}
