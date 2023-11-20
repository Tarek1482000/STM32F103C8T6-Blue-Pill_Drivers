/*=================================================================================*/
/*  File        : stm32f103c8t6_Linker_skript.ld                                   */
/*  Description : Linker script for STM32F103C8T6 Device from STM32F3 series       */
/*  Author      : Tarek Ahmed Abd El Wahab. Embedded SW Engineer                   */
/*  Date        : 19/10/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/tarek-el-shafei-647698205/           */
/*  Git account : https://github.com/Tarek1482000?tab=repositories                 */
/*  mail        : tarekahmed0128@gmil.com                                          */
/*=================================================================================*/


/*
  Memories definition -> Label_Name(AttributeList):
  (1) ORIGIN -> StartMemoryAddress
  (2) LENGTH -> MemoryLength
*/


/* .Highest address of the user mode stack
    .End of "RAM" Ram type memory 
    .RAM  (rwx) :  ORIGIN = 0x20000000, LENGTH = 20K 
*/
 _estack = ORIGIN(RAM) + LENGTH(RAM);


/* Required amount of heap */
_Min_Heap_Size = 0x200;

/* Required amount of stack */
_Min_Stack_Size = 0x400;


MEMORY
{
	RAM  (rwx) :  ORIGIN = 0x20000000, LENGTH = 20K
	FLASH (rx) :  ORIGIN = 0x08000000, LENGTH = 64K
}


/* Sections */
SECTIONS
{
	/* The startup code <ISR> into "FLASH" Rom type memory */
	.isr_vector :
	{
		. = ALIGN(4);
		*(.isr_vector)
		. = ALIGN(4);
	}>FLASH
	

	/* .text section, The program code and other data into "FLASH" Rom type memory */
	.text : 
    {
    	. = ALIGN(4);
    	*(.text)    /* .text  sections (code) */            
		*(.text*)   /* .text* sections (code) text and any thing more ex: textk.... -> */    
    	. = ALIGN(4);
		_etext = .;    /* Define a global symbols at end of code (end of text section) */
    }>FLASH

	/* .text section, The program code and other data into "FLASH" Rom type memory */
	.rodata : 
    {
    	. = ALIGN(4);
    	*(.rodata)    /* .rodata  sections (constants , strings , etc.)  */            
		*(.rodata*)   /* .rodata* sections (constants , strings , etc.)  */    
    	. = ALIGN(4);
    }>FLASH


     /* Used by the startup to initialize data */
     _sidata = LOADADDR(.data);

    /* .data section, Initialized data sections into "RAM" Ram type memory */
	.data : 
    {
    	. = ALIGN(4);
		_sdata = .;   /* Create a global symbol at data start */
    	*(.data)      /* .data sections  */
		*(.data*)     /* .data* sections */
    	. = ALIGN(4);
		_edata = .;   /* Define a global symbol at data end */
    }>RAM AT>FLASH


     /* .bss section, Uninitialized data section into "RAM" Ram type memory */
    .bss : 
    {
    	. = ALIGN(4);
    	_sbss = .;   /* Define a global symbol at bss start */
    	*(.bss)      /* .bss sections  */
    	*(.bss*)     /* .bss* sections */
    	. = ALIGN(4);                                            
    	_ebss = .;   /* Define a global symbol at bss end */
    }>RAM


    /* .User_heap_stack section, used to check that there is enough "RAM" Ram  type memory left */
    ._user_heap_stack :
	{
		. = ALIGN(8);
		. = . + _Min_Heap_Size;
		. = . + _Min_Stack_Size;
		. = ALIGN(8);
	}>RAM
}