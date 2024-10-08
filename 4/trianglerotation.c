/* zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos -lm -create-app */

#define ABS(N) ((N<0)?(-N):(N))
#define MAXANGLE 360


#include <math.h>
#include <graphics.h>
#include "extern.h"
#include "clear_screen.c"
#include "variables.c"
#include "estimate_trig.c"
#include "bresenham.c"


/* trianglerotation.c */


int main(void) {

    cls();

  if (size == 1) {
    x2 = 125;
    x3 = 100;
    y3 = 127;
  } else {
    x2 = 80;
    x3 = 75;
    y3 = 78;
  }
  c = (x1 + x2 + x3) / 3;
  d = (y1 + y2 + y3) / 3;


  //gfx_xy = (yy << 8) | xx;

  /* Rotate triangle */
  while (count < 500)
  {
	cls();

    rad_temp = a*M_PI / 180;
    sin_temp = _sine(rad_temp);
    cos_temp = _cosine(rad_temp);
    xr1 = c + (x1 - c) * cos_temp - (y1 - d) * sin_temp;
    yr1 = d + (x1 - c) * sin_temp + (y1 - d) * cos_temp;
    xr2 = c + (x2 - c) * cos_temp - (y2 - d) * sin_temp;
    yr2 = d + (x2 - c) * sin_temp + (y2 - d) * cos_temp;
    xr3 = c + (x3 - c) * cos_temp - (y3 - d) * sin_temp;
    yr3 = d + (x3 - c) * sin_temp + (y3 - d) * cos_temp;

	bresenham(xr1, yr1, xr2, yr2);
	bresenham(xr2, yr2, xr3, yr3);
	bresenham(xr3, yr3, xr1, yr1);

    a += step;
    if (a > MAXANGLE) {
      a -= MAXANGLE;
    }
    count++;
  }
  return 0;
}


