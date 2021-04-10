#include <msp430.h>
#include "buttons.h"
#include "led.h"

void buttons_init(){
  P2REN |= BUTTONS;
  P2IE |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR |= BUTTONS;
  P2DIR &= ~BUTTONS;
  led_update();
}
