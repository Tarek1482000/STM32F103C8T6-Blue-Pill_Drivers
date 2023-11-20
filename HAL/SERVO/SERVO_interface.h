/*=================================================================================*/
/*  File        : SERVO_interface.h                                                */
/*  Description : This Header file includes Servo_interface                        */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/*******************************************************************************
*                        		Definitions                                    *
*******************************************************************************/

/*******************************************************************************
*                         Types Declaration                                   *
*******************************************************************************/

/*******************************************************************************
* Name: SERVO
* Type: Structure
* Description: Data type to get the response of the ESP
********************************************************************************/
typedef struct
{
	u8 SERVO_u8_PORT;
	u8 SERVO_u8_PIN;
	u8 SERVO_u8_TIMER;
	u8 SERVO_u8_PWM_CHANNEL;
}SERVO_initStruct_t;

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*******************************************************************************
* Function Name:		SERVO_u8init
* Description:			Function to initialize the servo
* Parameters (in):    	pointer to the servo init structure
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 SERVO_u8init(SERVO_initStruct_t * Copy_PstrServoInit);

/*******************************************************************************
* Function Name:		SERVO_u8rotate
* Description:			Function to rotate the servo with required angle
* Parameters (in):    	pointer the servo structure and the required angle
* Parameters (out):   	u8
* Return value:      	OK or Error
********************************************************************************/
u8 SERVO_u8rotate(SERVO_initStruct_t * Copy_PstrServoInit , u8 Copy_u8Angle);

#endif /* SERVO_INTERFACE_H_ */
