.section ".text.boot"
.global _start

_start:
    mrs x0, mpidr_el1
    and x0, x0, #0xFF
    cbnz x0, halt

    ldr x0, =_stack_top
    mov sp, x0

    ldr x0, =_bss_start
    ldr x1, =_bss_end
    mov x2, #0

bss_loop:
    cmp x0, x1
    beq done
    str x2, [x0], #8
    b bss_loop
done:
    ldr x0, =vector_table
    msr vbar_el1, x0
    bl kernel_main

halt:
    wfe
    b halt
