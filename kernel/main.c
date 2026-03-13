#include "uart.h"

void kernel_main(void){
  uart_init();
  uart_puts("Welcome to BalOS - Copyright (c) 2026 Cropping_Gecko. All Rights Reserved.");
  while(1)
  {
    uart_putc(uart_getc());
  }
}
