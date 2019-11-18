
#include <string.h>

#include "vecops.h"
//#link "vecops.c"

#include "vecfont.h"
//#link "vecfont.c"

////

#define input0   (*(byte*)0x7800)
#define input1   (*(byte*)0x8000)
#define watchdog (*(byte*)0x8980)
#define vidframe (*(byte*)0x0)

#define LEFT1 !(input1 & 0x8)
#define RIGHT1 !(input1 & 0x4)
#define UP1 !(input1 & 0x10)
#define DOWN1 !(input1 & 0x20)
#define FIRE1 !(input1 & 0x2)
#define BOMB1 !(input1 & 0x1)
#define COIN1 (input0 & 0x2)
#define COIN2 (input0 & 0x1)
#define START1 (input2 & 0x20)
#define START2 (input2 & 0x40)

static int frame = 0;

void main(void) {
  int r = 512;
  int y = -10;
  int x = 10;
  dvgclear();
  dvgwrofs = 0x200;
  draw_string("W", 0);
  RTSL();
  while (1) {
    dvgreset();
    if (UP1) {
      y++;
    }
    if (DOWN1) {
      y--;
    }
    if (LEFT1) {
      x--;
    }
    if (RIGHT1) {
      x++;
    }
    
    STAT(YELLOW, 0);//set color and stuff
    VCTR(x, y, 0);//set vector
    JSRL(0x200);//draw
    HALT();//stop
    dvgstart();
    frame++;
  }
}
