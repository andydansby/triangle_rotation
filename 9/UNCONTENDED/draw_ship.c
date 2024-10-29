
void updateShip (unsigned char size)
{
    if (size == 1)
    {
        ship.point_1_X = ship1.center_X - 8;
        ship.point_1_Y = ship1.center_Y - 16;

        ship.point_2_X = ship1.center_X + 8;
        ship.point_2_Y = ship1.center_Y - 16;

        ship.point_3_X = ship1.center_X;
        ship.point_3_Y = ship1.center_Y + 16;
    }
    if (size == 0)
    {
        ship.point_1_X = ship1.center_X - 8;
        ship.point_1_Y = ship1.center_Y - 16;

        ship.point_2_X = ship1.center_X + 8;
        ship.point_2_Y = ship1.center_Y - 16;

        ship.point_3_X = ship1.center_X;
        ship.point_3_Y = ship1.center_Y + 16;
    }
}


void draw_ship (unsigned char render)
{
    eraseLine = render;

    line_x1 = ship.point_1_X;
	line_y1 = ship.point_1_Y;
	line_x2 = ship.point_2_X;
	line_y2 = ship.point_2_Y;
	Bresenham_Line();
	line_x1 = ship.point_2_X;
	line_y1 = ship.point_2_Y;
	line_x2 = ship.point_3_X;
	line_y2 = ship.point_3_Y;
	Bresenham_Line();
	line_x1 = ship.point_3_X;
	line_y1 = ship.point_3_Y;
	line_x2 = ship.point_1_X;
	line_y2 = ship.point_1_Y;
	Bresenham_Line();
}


void calculateShipRotation (void)
{
    rad_temp = degree2radian(ship_angle);
    sin_temp = _sine(rad_temp);
    cos_temp = _cosine(rad_temp);

    centerX = ship1.center_X;
    centerY = ship1.center_Y;

    ship.point_1_X = centerX + (x1 - centerX) * cos_temp - (y1 - centerY) * sin_temp;
    ship.point_1_Y = centerY + (x1 - centerX) * sin_temp + (y1 - centerY) * cos_temp;

    ship.point_2_X = centerX + (x2 - centerX) * cos_temp - (y2 - centerY) * sin_temp;
    ship.point_2_Y = centerY + (x2 - centerX) * sin_temp + (y2 - centerY) * cos_temp;

    ship.point_3_X = centerX + (x3 - centerX) * cos_temp - (y3 - centerY) * sin_temp;
    ship.point_3_Y = centerY + (x3 - centerX) * sin_temp + (y3 - centerY) * cos_temp;


}

