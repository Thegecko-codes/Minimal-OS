ENTRY(_start)

SECTIONS
{
    . = 0x40080000;

    .text : {
        *(.text.boot)
        *(.text)
    }

    .rodata : {
        *(.rodata)
    }

    .data : {
        *(.data)
    }

    . = ALIGN(8);
    _bss_start = .;
    .bss : {
        *(.bss)
    }
    _bss_end = .;

    . = ALIGN(16);
    . += 0x4000;
    _stack_top = .;
}
