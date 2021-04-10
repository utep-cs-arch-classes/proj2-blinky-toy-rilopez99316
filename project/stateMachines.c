#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

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
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  }
}

void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}
