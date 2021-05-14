#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

void main (){
  configureClocks();
  lcd_init();
  u_char width = screenWidth;
  u_char height = screenHeight;

  clearScreen(COLOR_BLACK);
  drawPixel(height/2, width/2, COLOR_BLUE);
  or_sr(0x18);
}
