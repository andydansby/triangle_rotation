
//#include "externs.h"    //references to asm functions
//#include <arch/zx.h>

void controls (void)
{
    Read_Controls();
    switch (keypress)//only for controls
        {
            case 1:
            {//left
                //destroyShip();
                break;
            }

            case 2:
            {//right
                //destroyShip1();
                break;
            }

            case 4:
            {//up
                //border_Change_uncontended(3);
                break;
            }
            case 8:
            {//down
                //border_Change_uncontended(4);
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
