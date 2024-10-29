
/*
void destroyShip(void)
{
    for (int_temp1 = 0; int_temp1 < 36; int_temp1 ++)
    {
        calculateShipRotation();
        draw_ship();
        copy_buffer();//since we are not printing to screen
        ship_angle += 10;
        if (angle > MAXANGLE)
        {
            angle -= MAXANGLE;
        }
    }

    for (int_temp1 = 0; int_temp1 < 36; int_temp1 ++)
    {
        calculateShipRotation();
        undraw_ship();
        copy_buffer();//since we are not printing to screen
        ship_angle += 10;
        if (angle > MAXANGLE)
        {
            angle -= MAXANGLE;
        }
    }
    clear_buffer();
    copy_buffer();//since we are not printing to screen
}
*/

/*
void destroyShip1(void)
{

    // calculate line segments
    //end_x = x + (length * cos(rad));
    //end_y = y + (length * sin(rad));

    //segment 1
    tempx1S = x1;
    tempx1F = x2;
    tempy1S = y1;
    tempy1F = y2;

    //segment 2
    tempx2S = x1;
    tempx2F = x3;
    tempy2S = y1;
    tempy2F = y2;

    //segment 3
    tempx3S = x2;
    tempx3F = x3;
    tempy3S = y2;
    tempy3F = y3;

    //find the mid points
    //segment 1
    //char_temp1 = ABS (x1 - x2);
    //char_temp2 = ABS (y1 - y2);
    //segment 2
    //char_temp3 = ABS (x1 - x3);
    //char_temp4 = ABS (y1 - y3);
    //segment 3
    //    char_temp5 = ABS (x2 - x3);
    //char_temp6 = ABS (y2 - y3);

    //clear ship off screen
    undraw_ship();
    copy_buffer();//since we are not printing to screen



    eraseLine = 0;
	line_x1 = tempx1S;
	line_y1 = tempy1S;
	line_x2 = tempx1F;
	line_y2 = tempy1F;
	Bresenham_Line();
	line_x1 = tempx2S;
	line_y1 = tempy2S;
	line_x2 = tempx2F;
	line_y2 = tempy2F;
	Bresenham_Line();
	line_x1 = tempx3S;
	line_y1 = tempy3S;
	line_x2 = tempx3F;
	line_y2 = tempy3F;
	Bresenham_Line();


	copy_buffer();//since we are not printing to screen
    //while(1) {}
}

*/


