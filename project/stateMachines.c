#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buttons.h"

static char state = 0;
static char nRed, nGreen, level; // level represents what type of brightnes we are currently at.

void dimmer(){
  char dimmer = 5;
  level++;
  if (level > dimmer){
    level = 0; //restarts level
  }

  switch(state){ // each case represent a state. case 0 = state 0...
  case 0:
    nRed = 0;
    nGreen = 0;
    break;
  case 1:
    nRed = 1;
    nGreen = 0;
    break;
  case 2:
    nRed = 0;
    nGreen = 1;
    break;
  case 3:
    nRed = 1;
    nGreen = 1;
    break;
  }

  if (nRed != red_on){
    red_on = nRed;
    led_changed = 1;
  }

  if (nGreen != green_on){
    green_on = nGreen;
    led_changed = 1;
  }
}

void state_advance()		/* alternate between toggling red & green */
{
  if (button1_down){state = 1;}
  else if (button2_down){state = 2;}
  else if (button3_down){state = 3;}
  else if (button4_down){
    state++; // makes cycle continue and not sink.
    if (state > 3){state = 0;}
  } // resets cycle
  
}
