#include <msp430.h>
#include "buttons.h"
#include "led.h"

char button1_down;
char button2_down;
char button3_down;
char button4_down;

void buttons_init(){
  P2REN |= BUTTONS;
  P2IE |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR |= BUTTONS;
  P2DIR &= ~BUTTONS;
  led_update();
}

static char button_upd_Interrupt_hndrl(){
  char P2VAL = P2IN;

  P2IES |= (P2VAL & BUTTONS);
  P2IES &= (P2VAL | ~BUTTONS);
  return P2VAL;
}
