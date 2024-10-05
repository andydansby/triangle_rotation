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
	
	float temp = 0;
    /* Rotate triangle */
    while (count < 500) {		
		temp = a*M_PI / 180;
		
        xr1 = c + (x1 - c) * _cosine(temp) - (y1 - d) * _sine(temp);
		
        yr1 = d + (x1 - c) * _sine(temp) + (y1 - d) * _cosine(temp);
		
        xr2 = c + (x2 - c) * _cosine(temp) - (y2 - d) * _sine(temp);
		
        yr2 = d + (x2 - c) * _sine(temp) + (y2 - d) * _cosine(temp);
		
        xr3 = c + (x3 - c) * _cosine(temp) - (y3 - d) * _sine(temp);
		
        yr3 = d + (x3 - c) * _sine(temp) + (y3 - d) * _cosine(temp);

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