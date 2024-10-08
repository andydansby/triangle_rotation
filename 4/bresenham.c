void bresenham (int x1, int y1, int x2, int y2)
{
    fraction = 0;

    deltaX = x2 - x1;
    deltaY = y2 - y1;

    stepy = (deltaY < 0) ? -1 : 1;
    stepx = (deltaX < 0) ? -1 : 1;

    deltaX = ABS(deltaX);
    deltaY = ABS(deltaY);

	//plot starting point
    gfx_xy = (x1 << 8) | y1;
    joffa_pixel2();

    if (deltaX > deltaY)
    {
        fraction = deltaY - (deltaX >> 1);
        while (x1 != x2)
        {
            gfx_xy = (x1 << 8) | y1;
            joffa_pixel2();

            if (fraction >= 0)
            {
                y1 += stepy;
                fraction -= deltaX;
            }
            x1 += stepx;
            fraction += deltaY;
        }
    }
    else
    {
        fraction = deltaX - (deltaY >> 1);
        while (y1 != y2)
        {
            gfx_xy = (x1 << 8) | y1;
            joffa_pixel2();

            if (fraction >= 0)
            {
                x1 += stepx;
                fraction -= deltaY;
            }
            y1 += stepy;
            fraction += deltaX;
        }
    }
}

