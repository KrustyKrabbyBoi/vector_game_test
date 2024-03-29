
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


void draw_pad(const int p[]) {
  CNTR();//center
  SCAL(0x7f);//scale
  STAT(GREEN, 0);//vector properties
  VCTR(p[0], p[1], 0);//put vector
  JSRL(0x400);//draw at addr
}



static int frame = 0;

void main(void) {
  int r = 512;
  byte pad0[] = {0, 0, 0};
  dvgclear();
  dvgwrofs = 0x200;
  draw_string("W", 0);
  RTSL();
  
  
  while (1) {
    dvgreset();
    
    STAT(YELLOW, 0);//set color and stuff
    VCTR(0, 0, 0);//set vector
    JSRL(0x200);//draw
    
    
    HALT();//stop
    dvgstart();
    frame++;
  }
}
