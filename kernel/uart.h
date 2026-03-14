#ifndef UART_H
#define UART_H

void uart_init(void);
void uart_printc(char c);
void uart_prints(char* s);
char uart_inputc();
  
#endif // !UART_H

