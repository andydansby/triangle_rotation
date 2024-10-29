
void defineShip(unsigned char size)
{
    if (size == 0)
    {
        ship.point_1_X = ship1.center_X;
        ship.point_1_Y = ship1.center_Y - 4;
        ship.point_2_X = ship1.center_X - 2;
        ship.point_2_Y = ship1.center_Y + 4;
        ship.point_3_X = ship1.center_X + 2;
        ship.point_3_Y = ship1.center_Y + 4;
    }

    if (size == 1)
    {
        ship.point_1_X = ship1.center_X;
        ship.point_1_Y = ship1.center_Y - 16;

        ship.point_2_X = ship1.center_X - 10;
        ship.point_2_Y = ship1.center_Y + 16;

        ship.point_3_X = ship1.center_X + 10;
        ship.point_3_Y = ship1.center_Y + 16;
    }

    x1 = ship.point_1_X;
    y1 = ship.point_1_Y;
    x2 = ship.point_2_X;
    y2 = ship.point_2_Y;
    x3 = ship.point_3_X;
    y3 = ship.point_3_Y;
}



