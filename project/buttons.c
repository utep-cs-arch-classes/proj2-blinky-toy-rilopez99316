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

void button_interrupt_hndlr(){
  char P2VAL = button_upd_Interrupt_hndrl();

  button1_down = (P2VAL & button1) ? 0 : 1;
  button2_down = (P2VAL & button2) ? 0 : 1;
  button3_down = (P2VAL & button3) ? 0 : 1;
  button4_down = (P2VAL & button4) ? 0 : 1;

  button1_upd = 1;
  button2_upd = 1;
  button3_upd = 1;
  button4_upd = 1;
  led_update();
}
