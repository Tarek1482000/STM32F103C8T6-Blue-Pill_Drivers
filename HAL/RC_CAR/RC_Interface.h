/*=================================================================================*/
/*  File        : RC_CAR_INTERFACE                                                 */
/*  Description : This Header file for RC_CAR_INTERFACE                            */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#ifndef HAL_RC_CAR_RC_INTERFACE_H_
#define HAL_RC_CAR_RC_INTERFACE_H_


#define START_DISTANCE     10
#define MINIMUM_DISTANCE   5
#define MAX_SPEED          80


void RC_Init(void);
void RC_Stop(void);

void RC_Forward(u8 speed);
void RC_Right(u8 speed);
void RC_Left(u8 speed);


void RC_Back(u8 speed);
void RC_Back_Right(u8 speed);
void RC_Back_Left(u8 speed);


#endif /* HAL_RC_CAR_RC_INTERFACE_H_ */
