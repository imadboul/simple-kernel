ENTRY(start)

SECTIONS
{
    . = 0x8000;              /* stage2 loads here */

    .text : { *(.text) }     /* code */
    .data : { *(.data) }     /* initialized data */
    .bss  : { *(.bss)  }     /* uninitialized data */
}