/* zcc +zx trianglerotation.c -o trianglerotation -compiler=sccz80 -clib=default -lndos -lm -create-app */
#include <math.h>
#include <graphics.h>
#include "estimate_trig.c"

/* trianglerotation.c */



void cls(void) {
    #asm
    call 3435;
    #endasm
}

int main(void) {
    /* triangle-size: 0 = small, 1 = large */
    int size = 1;
    int step = 10;
    int x1 = 70;
    int y1 = 70;
    int y2 = 70;
    int x2;
    int x3;
    int y3;
    if (size == 1) {
        x2 = 130;
        x3 = 100;
        y3 = 130;
    } else {
        x2 = 80;
        x3 = 75;
        y3 = 78;
    }
    int c = (x1 + x2 + x3) / 3;
    int d = (y1 + y2 + y3) / 3;
    plot(c, d);
    int a = 0;
    int xr1;
    int yr1;
    int xr2;
    int yr2;
    int xr3;
    int yr3;
    int cursor_x;
    int cursor_y;
    int count = 0;
	
	float rad_temp = 0;
	float sin_temp = 0;
	float cos_temp = 0;
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
        cls();
        plot(cursor_x, cursor_y);
        cursor_x += xr2 - xr1;
        cursor_y += yr2 - yr1;
        drawto(cursor_x, cursor_y);
        cursor_x += xr3 - xr2;
        cursor_y += yr3 - yr2;
        drawto(cursor_x, cursor_y);
        cursor_x += xr1 - xr3;
        cursor_y += yr1 - yr3;
        drawto(cursor_x, cursor_y);
        a += step;
        if (a > 360) {
            a -= 360;
        }
        count++;
    }
    return 0;
}