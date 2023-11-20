/*=================================================================================*/
/*  File        : stm32f103c8t6_Startup_code.c                                     */
/*  Description : Startup code for stm32f103c8t6                                   */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/

#define NULL  0
typedef unsigned long u32;

extern u32 _estack,_etext,_sdata,_edata,_sbss,_ebss,_sidata;


extern void main(void);


void Reset_Handler                     (void);
void NMI_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void HardFault_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void MemManage_Handler                 (void) __attribute__ ((alias ("Default_Handler")));
void BusFault_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void UsageFault_Handler                (void) __attribute__ ((alias ("Default_Handler")));
void SVC_Handler                       (void) __attribute__ ((alias ("Default_Handler")));
void DebugMon_Handler                  (void) __attribute__ ((alias ("Default_Handler")));
void PendSV_Handler                    (void) __attribute__ ((alias ("Default_Handler")));
void SysTick_Handler                   (void) __attribute__ ((alias ("Default_Handler")));
void WWDG_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));               
void PVD_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));
void TAMPER_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void RTC_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));
void FLASH_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler"))); 
void RCC_IRQHandler                    (void) __attribute__ ((alias ("Default_Handler")));   
void EXTI0_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI1_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI2_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI3_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void EXTI4_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel1_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel2_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel3_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel4_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel5_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel6_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA1_Channel7_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void ADC1_2_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void USB_HP_CAN_TX_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void USB_LP_CAN_RX0_IRQHandler         (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_RX1_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void CAN1_SCE_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void EXTI9_5_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_BRK_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_UP_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_TRG_COM_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void TIM1_CC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM2_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM4_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C1_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_EV_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void I2C2_ER_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void SPI1_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void SPI2_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void USART1_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void USART2_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void USART3_IRQHandler                 (void) __attribute__ ((alias ("Default_Handler")));
void EXTI15_10_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void RTC_Alarm_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void USBWakeup_IRQHandler              (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_BRK_IRQHandler               (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_UP_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_TRG_COM_IRQHandler           (void) __attribute__ ((alias ("Default_Handler")));
void TIM8_CC_IRQHandler                (void) __attribute__ ((alias ("Default_Handler")));
void ADC3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void FSMC_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SDIO_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM5_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void SPI3_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void UART4_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void UART5_IRQHandler                  (void) __attribute__ ((alias ("Default_Handler")));
void TIM6_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void TIM7_IRQHandler                   (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel1_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel2_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel3_IRQHandler          (void) __attribute__ ((alias ("Default_Handler")));
void DMA2_Channel4_5_IRQHandler        (void) __attribute__ ((alias ("Default_Handler")));



/* _estack is the first stack ptr address start */
u32 *const MSP_Value = (u32 *)&_estack;


/* Vector table for a Cortex M3 */
u32 *Vector_Table[] __attribute__ ((section (".isr_vector"))) = 
{
    (u32 *) MSP_Value,                      /* Main Stack Pointer */                                                 
    (u32 *) Reset_Handler,                  /* Reset */                               
    (u32 *) NMI_Handler,                    /* Non maskable interrupt */                             
    (u32 *) HardFault_Handler,              /* All class of fault */                                   
    (u32 *) MemManage_Handler,              /* Memory management */                                   
    (u32 *) BusFault_Handler,               /* Pre-fetch fault, memory access fault */                                   
    (u32 *) UsageFault_Handler,             /* Undefined instruction or illegal state */                                    
    0,                                       
    0,                                       
    0,                                       
    0,                                       
    (u32 *) SVC_Handler,                    /* System service call via SWI instruction */                                             
    (u32 *) DebugMon_Handler,               /* Debug Monitor */                                                       
    0,                                                                                                                                      
    (u32 *) PendSV_Handler,                 /* Pendable request for system service */                                                                  
    (u32 *) SysTick_Handler,                                                                                     
    (u32 *) WWDG_IRQHandler,                                                                                     
    (u32 *) PVD_IRQHandler,                                                                                     
    (u32 *) TAMPER_IRQHandler,                                                                                     
    (u32 *) RTC_IRQHandler,                                                                                     
    (u32 *) FLASH_IRQHandler,                                                                                     
    (u32 *) RCC_IRQHandler,                                                                                     
    (u32 *) EXTI0_IRQHandler,                                                                                     
    (u32 *) EXTI1_IRQHandler,                                                                                     
    (u32 *) EXTI2_IRQHandler,                                                                                     
    (u32 *) EXTI3_IRQHandler,                                                                                     
    (u32 *) EXTI4_IRQHandler,                                                                                     
    (u32 *) DMA1_Channel1_IRQHandler,  
    (u32 *) DMA1_Channel2_IRQHandler,  
    (u32 *) DMA1_Channel3_IRQHandler,  
    (u32 *) DMA1_Channel4_IRQHandler,  
    (u32 *) DMA1_Channel5_IRQHandler,  
    (u32 *) DMA1_Channel6_IRQHandler,  
    (u32 *) DMA1_Channel7_IRQHandler,  
    (u32 *) ADC1_2_IRQHandler,  
    (u32 *) USB_HP_CAN_TX_IRQHandler,  
    (u32 *) USB_LP_CAN_RX0_IRQHandler,  
    (u32 *) CAN1_RX1_IRQHandler,  
    (u32 *) CAN1_SCE_IRQHandler,  
    (u32 *) EXTI9_5_IRQHandler,  
    (u32 *) TIM1_BRK_IRQHandler,  
    (u32 *) TIM1_UP_IRQHandler,  
    (u32 *) TIM1_TRG_COM_IRQHandler,  
    (u32 *) TIM1_CC_IRQHandler,  
    (u32 *) TIM2_IRQHandler,  
    (u32 *) TIM3_IRQHandler,  
    (u32 *) TIM4_IRQHandler,  
    (u32 *) I2C1_EV_IRQHandler,  
    (u32 *) I2C1_ER_IRQHandler,  
    (u32 *) I2C2_EV_IRQHandler,  
    (u32 *) I2C2_ER_IRQHandler,  
    (u32 *) SPI1_IRQHandler,  
    (u32 *) SPI2_IRQHandler,  
    (u32 *) USART1_IRQHandler,  
    (u32 *) USART2_IRQHandler,  
    (u32 *) USART3_IRQHandler,  
    (u32 *) EXTI15_10_IRQHandler,  
    (u32 *) RTC_Alarm_IRQHandler,  
    (u32 *) USBWakeup_IRQHandler,  
    (u32 *) TIM8_BRK_IRQHandler,  
    (u32 *) TIM8_UP_IRQHandler,  
    (u32 *) TIM8_TRG_COM_IRQHandler,  
    (u32 *) TIM8_CC_IRQHandler,  
    (u32 *) ADC3_IRQHandler,  
    (u32 *) FSMC_IRQHandler,  
    (u32 *) SDIO_IRQHandler,  
    (u32 *) TIM5_IRQHandler,  
    (u32 *) SPI3_IRQHandler,  
    (u32 *) UART4_IRQHandler,  
    (u32 *) UART5_IRQHandler,  
    (u32 *) TIM6_IRQHandler,  
    (u32 *) TIM7_IRQHandler,  
    (u32 *) DMA2_Channel1_IRQHandler,  
    (u32 *) DMA2_Channel2_IRQHandler,  
    (u32 *) DMA2_Channel3_IRQHandler,  
    (u32 *) DMA2_Channel4_5_IRQHandler,  
};

static void System_Initialization(void)
{
     /* Clock intitialization */
}



void Reset_Handler(void)
{
    u32 Section_Size = 0;
    u32 *MemSource_Add   = NULL;
    u32 *MemDestAddr      = NULL;

    /* 1) Copy the data segment initializers from flash to SRAM */
    Section_Size   = &_edata - &_sdata; /* Length of .data segment */
    MemSource_Add  = (u32 *)&_sidata;  /* Start address of .data sengement (LMA)(FLASH) -> Load Memory Address   */      
    MemDestAddr    = (u32 *)&_sdata;   /* Start address of .data sengement (VMA)(SRAM) -> Virtual Memory Address */  

    for(u32 Mem_counter=0;Mem_counter < Section_Size;Mem_counter++)
    {
        *MemDestAddr = *MemSource_Add;
        MemDestAddr++;
        MemSource_Add++;
    }
    /* 2) Initialize the .bss segment with zero */
    Section_Size = &_ebss - &_sbss; /* Length of .bss segment */
    MemDestAddr = (u32 *)&_sbss;    /* Start address of .bss sengement */

  for(u32 Mem_counter=0;Mem_counter < Section_Size;Mem_counter++)
    {
        *MemDestAddr = 0;
         MemDestAddr++;
    }
    /* 3) Call the system intitialization function */
    System_Initialization();


    /* 4) Call the main function */
    main();
}



void Default_Handler(void)
{


}















































































