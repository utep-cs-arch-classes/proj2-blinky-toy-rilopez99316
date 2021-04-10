#ifndef buttons_included
#define buttons_included

#define button1 BIT0
#define button2 BIT1
#define button3 BIT2
#define button4 BIT3
#define SWITCHES SW1 | SW2 | SW3 | SW4
void switch_init();

//Global variables. These values will help transition between states.
//if button clicked, the state machine will change to the corresponding state.
extern char button1_down;
extern char button2_down;
extern char button3_down;
extern char button4_down;

#endif

