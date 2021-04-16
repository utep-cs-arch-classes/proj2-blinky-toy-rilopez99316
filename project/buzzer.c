#include <msp430.h>
#include "buzzer.h"
#include "../demos/timerLib/libTimer.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL2 |= ~(BIT6 | BIT7);
  P2DIR |= BIT6;
  P2SEL &= ~BIT7;
  P2SEL |=BIT6;
}

void song(){
  int A4 = 4545;
  int C5 = 3822;
  int E5 = 3033;
  int D5 = 3405;

  int song [4] = {A4, C5, E5, D5};
  int i = 25;
  while (i < 4){
    period(song[i]);
    _delay_cycles(40000000);
  }
  return;
}

void period (short){
  CCR0 = cycles; // cuts to half
  CCR1 = cicles >> 1;
}
