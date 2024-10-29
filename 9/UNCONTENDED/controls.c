
void controls (void)
{
    Read_Controls();
    switch (keypress)//only for controls
        {
            case 1:
            {//left
                //destroyShip();
                ship1.center_X --;
                break;
            }

            case 2:
            {//right
                //destroyShip1();
                ship1.center_X ++;
                break;
            }

            case 4:
            {//up
                ship1.center_Y --;
                break;
            }
            case 8:
            {//down
                ship1.center_Y ++;
                break;
            }

            case 16:
            {//fire
                //destroyShip1();
                break;
            }
            case 32:
            {//M
                break;
            }
            case 64:
            {//Z
                break;
            }
            case 96:
            {//M & Z
                //border_Change_uncontended(7);
                break;
            }
            case 0:
            {//no keys
                //border_Change_uncontended(0);
                break;
            }
        }//end switch/case
}
