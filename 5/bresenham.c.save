void bresenham (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char erase)
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

    if (erase == 0)
        joffa_plot();
    if (erase == 1)
        joffa_unplot();

    if (deltaX > deltaY)
    {
        fraction = deltaY - (deltaX >> 1);
        while (x1 != x2)
        {
            gfx_xy = (x1 << 8) | y1;
            if (erase == 0)
                joffa_plot();
            if (erase == 1)
                joffa_unplot();

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
            if (erase == 0)
                joffa_plot();
            if (erase == 1)
                joffa_unplot();

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



void bresenham_2(unsigned char xx1, unsigned char yy1, unsigned char xx2, unsigned char yy2, unsigned char erase)
{
    deltaX = ABS(xx2 - xx1);
    deltaY = ABS(yy2 - yy1);
    stepx = (xx1 < xx2) ? 1 : -1;
    stepy = (yy1 < yy2) ? 1 : -1;
    steps = (deltaX > deltaY) ? deltaX : deltaY;
    fraction = 0;

    if (deltaX > deltaY)//deltaX larger
    {
        fraction = deltaY - (deltaX >> 1);// >>1 == divide by 2 = right shift 1 place
        for (iterations = 0; iterations <= steps; iterations++)
        {
            gfx_xy = (xx1 << 8) | yy1;
            if (erase == 0)
                joffa_plot();
            if (erase == 1)
                joffa_unplot();

            if (fraction >= 0)
            {
                yy1 += stepy;
                fraction -= deltaX;
            }
            xx1 += stepx;
            fraction += deltaY;
        }
    }
    else        //deltaY larger or equal
    {
        fraction = deltaX - (deltaY >> 1);// >>1 == divide by 2 = right shift 1 place
        for (iterations = 0; iterations <= steps; iterations++)
        {
            gfx_xy = (xx1 << 8) | yy1;
            if (erase == 0)
                joffa_plot();
            if (erase == 1)
                joffa_unplot();

            if (fraction >= 0)
            {
                xx1 += stepx;
                fraction -= deltaY;
            }
            yy1 += stepy;
            fraction += deltaX;
        }
    }
}

