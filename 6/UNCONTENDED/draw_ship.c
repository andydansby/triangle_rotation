
void draw_ship (void)
{
    #asm
        di
    #endasm
    eraseLine = 0;
	line_x1 = ship_xr1;
	line_y1 = ship_yr1;
	line_x2 = ship_xr2;
	line_y2 = ship_yr2;
	Bresenham_Line();
	line_x1 = ship_xr2;
	line_y1 = ship_yr2;
	line_x2 = ship_xr3;
	line_y2 = ship_yr3;
	Bresenham_Line();
	line_x1 = ship_xr3;
	line_y1 = ship_yr3;
	line_x2 = ship_xr1;
	line_y2 = ship_yr1;
	Bresenham_Line();
	#asm
        ei
    #endasm
}


void undraw_ship (void)
{
    #asm
        di
    #endasm
    eraseLine = 1;
	line_x1 = ship_xr1;
	line_y1 = ship_yr1;
	line_x2 = ship_xr2;
	line_y2 = ship_yr2;
	Bresenham_Line();
	line_x1 = ship_xr2;
	line_y1 = ship_yr2;
	line_x2 = ship_xr3;
	line_y2 = ship_yr3;
	Bresenham_Line();
	line_x1 = ship_xr3;
	line_y1 = ship_yr3;
	line_x2 = ship_xr1;
	line_y2 = ship_yr1;
	Bresenham_Line();
	#asm
        ei
    #endasm
}

void calculateShip (void)
{
    rad_temp = degree2radian(ship_angle);
    sin_temp = _sine(rad_temp);
    cos_temp = _cosine(rad_temp);

    ship_xr1 = c + (x1 - c) * cos_temp - (y1 - d) * sin_temp;
    ship_yr1 = d + (x1 - c) * sin_temp + (y1 - d) * cos_temp;
    ship_xr2 = c + (x2 - c) * cos_temp - (y2 - d) * sin_temp;
    ship_yr2 = d + (x2 - c) * sin_temp + (y2 - d) * cos_temp;
    ship_xr3 = c + (x3 - c) * cos_temp - (y3 - d) * sin_temp;
    ship_yr3 = d + (x3 - c) * sin_temp + (y3 - d) * cos_temp;
}
