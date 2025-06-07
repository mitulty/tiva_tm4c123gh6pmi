
ENTRY(reset_handler)

MEMORY
{
  FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 0x40000 /* 256k */
  RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x8000 /* 32k */
}


SECTIONS
{
  .text :
  {
    KEEP(*(.int_vector_table)) /* Interrupt vector table */
    KEEP(*(.external_interrupts_table)) /* External interrupts table */
    *(startup_code) /* Startup code */
    *(.text*)            /* All text sections */
    *(.rodata*)         /* Read-only data */
    *(.cinit*)          /* C++ constructors */
    *(.init)            /* Initialization code */
    *(.fini)            /* Finalization code */
    *(.pinit)           /* C++ pre-initialization code */
    *(.init_array)      /* Initialization functions */
    *(.fini_array)      /* Finalization functions */
    _data_flash_start = .; /* Start of data   in FLASH */
  } > FLASH

  /* .data : AT(ADDR(.text) + SIZEOF(.text)) */
  .data :
  {
    . = ALIGN(4); /* Align to 4 bytes */
    _data_ram_start = .; /* Start of data in FLASH */
    /* _data_ram_start = .; */ /* Start of data in RAM */
    *(.data*)           /* Initialized data sections */
    _data_ram_end = .; /* End of data in RAM */
  } > RAM AT > FLASH

  .bss :
  {
    . = ALIGN(4); /* Align to 4 bytes */
    _bss_start = .;    /* Start of BSS section */
    *(.bss*)            /* Uninitialized data sections */
    _bss_end = .;      /* End of BSS section */
  } > RAM AT > RAM

  .heap (NOLOAD) :
  {
    . = ALIGN(4); /* Align to 4 bytes */
    _heap_start = .; /* Start of heap */
    *(.heap*)           /* Heap sections */
    _heap_end = .; /* End of heap */
  } > RAM AT > RAM

  .stack (NOLOAD) :
  {
    . = ALIGN(4); /* Align to 4 bytes */
    _stack_start = .; /* Start of stack */
    . += 0x2000; /* Reserve 8k for main stack pointer */
    _stack_end = .; /* End of stack */
    _stack_process_start = .; /* Start of process stack */
    . += 0x400; /* Reserve 1k for process stack pointer */
    _stack_process_end = .; /* End of process stack */
  } > RAM AT > RAM

/* Discard unused sections */

/* 
  /DISCARD/ : { 
              *(*)
              } */
}