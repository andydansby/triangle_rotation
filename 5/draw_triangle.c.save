
void draw_triangle (void)
{
    eraseLine = 0;
	line_x1 = xr1;
	line_y1 = yr1;
	line_x2 = xr2;
	line_y2 = yr2;
	bresenham_start();
	line_x1 = xr2;
	line_y1 = yr2;
	line_x2 = xr3;
	line_y2 = yr3;
	bresenham_start();
	line_x1 = xr3;
	line_y1 = yr3;
	line_x2 = xr1;
	line_y2 = yr1;
	bresenham_start();
}

void undraw_triangle (void)
{
    eraseLine = 1;
	line_x1 = xr1;
	line_y1 = yr1;
	line_x2 = xr2;
	line_y2 = yr2;
	bresenham_start();
	line_x1 = xr2;
	line_y1 = yr2;
	line_x2 = xr3;
	line_y2 = yr3;
	bresenham_start();
	line_x1 = xr3;
	line_y1 = yr3;
	line_x2 = xr1;
	line_y2 = yr1;
	bresenham_start();
}
