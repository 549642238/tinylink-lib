MEMORY
{
  FLASH (rx) : ORIGIN = 0x0001C000, LENGTH = 0x24000
  RAM (rwx) : ORIGIN = 0x20002800, LENGTH = 0x1800
}
OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
ENTRY(Reset_Handler)
SECTIONS
{
 .text :
 {
  KEEP(*(.Vectors))
  *(.text*)
  KEEP(*(.init))
  KEEP(*(.fini))
  *crtbegin.o(.ctors)
  *crtbegin?.o(.ctors)
  *(EXCLUDE_FILE(*crtend?.o *crtend.o) .ctors)
  *(SORT(.ctors.*))
  *(.ctors)
   *crtbegin.o(.dtors)
   *crtbegin?.o(.dtors)
   *(EXCLUDE_FILE(*crtend?.o *crtend.o) .dtors)
   *(SORT(.dtors.*))
   *(.dtors)
  *(.rodata*)
  KEEP(*(.eh_frame*))
 } > FLASH
 .ARM.extab :
 {
  *(.ARM.extab* .gnu.linkonce.armextab.*)
 } > FLASH
 __exidx_start = .;
 .ARM.exidx :
 {
  *(.ARM.exidx* .gnu.linkonce.armexidx.*)
 } > FLASH
 __exidx_end = .;
 __etext = .;
 .data : AT (__etext)
 {
  __data_start__ = .;
  *(vtable)
  *(.data*)
  . = ALIGN(4);
  PROVIDE_HIDDEN (__preinit_array_start = .);
  KEEP(*(.preinit_array))
  PROVIDE_HIDDEN (__preinit_array_end = .);
  . = ALIGN(4);
  PROVIDE_HIDDEN (__init_array_start = .);
  KEEP(*(SORT(.init_array.*)))
  KEEP(*(.init_array))
  PROVIDE_HIDDEN (__init_array_end = .);
  . = ALIGN(4);
  PROVIDE_HIDDEN (__fini_array_start = .);
  KEEP(*(SORT(.fini_array.*)))
  KEEP(*(.fini_array))
  PROVIDE_HIDDEN (__fini_array_end = .);
  *(.jcr)
  . = ALIGN(4);
  __data_end__ = .;
 } > RAM
 .bss :
 {
  . = ALIGN(4);
  __bss_start__ = .;
  *(.bss*)
  *(COMMON)
  . = ALIGN(4);
  __bss_end__ = .;
 } > RAM
 .heap (NOLOAD):
 {
  __end__ = .;
  end = __end__;
  __HeapBase = .;
  *(.heap*)
  . = ORIGIN(RAM) + LENGTH(RAM) - Stack_Size;
  __HeapLimit = .;
 } > RAM
 .stack_dummy (NOLOAD):
 {
  *(.stack*)
 } > RAM
 __StackTop = ORIGIN(RAM) + LENGTH(RAM);
 __StackLimit = __StackTop - SIZEOF(.stack_dummy);
 PROVIDE(__stack = __StackTop);
 ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}
