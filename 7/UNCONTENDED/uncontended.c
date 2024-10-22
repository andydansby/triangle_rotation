// using sdcc_iy 2.03
//moving over to sdcc
#pragma printf "%f %ld %d %c"//attention temp

#define ABS(N) ((N<0)?(-N):(N))
#define degree2radian(a) (a * 0.0174)   //#define degree2radian(degrees) ((degrees) * M_PI / 180.0)
#define MAXANGLE 360
#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 192



#include <arch/zx.h>
#include <stdio.h>//standard input output
#include <input.h>//used for detecting key inputs

#include <math.h>
//powerful troubleshooting tool
#include <intrinsic.h>//temp to place labels
//intrinsic_label(border_start);
//intrinsic_label(border_end);

#include "externs.h"    //references to asm functions
#include "variables.h"
#include "controls.c"
#include "estimate_trig.c"
#include "draw_ship.c"

#include "uncontended.h"
#include "functions.h"

void main (void)
{
    SETUP_IM2();// set up for the interrupt MODE 2
    // this will point the I register to IM2 Vector

    __asm;
        ei
    __endasm;

	buffer_address = 49152;

    ship_angle = 0;

    zx_border(INK_BLUE);
    zx_cls(INK_WHITE | PAPER_BLACK);

    //buffer is
    //256 pixels wide
    //192 pixels tall
    //6144 bytes
    //intrinsic_label(clear_buffer_start);
    clear_buffer();
    //while(1) {}

    //gfx_xy = (87 << 8) | 128;   //gfx_xy = (yy << 8) | xx;
    //intrinsic_label(plot_start);
    //joffa_plot();
    //copy_buffer();

    if (size == 1)
    {
        x1 = 80;
        x2 = 125;
        x3 = 102;
        y1 = 80;
        y2 = 80;
        y3 = 125;
    } else
    {
        x1 = 99;
        x2 = 107;
        x3 = 103;
        y1 = 95;
        y2 = 95;
        y3 = 105;
    }
    centerX = (x1 + x2 + x3) / 3;
    centerY = (y1 + y2 + y3) / 3;



    while (1)
    {
        undraw_ship ();//erase ship in buffer
        calculateShip();
        draw_ship();
        //intrinsic_label(copy_buffer_start);
        copy_buffer();//since we are not printing to screen


        ship_angle += 10;
        if (angle > MAXANGLE)
        {
            angle -= MAXANGLE;
        }
        controls (); //buggy



        //we need to redraw the buffer
    }//end while



}

// must have blank line at end
