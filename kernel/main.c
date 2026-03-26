#include "uart.h"
#include "mstring.h"

void kernel_main(void){
  char word[256];
  char letter[2];
  uart_init();
  uart_prints("Welcome to Minimal OS\nCopyright (c) 2026 Gecko. All Rights Reserved.\n");
  while(1)
  {
    word[0] = '\0';
    uart_prints(">>> ");
    while (1) {
      char c = uart_inputc();
      if(c == '\r')
        break;
      else if (c == 127)
      {
        uart_printc('\b');
        uart_printc(' ');
        uart_printc('\b');
      }

      uart_printc(c);
      letter[0] = c;
      letter[1] = '\0';
      mstrcat(word, letter);
    }
    uart_printc('\n');
    if(word == "spit")
      uart_prints("The spit command has not been initialised yet. Please wait for the next update");
    else
     uart_prints(word);
    uart_printc('\n');
  }
}
