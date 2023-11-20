/*=================================================================================*/
/*  File        : MOTOR_Private                                                    */
/*  Description : This Header file for MOTOR_Private                               */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef HAL_MOTOR_DRIVER_MOTOR_PRIVATE_H_
#define HAL_MOTOR_DRIVER_MOTOR_PRIVATE_H_


void Motor1_Forward(void);
void Motor2_Forward(void);

void Motor1_Back(void);
void Motor2_Back(void);

void Motor1_Stop(void);
void Motor2_Stop(void);

void Motor1_Speed(u8 speed);
void Motor2_Speed(u8 speed);

#endif /* HAL_MOTOR_DRIVER_MOTOR_PRIVATE_H_ */
