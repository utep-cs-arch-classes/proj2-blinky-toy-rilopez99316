#include <msp430.h>
#include "buttons.h"

void interrupt_Vector(PORT2_VECTOR) Port_2{
  if (P2IFG & BUTTONS){
    P2IFG &= ~BUTTONS;

    buttons_interrupt_handler();
  }
}
