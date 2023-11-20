/*=================================================================================*/
/*  File        : NVIC_config.h                                                    */
/*  Description : This Header file includes NVIC_config for STM32f103C8T6          */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                       */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*******************************************************************************
*                      Configure the NVIC grouping
*                      1- NVIC_u8_16GROUPS_0SUB
*                      2- NVIC_u8_8GROUPS_2SUBS
*                      3- NVIC_u8_4GROUPS_4SUBS
*                      4- NVIC_u8_2GROUPS_8SUBS
*                      5- NVIC_u8_0GROUP_16SUBS
*******************************************************************************/
#define NVIC_u8_GROUPING		NVIC_u8_16GROUPS_0SUB

#endif
