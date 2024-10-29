#ifndef VARIABLES_H
#define VARIABLES_H

struct Ship
{
    unsigned char point_1_X;
    unsigned char point_1_Y;
    unsigned char point_2_X;
    unsigned char point_2_Y;
    unsigned char point_3_X;
    unsigned char point_3_Y;
}ship;

struct Ship1
{
    unsigned char center_X;
    unsigned char center_Y;
}ship1;

unsigned char x1;
unsigned char y1;
unsigned char y2;
unsigned char x2;
unsigned char x3;
unsigned char y3;



unsigned char relativeX, relativeY;
unsigned char new_point_1_X, new_point_1_Y;
unsigned char new_point_2_X, new_point_2_Y;
unsigned char new_point_3_X, new_point_3_Y;


unsigned int int_temp1;
unsigned int int_temp2;
unsigned int int_temp3;
unsigned char char_temp1;
unsigned char char_temp2;
unsigned char char_temp3;
unsigned char char_temp4;
unsigned char char_temp5;
unsigned char char_temp6;


unsigned int ship_angle;


unsigned int copy_memory_source = 0;
unsigned int copy_memory_destination = 0;
unsigned int copy_memory_size = 0;


double_t rad_temp = 0;        //half_t rad_temp = 0;
double_t sin_temp = 0;        //half_t sin_temp = 0;
double_t cos_temp = 0;        //half_t cos_temp = 0;

/* triangle-size: 0 = small, 1 = large */


/* triangle-size: 0 = small, 1 = large */
unsigned char ship_size = 1;
int step = 10;




unsigned char centerX;
unsigned char centerY;
int angle = 90;

unsigned char xr1;
unsigned char yr1;
unsigned char xr2;
unsigned char yr2;
unsigned char xr3;
unsigned char yr3;

//to remove
    unsigned char tempx1S;
    unsigned char tempx1F;
    unsigned char tempy1S;
    unsigned char tempy1F;

    unsigned char tempx2S;
    unsigned char tempy2S;
    unsigned char tempx2F;
    unsigned char tempy2F;

    unsigned char tempx3S;
    unsigned char tempy3S;
    unsigned char tempx3F;
    unsigned char tempy3F;

    float scale;

#endif
