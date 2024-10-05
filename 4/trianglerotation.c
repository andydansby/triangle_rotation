/* zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos -lm -create-app */
#include <math.h>
#include <graphics.h>
#include "variables.c"
#include "estimate_trig.c"
#include "bresenham.c"

/* trianglerotation.c */

void cls(void) {
    #asm
    call 3435;
    #endasm
}

void cls2()
{
    #asm
    ld hl, 16384+2048
    ld de, 16384+2048+1
    ld bc, 2047
    ldir
    #endasm
}


int main(void) {

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
  plot(c, d);

  while(1)
  {
        //gfx_xy = (yy << 8) | xx;
  }

  /* Rotate triangle */
  while (count < 500) {
    rad_temp = a*M_PI / 180;
    sin_temp = _sine(rad_temp);
    cos_temp = _cosine(rad_temp);
    xr1 = c + (x1 - c) * cos_temp - (y1 - d) * sin_temp;
    yr1 = d + (x1 - c) * sin_temp + (y1 - d) * cos_temp;
    xr2 = c + (x2 - c) * cos_temp - (y2 - d) * sin_temp;
    yr2 = d + (x2 - c) * sin_temp + (y2 - d) * cos_temp;
    xr3 = c + (x3 - c) * cos_temp - (y3 - d) * sin_temp;
    yr3 = d + (x3 - c) * sin_temp + (y3 - d) * cos_temp;


    cursor_x = xr1;
    cursor_y = yr1;


    //plot(cursor_x, cursor_y);


    //cursor_x += xr2 - xr1;
    //cursor_y += yr2 - yr1;
    //drawto(cursor_x, cursor_y);
	//plot(cursor_x, cursor_y);
	bresenham(xr1, yr1, xr2, yr2);

    //cursor_x += xr3 - xr2;
    //cursor_y += yr3 - yr2;
    //drawto(cursor_x, cursor_y);
	//plot(cursor_x, cursor_y);
	bresenham(xr2, yr2, xr3, yr3);

    //cursor_x += xr1 - xr3;
    //cursor_y += yr1 - yr3;
    //drawto(cursor_x, cursor_y);
	//plot(cursor_x, cursor_y);
	bresenham(xr3, yr3, xr1, yr1);

    a += step;
    if (a > 360) {
      a -= 360;
    }
    count++;

	#asm
	    halt
	#endasm
	cls2();

  }
  return 0;
}


