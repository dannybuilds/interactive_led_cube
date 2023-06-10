#include <SPI.h>

//*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE*+*+*+*+*+*+*+*+*+*+*+*+PUT ANIMATIONS DOWN HERE

void wipe_out()
{//*****wipe_out*****wipe_out*****wipe_out*****wipe_out*****wipe_out*****wipe_out*****wipe_out*****wipe_out
    int xxx = 0, yyy = 0, zzz = 0;
    int fx = random(8), fy = random(8), fz = random(8), direct, fxm = 1, fym = 1, fzm = 1, fxo = 0, fyo = 0, fzo = 0;
    int  ftx = random(8), fty = random(8), ftz = random(8), ftxm = 1, ftym = 1, ftzm = 1, ftxo = 0, ftyo = 0, ftzo = 0;
    int select, rr, gg, bb, rrt, ggt, bbt;
    for (xxx = 0; xxx < 8; xxx++)
    {
        for (yyy = 0; yyy < 8; yyy++)
        {
            for (zzz = 0; zzz < 8; zzz++)
            {
                LED(xxx, yyy, zzz, 0, 0, 0);
            }
        }
    }

    select = random(3);
    if (select == 0)
    {
        rr = random(1, 16);
        gg = random(1, 16);
        bb = 0;
    }
    if (select == 1)
    {
        rr = random(1, 16);
        gg = 0;
        bb = random(1, 16);
    }
    if (select == 2)
    {
        rr = 0;
        gg = random(1, 16);
        bb = random(1, 16);
    }

    select = random(3);
    if (select == 0)
    {
        rrt = random(1, 16);
        ggt = random(1, 16);
        bbt = 0;
    }
    if (select == 1)
    {
        rrt = random(1, 16);
        ggt = 0;
        bbt = random(1, 16);
    }
    if (select == 2)
    {
        rrt = 0;
        ggt = random(1, 16);
        bbt = random(1, 16);
    }
    start = millis();

    while (millis() - start < 10000)
    {

  //fx=random(8); fy=random(8); fz=random(8);

        LED(fxo, fyo, fzo, 0, 0, 0);
        LED(fxo, fyo, fzo + 1, 0, 0, 0);
        LED(fxo, fyo, fzo - 1, 0, 0, 0);
        LED(fxo + 1, fyo, fzo, 0, 0, 0);
        LED(fxo - 1, fyo, fzo, 0, 0, 0);
        LED(fxo, fyo + 1, fzo, 0, 0, 0);
        LED(fxo, fyo - 1, fzo, 0, 0, 0);

        LED(ftxo, ftyo, ftzo, 0, 0, 0);
        LED(ftxo, ftyo, ftzo + 1, 0, 0, 0);
        LED(ftxo, ftyo, ftzo - 1, 0, 0, 0);
        LED(ftxo + 1, ftyo, ftzo, 0, 0, 0);
        LED(ftxo - 1, ftyo, ftzo, 0, 0, 0);
        LED(ftxo, ftyo + 1, ftzo, 0, 0, 0);
        LED(ftxo, ftyo - 1, ftzo, 0, 0, 0);

        LED(ftx, fty, ftz, rr, gg, bb);
        LED(ftx, fty, ftz + 1, rr, gg, bb);
        LED(ftx, fty, ftz - 1, rr, gg, bb);
        LED(ftx + 1, fty, ftz, rr, gg, bb);
        LED(ftx - 1, fty, ftz, rr, gg, bb);
        LED(ftx, fty + 1, ftz, rr, gg, bb);
        LED(ftx, fty - 1, ftz, rr, gg, bb);

        LED(fx, fy, fz, rrt, ggt, bbt);
        LED(fx, fy, fz + 1, rrt, ggt, bbt);
        LED(fx, fy, fz - 1, rrt, ggt, bbt);
        LED(fx + 1, fy, fz, rrt, ggt, bbt);
        LED(fx - 1, fy, fz, rrt, ggt, bbt);
        LED(fx, fy + 1, fz, rrt, ggt, bbt);
        LED(fx, fy - 1, fz, rrt, ggt, bbt);


        delay(10);

        fxo = fx;
        fyo = fy;
        fzo = fz;

        ftxo = ftx;
        ftyo = fty;
        ftzo = ftz;

        direct = random(3);
        if (direct == 0)
            fx = fx + fxm;
        if (direct == 1)
            fy = fy + fym;
        if (direct == 2)
            fz = fz + fzm;
        if (fx < 0)
        {
            fx = 0; fxm = 1;
        }
        if (fx > 7)
        {
            fx = 7; fxm = -1;
        }
        if (fy < 0)
        {
            fy = 0; fym = 1;
        }
        if (fy > 7)
        {
            fy = 7; fym = -1;
        }
        if (fz < 0)
        {
            fz = 0; fzm = 1;
        }
        if (fz > 7)
        {
            fz = 7; fzm = -1;
        }

        direct = random(3);
        if (direct == 0)
            ftx = ftx + ftxm;
        if (direct == 1)
            fty = fty + ftym;
        if (direct == 2)
            ftz = ftz + ftzm;
        if (ftx < 0)
        {
            ftx = 0; ftxm = 1;
        }
        if (ftx > 7)
        {
            ftx = 7; ftxm = -1;
        }
        if (fty < 0)
        {
            fty = 0; ftym = 1;
        }
        if (fty > 7)
        {
            fty = 7; ftym = -1;
        }
        if (ftz < 0)
        {
            ftz = 0; ftzm = 1;
        }
        if (ftz > 7)
        {
            ftz = 7; ftzm = -1;
        }
    }//while
    for (xxx = 0; xxx < 8; xxx++)
    {
        for (yyy = 0; yyy < 8; yyy++)
        {
            for (zzz = 0; zzz < 8; zzz++)
            {
                LED(xxx, yyy, zzz, 0, 0, 0);
            }
        }
    }

}//wipeout


void rainVersionTwo()
{//****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo****rainVersionTwo
    int x[64], y[64], z[64], addr, leds = 64, bright = 1, ledcolor, colowheel;
    int xx[64], yy[64], zz[64], xold[64], yold[64], zold[64], slowdown;

    for (addr = 0; addr < 64; addr++)
    {
        x[addr] = random(8);
        y[addr] = random(8);
        z[addr] = random(8);
        xx[addr] = random(16);
        yy[addr] = random(16);
        zz[addr] = random(16);
    }
    start = millis();
    while (millis() - start < 20000)
    {
  //wipe_out();
  //for(addr=0; addr<leds; addr++)
  //LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);

        if (ledcolor < 200)
        {
            for (addr = 0; addr < leds; addr++)
            {
                LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
                if (z[addr] >= 7)
                    LED(z[addr], x[addr], y[addr], 0, 5, 15);
                if (z[addr] == 6)
                    LED(z[addr], x[addr], y[addr], 0, 1, 9);
                if (z[addr] == 5)
                    LED(z[addr], x[addr], y[addr], 0, 0, 10);
                if (z[addr] == 4)
                    LED(z[addr], x[addr], y[addr], 1, 0, 11);
                if (z[addr] == 3)
                    LED(z[addr], x[addr], y[addr], 3, 0, 12);
                if (z[addr] == 2)
                    LED(z[addr], x[addr], y[addr], 10, 0, 15);
                if (z[addr] == 1)
                    LED(z[addr], x[addr], y[addr], 10, 0, 10);
                if (z[addr] <= 0)
                    LED(z[addr], x[addr], y[addr], 10, 0, 1);
            }
        }//200

        if (ledcolor >= 200 && ledcolor < 300)
        {
            for (addr = 0; addr < leds; addr++)
            {
                LED(zold[addr], xold[addr], yold[addr], 0, 0, 0);
                if (z[addr] >= 7)
                    LED(z[addr], x[addr], y[addr], 15, 15, 0);
                if (z[addr] == 6)
                    LED(z[addr], x[addr], y[addr], 10, 10, 0);
                if (z[addr] == 5)
                    LED(z[addr], x[addr], y[addr], 15, 5, 0);
                if (z[addr] == 4)
                    LED(z[addr], x[addr], y[addr], 15, 2, 0);
                if (z[addr] == 3)
                    LED(z[addr], x[addr], y[addr], 15, 1, 0);
                if (z[addr] == 2)
                    LED(z[addr], x[addr], y[addr], 15, 0, 0);
                if (z[addr] == 1)
                    LED(z[addr], x[addr], y[addr], 12, 0, 0);
                if (z[addr] <= 0)
                    LED(z[addr], x[addr], y[addr], 10, 0, 0);
            }
        }//300

        if (ledcolor >= 300 && ledcolor < 400)
        {

        }
        if (ledcolor >= 500 && ledcolor < 600)
        {

        }


        ledcolor++;
        if (ledcolor >= 300)
            ledcolor = 0;

        for (addr = 0; addr < leds; addr++)
        {
            xold[addr] = x[addr];
            yold[addr] = y[addr];
            zold[addr] = z[addr];
        }


        delay(15);

        //for(addr=0; addr<leds; addr++)
        //LED(z[addr], x[addr], y[addr], 0, 0, 0);
        for (addr = 0; addr < leds; addr++)
        {

    //slowdown = random(2);
    //if(bitRead(z[addr],0))
            z[addr] = z[addr] - 1;

           // x[addr] = x[addr]+1;
           // y[addr] = y[addr]+1;
            if (z[addr] < random(-100, 0))
            {
                x[addr] = random(8);
                y[addr] = random(8);
                int select = random(3);
                if (select == 0)
                {
                    xx[addr] = 0;
                    zz[addr] = random(16);
                    yy[addr] = random(16);
                    //zz[addr]=0;
                }
                if (select == 1)
                {
                    xx[addr] = random(16);
                    zz[addr] = 0;
                    yy[addr] = random(16);
                    //yy[addr]=0;
                }
                if (select == 2)
                {
                    xx[addr] = random(16);
                    zz[addr] = random(16);
                    yy[addr] = 0;


                }
                z[addr] = 7;

            }//-check
        }//add


    }//while

}//rainv2

void folder()
{//****folder****folder****folder****folder****folder****folder****folder****folder****folder
    int xx, yy, zz, pullback[16], state = 0, backorfront = 7;//backorfront 7 for back 0 for front

    int folderaddr[16], LED_Old[16], oldpullback[16], ranx = random(16), rany = random(16), ranz = random(16), ranselect;
    int bot = 0, top = 1, right = 0, left = 0, back = 0, front = 0, side = 0, side_select;

    folderaddr[0] = -7;
    folderaddr[1] = -6;
    folderaddr[2] = -5;
    folderaddr[3] = -4;
    folderaddr[4] = -3;
    folderaddr[5] = -2;
    folderaddr[6] = -1;
    folderaddr[7] = 0;

    for (xx = 0; xx < 8; xx++)
    {
        oldpullback[xx] = 0;
        pullback[xx] = 0;
    }



    start = millis();
    while (millis() - start < 10000)
    {
        if (top == 1)
        {
            if (side == 0)
            {
      //top to left-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(7 - LED_Old[yy], yy - oldpullback[yy], xx, 0, 0, 0);
                        LED(7 - folderaddr[yy], yy - pullback[yy], xx, ranx, rany, ranz);
                    }
                }
            }
            if (side == 2)
            {
      //top to back-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(7 - LED_Old[yy], xx, yy - oldpullback[yy], 0, 0, 0);
                        LED(7 - folderaddr[yy], xx, yy - pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 3)
            {
      //top-side to front-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(7 - LED_Old[7 - yy], xx, yy + oldpullback[yy], 0, 0, 0);
                        LED(7 - folderaddr[7 - yy], xx, yy + pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 1)
            {
      //top-side to right
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(7 - LED_Old[7 - yy], yy + oldpullback[yy], xx, 0, 0, 0);
                        LED(7 - folderaddr[7 - yy], yy + pullback[yy], xx, ranx, rany, ranz);
                    }
                }
            }
        }//top

        if (right == 1)
        {
            if (side == 4)
            {
      //right-side to top
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy + oldpullback[7 - yy], 7 - LED_Old[7 - yy], xx, 0, 0, 0);
                        LED(yy + pullback[7 - yy], 7 - folderaddr[7 - yy], xx, ranx, rany, ranz);
                    }
                }
            }
            if (side == 3)
            {
      //right-side to front-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, 7 - LED_Old[7 - yy], yy + oldpullback[yy], 0, 0, 0);
                        LED(xx, 7 - folderaddr[7 - yy], yy + pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 2)
            {
      //right-side to back-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, 7 - LED_Old[yy], yy - oldpullback[yy], 0, 0, 0);
                        LED(xx, 7 - folderaddr[yy], yy - pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 5)
            {
      //right-side to bottom
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy - oldpullback[yy], 7 - LED_Old[yy], xx, 0, 0, 0);
                        LED(yy - pullback[yy], 7 - folderaddr[yy], xx, ranx, rany, ranz);
                    }
                }
            }
        }//right

        if (left == 1)
        {
            if (side == 4)
            {
      //left-side to top
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy + oldpullback[yy], LED_Old[7 - yy], xx, 0, 0, 0);
                        LED(yy + pullback[yy], folderaddr[7 - yy], xx, ranx, rany, ranz);
                    }
                }
            }
            if (side == 3)
            {
      //left-side to front-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, LED_Old[7 - yy], yy + oldpullback[yy], 0, 0, 0);
                        LED(xx, folderaddr[7 - yy], yy + pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 2)
            {
      //left-side to back-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, LED_Old[yy], yy - oldpullback[yy], 0, 0, 0);
                        LED(xx, folderaddr[yy], yy - pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 5)
            {
      //left-side to bottom
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy - oldpullback[yy], LED_Old[yy], xx, 0, 0, 0);
                        LED(yy - pullback[yy], folderaddr[yy], xx, ranx, rany, ranz);
                    }
                }
            }
        }//left


        if (back == 1)
        {
            if (side == 1)
            {
      //back-side to right-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, yy + oldpullback[yy], LED_Old[7 - yy], 0, 0, 0);
                        LED(xx, yy + pullback[yy], folderaddr[7 - yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 4)
            {
      // back-side to top-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy + oldpullback[yy], xx, LED_Old[7 - yy], 0, 0, 0);
                        LED(yy + pullback[yy], xx, folderaddr[7 - yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 5)
            {
      // back-side to bottom
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy - oldpullback[yy], xx, LED_Old[yy], 0, 0, 0);
                        LED(yy - pullback[yy], xx, folderaddr[yy], ranx, rany, ranz);
                    }
                }
            }//state1
            if (side == 0)
            {
      //back-side to left-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, yy - oldpullback[yy], LED_Old[yy], 0, 0, 0);
                        LED(xx, yy - pullback[yy], folderaddr[yy], ranx, rany, ranz);
                    }
                }
            }
        }//back
        if (bot == 1)
        {
            if (side == 1)
            {
      // bottom-side to right-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(LED_Old[7 - yy], yy + oldpullback[yy], xx, 0, 0, 0);
                        LED(folderaddr[7 - yy], yy + pullback[yy], xx, ranx, rany, ranz);
                    }
                }
            }
            if (side == 3)
            {
      //bottom to front-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(LED_Old[7 - yy], xx, yy + oldpullback[yy], 0, 0, 0);
                        LED(folderaddr[7 - yy], xx, yy + pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 2)
            {
      //bottom to back-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(LED_Old[yy], xx, yy - oldpullback[yy], 0, 0, 0);
                        LED(folderaddr[yy], xx, yy - pullback[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 0)
            {
      //bottom to left-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(LED_Old[yy], yy - oldpullback[yy], xx, 0, 0, 0);
                        LED(folderaddr[yy], yy - pullback[yy], xx, ranx, rany, ranz);
                    }
                }
            }
        }//bot

        if (front == 1)
        {
            if (side == 0)
            {
      //front-side to left-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, yy - oldpullback[yy], 7 - LED_Old[yy], 0, 0, 0);
                        LED(xx, yy - pullback[yy], 7 - folderaddr[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 5)
            {
      // front-side to bottom
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy - oldpullback[yy], xx, 7 - LED_Old[yy], 0, 0, 0);
                        LED(yy - pullback[yy], xx, 7 - folderaddr[yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 4)
            {
      // front-side to top-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(yy + oldpullback[yy], xx, 7 - LED_Old[7 - yy], 0, 0, 0);
                        LED(yy + pullback[yy], xx, 7 - folderaddr[7 - yy], ranx, rany, ranz);
                    }
                }
            }
            if (side == 1)
            {
      //front-side to right-side
                for (yy = 0; yy < 8; yy++)
                {
                    for (xx = 0; xx < 8; xx++)
                    {
                        LED(xx, yy + oldpullback[yy], 7 - LED_Old[7 - yy], 0, 0, 0);
                        LED(xx, yy + pullback[yy], 7 - folderaddr[7 - yy], ranx, rany, ranz);
                    }
                }
            }
        }//front




        delay(5);//               DELAY   DELAY  DELAY
        for (xx = 0; xx < 8; xx++)
        {
            LED_Old[xx] = folderaddr[xx];
            oldpullback[xx] = pullback[xx];
        }





        if (folderaddr[7] == 7)
        {
    // pullback=8;
            for (zz = 0; zz < 8; zz++)
                pullback[zz] = pullback[zz] + 1;

            if (pullback[7] == 8)
            {//finished with fold
                delay(10);
                  //state++;
                  //if(state==4)
                  //state=0;

                ranselect = random(3);
                if (ranselect == 0)
                {
                    ranx = 0;
                    rany = random(1, 16);
                    ranz = random(1, 16);
                }
                if (ranselect == 1)
                {
                    ranx = random(1, 16);
                    rany = 0;
                    ranz = random(1, 16);
                }
                if (ranselect == 2)
                {
                    ranx = random(1, 16);
                    rany = random(1, 16);
                    ranz = 0;
                }

                side_select = random(3);

                if (top == 1)
                {//                 TOP
                    top = 0;
                    if (side == 0)
                    {//top to left
                        left = 1;
                        if (side_select == 0) side = 2;
                        if (side_select == 1) side = 3;
                        //if(side_select==2) side=4;
                        if (side_select == 2) side = 5;
                    }
                    else
                        if (side == 1)
                        {//top to right
                            right = 1;
                            if (side_select == 0) side = 5;
                            if (side_select == 1) side = 2;
                            if (side_select == 2) side = 3;
                            //if(side_select==3) side=4;
                        }
                        else
                            if (side == 2)
                            {//top to back
                                back = 1;
                                if (side_select == 0) side = 0;
                                if (side_select == 1) side = 1;
                                if (side_select == 2) side = 5;
                                //if(side_select==3) side=4;
                            }
                            else
                                if (side == 3)
                                {//top to front
                                    front = 1;
                                    if (side_select == 0) side = 0;
                                    if (side_select == 1) side = 1;
                                    if (side_select == 2) side = 5;
                                    //if(side_select==3) side=4;
                                }
                }
                else//top
                    if (bot == 1)
                    {//                 BOTTOM
                        bot = 0;
                        if (side == 0)
                        {//bot to left
                            left = 1;
                            if (side_select == 0) side = 2;
                            if (side_select == 1) side = 3;
                            if (side_select == 2) side = 4;
                            //if(side_select==3) side=5;
                        }
                        else
                            if (side == 1)
                            {//bot to right
                                right = 1;
                                //if(side_select==0) side=5;
                                if (side_select == 0) side = 2;
                                if (side_select == 1) side = 3;
                                if (side_select == 2) side = 4;
                            }
                            else
                                if (side == 2)
                                {//bot to back
                                    back = 1;
                                    if (side_select == 0) side = 0;
                                    if (side_select == 1) side = 1;
                                    //if(side_select==2) side=5;
                                    if (side_select == 2) side = 4;
                                }
                                else
                                    if (side == 3)
                                    {//bot to front
                                        front = 1;
                                        if (side_select == 0) side = 0;
                                        if (side_select == 1) side = 1;
                                        //if(side_select==2) side=5;
                                        if (side_select == 2) side = 4;
                                    }
                    }
                    else//bot
                        if (right == 1)
                        {//                 RIGHT
                            right = 0;
                            if (side == 4)
                            {//right to top
                                top = 1;
                                if (side_select == 0) side = 2;
                                if (side_select == 1) side = 3;
                                if (side_select == 2) side = 0;
                                //if(side_select==3) side=1;
                            }
                            else
                                if (side == 5)
                                {//right to bot
                                    bot = 1;
                                    if (side_select == 0) side = 0;
                                    if (side_select == 1) side = 2;
                                    if (side_select == 2) side = 3;
                                    //if(side_select==3) side=1;
                                }
                                else
                                    if (side == 2)
                                    {//right to back
                                        back = 1;
                                        if (side_select == 0) side = 0;
                                        //if(side_select==1) side=1;
                                        if (side_select == 1) side = 5;
                                        if (side_select == 2) side = 4;
                                    }
                                    else
                                        if (side == 3)
                                        {//right to front
                                            front = 1;
                                            if (side_select == 0) side = 0;
                                            //if(side_select==1) side=1;
                                            if (side_select == 1) side = 5;
                                            if (side_select == 2) side = 4;
                                        }
                        }
                        else//bot
                            if (left == 1)
                            {//                 LEFT
                                left = 0;
                                if (side == 4)
                                {//left to top
                                    top = 1;
                                    //if(side_select==0) side=2;
                                    if (side_select == 0) side = 3;
                                    if (side_select == 1) side = 2;
                                    if (side_select == 2) side = 1;
                                }
                                else
                                    if (side == 5)
                                    {//left to bot
                                        bot = 1;
                                        //if(side_select==0) side=0;
                                        if (side_select == 0) side = 2;
                                        if (side_select == 1) side = 3;
                                        if (side_select == 2) side = 1;
                                    }
                                    else
                                        if (side == 2)
                                        {//left to back
                                            back = 1;
                                            //if(side_select==0) side=0;
                                            if (side_select == 0) side = 1;
                                            if (side_select == 1) side = 5;
                                            if (side_select == 2) side = 4;
                                        }
                                        else
                                            if (side == 3)
                                            {//left to front
                                                front = 1;
                                                //if(side_select==0) side=0;
                                                if (side_select == 0) side = 1;
                                                if (side_select == 1) side = 5;
                                                if (side_select == 2) side = 4;
                                            }
                            }
                            else//bot
                                if (front == 1)
                                {//                 front
                                    front = 0;
                                    if (side == 4)
                                    {//front to top
                                        top = 1;
                                        if (side_select == 0) side = 2;
                                        //if(side_select==1) side=3;
                                        if (side_select == 1) side = 0;
                                        if (side_select == 2) side = 1;
                                    }
                                    else
                                        if (side == 5)
                                        {//front to bot
                                            bot = 1;
                                            if (side_select == 0) side = 0;
                                            if (side_select == 1) side = 2;
                                            //if(side_select==2) side=3;
                                            if (side_select == 2) side = 1;
                                        }
                                        else
                                            if (side == 0)
                                            {//front to left
                                                left = 1;
                                                if (side_select == 0) side = 2;
                                               // if(side_select==1) side=3;
                                                if (side_select == 1) side = 5;
                                                if (side_select == 2) side = 4;
                                            }
                                            else
                                                if (side == 1)
                                                {//front to right
                                                    right = 1;
                                                    if (side_select == 0) side = 2;
                                                   // if(side_select==1) side=3;
                                                    if (side_select == 1) side = 5;
                                                    if (side_select == 2) side = 4;
                                                }
                                }
                                else//bot
                                    if (back == 1)
                                    {//                 back
                                        back = 0;
                                        if (side == 4)
                                        {//back to top
                                            top = 1;
                                            //if(side_select==0) side=2;
                                            if (side_select == 0) side = 3;
                                            if (side_select == 1) side = 0;
                                            if (side_select == 2) side = 1;
                                        }
                                        else
                                            if (side == 5)
                                            {//back to bot
                                                bot = 1;
                                                if (side_select == 0) side = 0;
                                                //if(side_select==1) side=2;
                                                if (side_select == 1) side = 3;
                                                if (side_select == 2) side = 1;
                                            }
                                            else
                                                if (side == 0)
                                                {//back to left
                                                    left = 1;
                                                    //if(side_select==0) side=2;
                                                    if (side_select == 0) side = 3;
                                                    if (side_select == 1) side = 5;
                                                    if (side_select == 2) side = 4;
                                                }
                                                else
                                                    if (side == 1)
                                                    {//back to right
                                                        right = 1;
                                                        //if(side_select==0) side=2;
                                                        if (side_select == 0) side = 3;
                                                        if (side_select == 1) side = 5;
                                                        if (side_select == 2) side = 4;
                                                    }
                                    } //bot


                                     // for(yy=0; yy<8; yy++)
                                 //for(xx=0; xx<8; xx++)
                                 //LED(LED_Old[yy], xx, yy-oldpullback[yy], 0, 0, 0);
                for (xx = 0; xx < 8; xx++)
                {
                    oldpullback[xx] = 0;
                    pullback[xx] = 0;
                }

                folderaddr[0] = -8;
                folderaddr[1] = -7;
                folderaddr[2] = -6;
                folderaddr[3] = -5;
                folderaddr[4] = -4;
                folderaddr[5] = -3;
                folderaddr[6] = -2;
                folderaddr[7] = -1;

            }//pullback==7
        }//folderaddr==7    

        if (folderaddr[7] != 7)
            for (zz = 0; zz < 8; zz++)
                folderaddr[zz] = folderaddr[zz] + 1;

    }//while





}//folder


void bouncyvTwo()
{//****bouncyTwo****bouncyTwo****bouncyTwo****bouncyTwo****bouncyTwo****bouncyTwo****bouncyTwo
    int wipex, wipey, wipez, ranr, rang, ranb, select, oldx[50], oldy[50], oldz[50];
    int x[50], y[50], z[50], addr, ledcount = 20, direct, direcTwo;
    int xx[50], yy[50], zz[50];
    int xbit = 1, ybit = 1, zbit = 1;
    for (addr = 0; addr < ledcount + 1; addr++)
    {
        oldx[addr] = 0;
        oldy[addr] = 0;
        oldz[addr] = 0;
        x[addr] = 0;
        y[addr] = 0;
        z[addr] = 0;
        xx[addr] = 0;
        yy[addr] = 0;
        zz[addr] = 0;

    }

    start = millis();

    while (millis() - start < 15000)
    {
        direct = random(3);

        for (addr = 1; addr < ledcount + 1; addr++)
        {
            LED(oldx[addr], oldy[addr], oldz[addr], 0, 0, 0);
            LED(x[addr], y[addr], z[addr], xx[addr], yy[addr], zz[addr]);
        }

        for (addr = 1; addr < ledcount + 1; addr++)
        {
            oldx[addr] = x[addr];
            oldy[addr] = y[addr];
            oldz[addr] = z[addr];
        }
        delay(20);


        //direcTwo=random(3);  
        //if(direcTwo==1)



        if (direct == 0)
            x[0] = x[0] + xbit;
        if (direct == 1)
            y[0] = y[0] + ybit;
        if (direct == 2)
            z[0] = z[0] + zbit;

        if (direct == 3)
            x[0] = x[0] - xbit;
        if (direct == 4)
            y[0] = y[0] - ybit;
        if (direct == 5)
            z[0] = z[0] - zbit;





        if (x[0] > 7)
        {
            xbit = -1;
            x[0] = 7;
            xx[0] = random(16);
            yy[0] = random(16);
            zz[0] = 0;
            //wipe_out();
        }
        if (x[0] < 0)
        {
            xbit = 1;
            x[0] = 0;
            xx[0] = random(16);
            yy[0] = 0;
            zz[0] = random(16);
            //wipe_out();
        }
        if (y[0] > 7)
        {
            ybit = -1;
            y[0] = 7;
            xx[0] = 0;
            yy[0] = random(16);
            zz[0] = random(16);
            //wipe_out();
        }
        if (y[0] < 0)
        {
            ybit = 1;
            y[0] = 0;
            xx[0] = 0;
            yy[0] = random(16);
            zz[0] = random(16);
            //wipe_out();
        }
        if (z[0] > 7)
        {
            zbit = -1;
            z[0] = 7;
            xx[0] = random(16);
            yy[0] = 0;
            zz[0] = random(16);
            //wipe_out();
        }
        if (z[0] < 0)
        {
            zbit = 1;
            z[0] = 0;
            xx[0] = random(16);
            yy[0] = random(16);
            zz[0] = 0;
            //wipe_out();
        }

        for (addr = ledcount; addr > 0; addr--)
        {
            x[addr] = x[addr - 1];
            y[addr] = y[addr - 1];
            z[addr] = z[addr - 1];
            xx[addr] = xx[addr - 1];
            yy[addr] = yy[addr - 1];
            zz[addr] = zz[addr - 1];
        }


    }//while





}//bouncyv2
void sinwaveTwo()
{//*****sinewaveTwo*****sinewaveTwo*****sinewaveTwo*****sinewaveTwo*****sinewaveTwo*****sinewaveTwo
    int sinewavearray[8], addr, sinemult[8], colselect, rr = 0, gg = 0, bb = 15, addrt;
    int sinewavearrayOLD[8], select, subZ = -7, subT = 7, multi = 0;//random(-1, 2);
    sinewavearray[0] = 0;
    sinemult[0] = 1;
    sinewavearray[1] = 1;
    sinemult[1] = 1;
    sinewavearray[2] = 2;
    sinemult[2] = 1;
    sinewavearray[3] = 3;
    sinemult[3] = 1;
    sinewavearray[4] = 4;
    sinemult[4] = 1;
    sinewavearray[5] = 5;
    sinemult[5] = 1;
    sinewavearray[6] = 6;
    sinemult[6] = 1;
    sinewavearray[7] = 7;
    sinemult[7] = 1;

    start = millis();

    while (millis() - start < 15000)
    {
        for (addr = 0; addr < 8; addr++)
        {
            if (sinewavearray[addr] == 7)
            {
                sinemult[addr] = -1;
            }
            if (sinewavearray[addr] == 0)
            {
                sinemult[addr] = 1;
            }
            sinewavearray[addr] = sinewavearray[addr] + sinemult[addr];
        }//addr
        if (sinewavearray[0] == 7)
        {
            select = random(3);
            if (select == 0)
            {
                rr = random(1, 16);
                gg = random(1, 16);
                bb = 0;
            }
            if (select == 1)
            {
                rr = random(1, 16);
                gg = 0;
                bb = random(1, 16);
            }
            if (select == 2)
            {
                rr = 0;
                gg = random(1, 16);
                bb = random(1, 16);
            }
      /*
      if(multi==1)
      multi=0;
      else
      multi=1;
      */

        }



        for (addr = 0; addr < 8; addr++)
        {
            LED(sinewavearrayOLD[addr], addr, 0, 0, 0, 0);
            LED(sinewavearrayOLD[addr], 0, addr, 0, 0, 0);
            LED(sinewavearrayOLD[addr], subT - addr, 7, 0, 0, 0);
            LED(sinewavearrayOLD[addr], 7, subT - addr, 0, 0, 0);
            LED(sinewavearray[addr], addr, 0, rr, gg, bb);
            LED(sinewavearray[addr], 0, addr, rr, gg, bb);
            LED(sinewavearray[addr], subT - addr, 7, rr, gg, bb);
            LED(sinewavearray[addr], 7, subT - addr, rr, gg, bb);
        }//}

        for (addr = 1; addr < 7; addr++)
        {
            LED(sinewavearrayOLD[addr + multi * 1], addr, 1, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 1], 1, addr, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 1], subT - addr, 6, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 1], 6, subT - addr, 0, 0, 0);
            LED(sinewavearray[addr + multi * 1], addr, 1, rr, gg, bb);
            LED(sinewavearray[addr + multi * 1], 1, addr, rr, gg, bb);
            LED(sinewavearray[addr + multi * 1], subT - addr, 6, rr, gg, bb);
            LED(sinewavearray[addr + multi * 1], 6, subT - addr, rr, gg, bb);
        }

        for (addr = 2; addr < 6; addr++)
        {
            LED(sinewavearrayOLD[addr + multi * 2], addr, 2, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 2], 2, addr, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 2], subT - addr, 5, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 2], 5, subT - addr, 0, 0, 0);
            LED(sinewavearray[addr + multi * 2], addr, 2, rr, gg, bb);
            LED(sinewavearray[addr + multi * 2], 2, addr, rr, gg, bb);
            LED(sinewavearray[addr + multi * 2], subT - addr, 5, rr, gg, bb);
            LED(sinewavearray[addr + multi * 2], 5, subT - addr, rr, gg, bb);
        }
        for (addr = 3; addr < 5; addr++)
        {
            LED(sinewavearrayOLD[addr + multi * 3], addr, 3, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 3], 3, addr, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 3], subT - addr, 4, 0, 0, 0);
            LED(sinewavearrayOLD[addr + multi * 3], 4, subT - addr, 0, 0, 0);
            LED(sinewavearray[addr + multi * 3], addr, 3, rr, gg, bb);
            LED(sinewavearray[addr + multi * 3], 3, addr, rr, gg, bb);
            LED(sinewavearray[addr + multi * 3], subT - addr, 4, rr, gg, bb);
            LED(sinewavearray[addr + multi * 3], 4, subT - addr, rr, gg, bb);
        }

        for (addr = 0; addr < 8; addr++)
            sinewavearrayOLD[addr] = sinewavearray[addr];
        delay(30);



    }//while


}//SinewaveTwo

void color_wheel()
{
    int xx, yy, zz, ww, rr = 1, gg = 1, bb = 1, ranx, rany, swiper;

    start = millis();

    while (millis() - start < 100000)
    {
        swiper = random(3);
        ranx = random(16);
        rany = random(16);

        for (xx = 0;xx < 8;xx++)
        {
            for (yy = 0;yy < 8;yy++)
            {
                for (zz = 0;zz < 8;zz++)
                {

                    LED(xx, yy, zz, ranx, 0, rany);
                }
            }
            delay(50);
        }

        ranx = random(16);
        rany = random(16);

        for (xx = 7;xx >= 0;xx--)
        {
            for (yy = 0;yy < 8;yy++)
            {
                for (zz = 0;zz < 8;zz++)
                {
                    LED(xx, yy, zz, ranx, rany, 0);
                }
            }
            delay(50);
        }
        ranx = random(16);
        rany = random(16);
        for (xx = 0;xx < 8;xx++)
        {
            for (yy = 0;yy < 8;yy++)
            {
                for (zz = 0;zz < 8;zz++)
                {
                    LED(xx, yy, zz, 0, ranx, rany);
                }
            }
            delay(50);
        }

        ranx = random(16);
        rany = random(16);
        for (xx = 7;xx >= 0;xx--)
        {
            for (yy = 0;yy < 8;yy++)
            {
                for (zz = 0;zz < 8;zz++)
                {
                    LED(xx, yy, zz, rany, ranx, 0);
                }
            }
            delay(50);
        }

    }//while

}//color wheel

void color_wheelTWO()
{//*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo*****colorWheelTwo
    int xx, yy, zz, ww, rr = 1, gg = 1, bb = 1, ranx, rany, ranz, select, swiper;

    start = millis();

    while (millis() - start < 10000)
    {
        swiper = random(6);
        select = random(3);
        if (select == 0)
        {
            ranx = 0;
            rany = random(16);
            ranz = random(16);
        }
        if (select == 1)
        {
            ranx = random(16);
            rany = 0;
            ranz = random(16);
        }
        if (select == 2)
        {
            ranx = random(16);
            rany = random(16);
            ranz = 0;
        }


        if (swiper == 0)
        {
            for (yy = 0;yy < 8;yy++)
            {//left to right
                for (xx = 0;xx < 8;xx++)
                {
                    for (zz = 0;zz < 8;zz++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }
        if (swiper == 1)
        {//bot to top
            for (xx = 0;xx < 8;xx++)
            {
                for (yy = 0;yy < 8;yy++)
                {
                    for (zz = 0;zz < 8;zz++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }
        if (swiper == 2)
        {//back to front
            for (zz = 0;zz < 8;zz++)
            {
                for (xx = 0;xx < 8;xx++)
                {
                    for (yy = 0;yy < 8;yy++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }
        if (swiper == 3)
        {
            for (yy = 7;yy >= 0;yy--)
            {//right to left
                for (xx = 0;xx < 8;xx++)
                {
                    for (zz = 0;zz < 8;zz++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }
        if (swiper == 4)
        {//top to bot
            for (xx = 7;xx >= 0;xx--)
            {
                for (yy = 0;yy < 8;yy++)
                {
                    for (zz = 0;zz < 8;zz++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }
        if (swiper == 5)
        {//front to back
            for (zz = 7;zz >= 0;zz--)
            {
                for (xx = 0;xx < 8;xx++)
                {
                    for (yy = 0;yy < 8;yy++)
                    {
                        LED(xx, yy, zz, ranx, ranz, rany);
                    }
                }
                delay(30);
            }
        }




    }//while

}//color wheel

//    Harlem Shake    Harlem Shake    Harlem Shake    Harlem Shake    Harlem Shake

void harlem_shake()
{



    int greenx = random(1, 7), greeny = random(1, 7), bluex = random(1, 7), bluey = random(1, 7), redx = random(1, 7), redy = random(1, 7);
    int greenmult = 1, bluemult = 1, redmult = 1;
    int greenmulty = 1, bluemulty = 1, redmulty = 1;
    int oredx, oredy, obluex, obluey, ogreenx, ogreeny, cb1 = 15, cb2 = 0, cr1 = 15, cr2 = 0, cg1 = 15, cg2 = 0;
    int time_counter = 10, timemult = 2;
    int m;
    int c1 = 1, c2 = 1, c3 = 1, xmult = 1, ymult = 1, zmult = 1, x = 4, y = 4, z = 4, color_select, xo, yo, zo;
    int c21 = 1, c22 = 1, c23 = 1, x2mult = 1, y2mult = 1, z2mult = 1, x2 = 2, y2 = 2, z2 = 2, color_select2, x2o, y2o, z2o;

    int counter, i, j, k;
    for (counter = 0; counter < 150; counter++)
    {
        for (i = 0; i < 8; i++)
        {
            LED(i, oredx, oredx, 0, 0, 0);
        }
        for (i = 0; i < 8; i++)
        {
            LED(i, redx, redx, 15, 0, 0);
        }

        oredx = redx;
        oredy = redy;

        for (i = 100; i > time_counter; i--)
            delay(1);

        time_counter = time_counter + timemult;
        if (time_counter > 100 || time_counter < 10)
            timemult = timemult * -1;


        if (redy > 6 || redy < 1)
        {
            redmulty = redmulty * -1;

        }

        if (redx > 6 || redx < 1)
        {
            redmult = redmult * -1;

            cr1 = random(16);
            cr2 = random(16);
        }

        redy = redy + redmulty;
        redx = redx + redmult;
    }//counter


    for (counter = 0; counter < 85; counter++)
    {
        for (i = 0; i < 8; i++)
        {
            LED(i, oredx, oredx, 0, 0, 0);
            LED(ogreenx, i, ogreeny, 0, 0, 0);
        }
        for (i = 0; i < 8; i++)
        {
            LED(i, redx, redx, 15, 0, 0);
            LED(greenx, i, greeny, 0, 15, 0);
        }
        ogreenx = greenx;
        ogreeny = greeny;
        oredx = redx;
        oredy = redy;

        for (i = 100; i > time_counter; i--)
            delay(1);

        time_counter = time_counter + timemult;
        if (time_counter > 100 || time_counter < 10)
            timemult = timemult * -1;


        if (greeny > 6 || greeny < 1)
            greenmulty = greenmulty * -1;

        if (redy > 6 || redy < 1)
        {
            redmulty = redmulty * -1;

        }


        if (greenx > 6 || greenx < 1)
        {
            greenmult = greenmult * -1;
            greeny = greeny + greenmulty;
            cg1 = random(16);
            cg2 = random(16);
        }

        if (redx > 6 || redx < 1)
        {
            redmult = redmult * -1;

            cr1 = random(16);
            cr2 = random(16);
        }
        greenx = greenx + greenmult;

        redy = redy + redmulty;
        redx = redx + redmult;
    }//counter


    for (counter = 0; counter < 85; counter++)
    {
        for (i = 0; i < 8; i++)
        {
            LED(i, oredx, oredx, 0, 0, 0);
            LED(obluey, obluex, i, 0, 0, 0);
            LED(ogreenx, i, ogreeny, 0, 0, 0);
        }
        for (i = 0; i < 8; i++)
        {
            LED(i, redx, redx, 15, 0, 0);
            LED(bluey, bluex, i, 0, 0, 15);
            LED(greenx, i, greeny, 0, 15, 0);
        }
        ogreenx = greenx;
        ogreeny = greeny;
        obluex = bluex;
        obluey = bluey;
        oredx = redx;
        oredy = redy;

        for (i = 100; i > time_counter; i--)
            delay(1);

        time_counter = time_counter + timemult;
        if (time_counter > 100 || time_counter < 10)
            timemult = timemult * -1;


        if (greeny > 6 || greeny < 1)
            greenmulty = greenmulty * -1;

        if (bluey > 6 || bluey < 1)
            bluemulty = bluemulty * -1;

        if (redy > 6 || redy < 1)
        {
            redmulty = redmulty * -1;

        }


        if (greenx > 6 || greenx < 1)
        {
            greenmult = greenmult * -1;
            greeny = greeny + greenmulty;
            cg1 = random(16);
            cg2 = random(16);
        }
        if (bluex > 6 || bluex < 1)
        {
            bluemult = bluemult * -1;
            bluey = bluey + bluemulty;
            cb1 = random(16);
            cb2 = random(16);
        }
        if (redx > 6 || redx < 1)
        {
            redmult = redmult * -1;

            cr1 = random(16);
            cr2 = random(16);
        }
        greenx = greenx + greenmult;
        bluex = bluex + bluemult;
        redy = redy + redmulty;
        redx = redx + redmult;
    }//counter



    for (counter = 0; counter < 3; counter++)
    {
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, 15, 15, 15);
        delay(50);
        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, 0, 0, 0);
        delay(50);
    }//counter

    for (m = 0; m < 1; m++)
    {


        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, 0, random(16), random(16));

        for (i = 7; i >= 0; i--)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, random(16), 0, random(16));

        for (i = 0; i < 8; i++)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, random(16), random(16), 0);

        for (i = 7; i >= 0; i--)
            for (j = 0; j < 8; j++)
                for (k = 0; k < 8; k++)
                    LED(i, j, k, random(16), 0, random(16));
    }

    clean();


    for (m = 0; m < 3; m++)
    {
        for (k = 0; k < 200; k++)
        {
            LED(random(8), random(8), random(8), random(16), random(16), 0);
            LED(random(8), random(8), random(8), random(16), 0, random(16));
            LED(random(8), random(8), random(8), 0, random(16), random(16));
             //   c1=random(8);
               // c2=random(8);
                //c3=random(8);
            //LED(c1,c2,c3,15,15,15);
        }
        for (k = 0; k < 200; k++)
        {
            LED(random(8), random(8), random(8), 0, 0, 0);
        }

    }//m




    clean();


    color_select = random(0, 3);
    if (color_select == 0)
    {
        c1 = 0;
        c2 = random(0, 16);
        c3 = random(0, 16);
    }
    if (color_select == 1)
    {
        c1 = random(0, 16);
        c2 = 0;
        c3 = random(0, 16);
    }
    if (color_select == 2)
    {
        c1 = random(0, 16);
        c2 = random(0, 16);
        c3 = 0;
    }


    color_select2 = random(0, 3);
    if (color_select2 == 0)
    {
        c21 = 0;
        c22 = random(0, 16);
        c23 = random(0, 16);
    }
    if (color_select2 == 1)
    {
        c21 = random(0, 16);
        c22 = 0;
        c23 = random(0, 16);
    }
    if (color_select2 == 2)
    {
        c21 = random(0, 16);
        c22 = random(0, 16);
        c23 = 0;
    }

    for (counter = 0; counter < 200; counter++)
    {

        LED(xo, yo, zo, 0, 0, 0);
        LED(xo + 1, yo, zo, 0, 0, 0);
        LED(xo + 2, yo, zo, 0, 0, 0);
        LED(xo - 1, yo, zo, 0, 0, 0);
        LED(xo - 2, yo, zo, 0, 0, 0);
        LED(xo, yo + 1, zo, 0, 0, 0);
        LED(xo, yo - 1, zo, 0, 0, 0);
        LED(xo, yo + 2, zo, 0, 0, 0);
        LED(xo, yo - 2, zo, 0, 0, 0);
        LED(xo, yo, zo - 1, 0, 0, 0);
        LED(xo, yo, zo + 1, 0, 0, 0);
        LED(xo, yo, zo - 2, 0, 0, 0);
        LED(xo, yo, zo + 2, 0, 0, 0);

        LED(x2o, y2o, z2o, 0, 0, 0);
        LED(x2o + 1, y2o, z2o, 0, 0, 0);
        LED(x2o + 2, y2o, z2o, 0, 0, 0);
        LED(x2o - 1, y2o, z2o, 0, 0, 0);
        LED(x2o - 2, y2o, z2o, 0, 0, 0);
        LED(x2o, y2o + 1, z2o, 0, 0, 0);
        LED(x2o, y2o - 1, z2o, 0, 0, 0);
        LED(x2o, y2o + 2, z2o, 0, 0, 0);
        LED(x2o, y2o - 2, z2o, 0, 0, 0);
        LED(x2o, y2o, z2o - 1, 0, 0, 0);
        LED(x2o, y2o, z2o + 1, 0, 0, 0);
        LED(x2o, y2o, z2o - 2, 0, 0, 0);
        LED(x2o, y2o, z2o + 2, 0, 0, 0);

        LED(xo + 1, yo + 1, zo, 0, 0, 0);
        LED(xo + 1, yo - 1, zo, 0, 0, 0);
        LED(xo - 1, yo + 1, zo, 0, 0, 0);
        LED(xo - 1, yo - 1, zo, 0, 0, 0);
        LED(xo + 1, yo + 1, zo + 1, 0, 0, 0);
        LED(xo + 1, yo - 1, zo + 1, 0, 0, 0);
        LED(xo - 1, yo + 1, zo + 1, 0, 0, 0);
        LED(xo - 1, yo - 1, zo + 1, 0, 0, 0);
        LED(xo + 1, yo + 1, zo - 1, 0, 0, 0);
        LED(xo + 1, yo - 1, zo - 1, 0, 0, 0);
        LED(xo - 1, yo + 1, zo - 1, 0, 0, 0);
        LED(xo - 1, yo - 1, zo - 1, 0, 0, 0);

        LED(x2o + 1, y2o + 1, z2o, 0, 0, 0);
        LED(x2o + 1, y2o - 1, z2o, 0, 0, 0);
        LED(x2o - 1, y2o + 1, z2o, 0, 0, 0);
        LED(x2o - 1, y2o - 1, z2o, 0, 0, 0);
        LED(x2o + 1, y2o + 1, z2o + 1, 0, 0, 0);
        LED(x2o + 1, y2o - 1, z2o + 1, 0, 0, 0);
        LED(x2o - 1, y2o + 1, z2o + 1, 0, 0, 0);
        LED(x2o - 1, y2o - 1, z2o + 1, 0, 0, 0);
        LED(x2o + 1, y2o + 1, z2o - 1, 0, 0, 0);
        LED(x2o + 1, y2o - 1, z2o - 1, 0, 0, 0);
        LED(x2o - 1, y2o + 1, z2o - 1, 0, 0, 0);
        LED(x2o - 1, y2o - 1, z2o - 1, 0, 0, 0);

        LED(x, y, z, c1, c2, c3);
        LED(x, y, z - 1, c1, c2, c3);
        LED(x, y, z + 1, c1, c2, c3);
        LED(x, y, z - 2, c1, c2, c3);
        LED(x, y, z + 2, c1, c2, c3);
        LED(x + 1, y, z, c1, c2, c3);
        LED(x - 1, y, z, c1, c2, c3);
        LED(x, y + 1, z, c1, c2, c3);
        LED(x, y - 1, z, c1, c2, c3);
        LED(x + 2, y, z, c1, c2, c3);
        LED(x - 2, y, z, c1, c2, c3);
        LED(x, y + 2, z, c1, c2, c3);
        LED(x, y - 2, z, c1, c2, c3);
        LED(x + 1, y + 1, z, c1, c2, c3);
        LED(x + 1, y - 1, z, c1, c2, c3);
        LED(x - 1, y + 1, z, c1, c2, c3);
        LED(x - 1, y - 1, z, c1, c2, c3);
        LED(x + 1, y + 1, z + 1, c1, c2, c3);
        LED(x + 1, y - 1, z + 1, c1, c2, c3);
        LED(x - 1, y + 1, z + 1, c1, c2, c3);
        LED(x - 1, y - 1, z + 1, c1, c2, c3);
        LED(x + 1, y + 1, z - 1, c1, c2, c3);
        LED(x + 1, y - 1, z - 1, c1, c2, c3);
        LED(x - 1, y + 1, z - 1, c1, c2, c3);
        LED(x - 1, y - 1, z - 1, c1, c2, c3);

        LED(x2, y2, z2, c21, c22, c23);
        LED(x2, y2, z2 - 1, c21, c22, c23);
        LED(x2, y2, z2 + 1, c21, c22, c23);
        LED(x2, y2, z2 - 2, c21, c22, c23);
        LED(x2, y2, z2 + 2, c21, c22, c23);
        LED(x2 + 1, y2, z2, c21, c22, c23);
        LED(x2 - 1, y2, z2, c21, c22, c23);
        LED(x2, y2 + 1, z2, c21, c22, c23);
        LED(x2, y2 - 1, z2, c21, c22, c23);
        LED(x2 + 2, y2, z2, c21, c22, c23);
        LED(x2 - 2, y2, z2, c21, c22, c23);
        LED(x2, y2 + 2, z2, c21, c22, c23);
        LED(x2, y2 - 2, z2, c21, c22, c23);
        LED(x2 + 1, y2 + 1, z2, c21, c22, c23);
        LED(x2 + 1, y2 - 1, z2, c21, c22, c23);
        LED(x2 - 1, y2 + 1, z2, c21, c22, c23);
        LED(x2 - 1, y2 - 1, z2, c21, c22, c23);
        LED(x2 + 1, y2 + 1, z2 + 1, c21, c22, c23);
        LED(x2 + 1, y2 - 1, z2 + 1, c21, c22, c23);
        LED(x2 - 1, y2 + 1, z2 + 1, c21, c22, c23);
        LED(x2 - 1, y2 - 1, z2 + 1, c21, c22, c23);
        LED(x2 + 1, y2 + 1, z2 - 1, c21, c22, c23);
        LED(x2 + 1, y2 - 1, z2 - 1, c21, c22, c23);
        LED(x2 - 1, y2 + 1, z2 - 1, c21, c22, c23);
        LED(x2 - 1, y2 - 1, z2 - 1, c21, c22, c23);





        x2o = x2;
        y2o = y2;
        z2o = z2;

        xo = x;
        yo = y;
        zo = z;

        delay(45);

        x = x + xmult;
        y = y + ymult;
        z = z + zmult;

        x2 = x2 + x2mult;
        y2 = y2 + y2mult;
        z2 = z2 + z2mult;

        if (x >= 7)
        {
    //x=7;
            xmult = random(-1, 1);
        }
        if (y >= 7)
        {
    //y=7;
            ymult = random(-1, 1);
        }
        if (z >= 7)
        {
    //z=7;
            zmult = random(-1, 1);
        }
        if (x <= 0)
        {
    //x=0;
            xmult = random(0, 2);
        }
        if (y <= 0)
        {
    //y=0;
            ymult = random(0, 2);
        }
        if (z <= 0)
        {
    //z=0;
            zmult = random(0, 2);
        }

        if (x2 >= 7)
        {
    //x=7;
            x2mult = random(-1, 1);
        }
        if (y2 >= 7)
        {
    //y=7;
            y2mult = random(-1, 1);
        }
        if (z2 >= 7)
        {
    //z=7;
            z2mult = random(-1, 1);
        }
        if (x2 <= 0)
        {
    //x=0;
            x2mult = random(0, 2);
        }
        if (y2 <= 0)
        {
    //y=0;
            y2mult = random(0, 2);
        }
        if (z <= 0)
        {
    //z=0;
            z2mult = random(0, 2);
        }




    }//counter  counter counter counter counter



    for (counter = 0; counter < 15; counter++)
    {
        color_select = random(0, 3);
        if (color_select == 0)
        {
            c1 = 0;
            c2 = random(0, 16);
            c3 = random(0, 16);
        }
        if (color_select == 1)
        {
            c1 = random(0, 16);
            c2 = 0;
            c3 = random(0, 16);
        }
        if (color_select == 2)
        {
            c1 = random(0, 16);
            c2 = random(0, 16);
            c3 = 0;
        }


        int num1 = -1, num2 = -4, num3 = -6, num4 = -10;
        for (m = 0; m < 20; m++)
        {

            num1++;
            num2++;
            num3++;
            num4++;


            for (i = 3; i < 5; i++)
            {
                LED(num1, i, 3, 0, 0, 0);
                LED(num1, 3, i, 0, 0, 0);
                LED(num1, 4, i, 0, 0, 0);
                LED(num1, i, 4, 0, 0, 0);
            }
            for (i = 3; i < 5; i++)
            {
                LED(num1 + 1, i, 4, c1, c2, c3);
                LED(num1 + 1, 4, i, c1, c2, c3);
                LED(num1 + 1, 3, i, c1, c2, c3);
                LED(num1 + 1, i, 3, c1, c2, c3);
            }
            for (i = 2; i < 6; i++)
            {
                LED(num2, i, 2, 0, 0, 0);
                LED(num2, 2, i, 0, 0, 0);
                LED(num2, 5, i, 0, 0, 0);
                LED(num2, i, 5, 0, 0, 0);
            }
            for (i = 2; i < 6; i++)
            {
                LED(num2 + 1, i, 2, c1, c2, c3);
                LED(num2 + 1, 2, i, c1, c2, c3);
                LED(num2 + 1, 5, i, c1, c2, c3);
                LED(num2 + 1, i, 5, c1, c2, c3);
            }
            for (i = 1; i < 7; i++)
            {
                LED(num3, i, 1, 0, 0, 0);
                LED(num3, 1, i, 0, 0, 0);
                LED(num3, 6, i, 0, 0, 0);
                LED(num3, i, 6, 0, 0, 0);
            }
            for (i = 1; i < 7; i++)
            {
                LED(num3 + 1, i, 1, c1, c2, c3);
                LED(num3 + 1, 1, i, c1, c2, c3);
                LED(num3 + 1, 6, i, c1, c2, c3);
                LED(num3 + 1, i, 6, c1, c2, c3);
            }
            for (i = 0; i < 8; i++)
            {
                LED(num4, i, 0, 0, 0, 0);
                LED(num4, 0, i, 0, 0, 0);
                LED(num4, 7, i, 0, 0, 0);
                LED(num4, i, 7, 0, 0, 0);
            }
            for (i = 0; i < 8; i++)
            {
                LED(num4 + 1, i, 0, c1, c2, c3);
                LED(num4 + 1, 0, i, c1, c2, c3);
                LED(num4 + 1, 7, i, c1, c2, c3);
                LED(num4 + 1, i, 7, c1, c2, c3);
            }
            //delay(1);
        }//m

        num1 = 8;
        num2 = 11;
        num3 = 13;
        num4 = 17;

        for (m = 0; m < 20; m++)
        {
            num1--;
            num2--;
            num3--;
            num4--;
            for (i = 3; i < 5; i++)
            {
                LED(num1, i, 3, 0, 0, 0);
                LED(num1, 3, i, 0, 0, 0);
                LED(num1, 4, i, 0, 0, 0);
                LED(num1, i, 4, 0, 0, 0);
            }
            for (i = 3; i < 5; i++)
            {
                LED(num1 - 1, i, 4, 0, 0, 15);
                LED(num1 - 1, 4, i, 0, 0, 15);
                LED(num1 - 1, 3, i, 0, 0, 15);
                LED(num1 - 1, i, 3, 0, 0, 15);
            }
            for (i = 2; i < 6; i++)
            {
                LED(num2, i, 2, 0, 0, 0);
                LED(num2, 2, i, 0, 0, 0);
                LED(num2, 5, i, 0, 0, 0);
                LED(num2, i, 5, 0, 0, 0);
            }
            for (i = 2; i < 6; i++)
            {
                LED(num2 - 1, i, 2, 0, 0, 15);
                LED(num2 - 1, 2, i, 0, 0, 15);
                LED(num2 - 1, 5, i, 0, 0, 15);
                LED(num2 - 1, i, 5, 0, 0, 15);
            }
            for (i = 1; i < 7; i++)
            {
                LED(num3, i, 1, 0, 0, 0);
                LED(num3, 1, i, 0, 0, 0);
                LED(num3, 6, i, 0, 0, 0);
                LED(num3, i, 6, 0, 0, 0);
            }
            for (i = 1; i < 7; i++)
            {
                LED(num3 - 1, i, 1, 0, 0, 15);
                LED(num3 - 1, 1, i, 0, 0, 15);
                LED(num3 - 1, 6, i, 0, 0, 15);
                LED(num3 - 1, i, 6, 0, 0, 15);
            }
            for (i = 0; i < 8; i++)
            {
                LED(num4, i, 0, 0, 0, 0);
                LED(num4, 0, i, 0, 0, 0);
                LED(num4, 7, i, 0, 0, 0);
                LED(num4, i, 7, 0, 0, 0);
            }
            for (i = 0; i < 8; i++)
            {
                LED(num4 - 1, i, 0, 0, 0, 15);
                LED(num4 - 1, 0, i, 0, 0, 15);
                LED(num4 - 1, 7, i, 0, 0, 15);
                LED(num4 - 1, i, 7, 0, 0, 15);
            }
            //delay(1);
        }//m

    }//counter

}//harlem SHake

void clean()
{
    int ii, jj, kk;
    for (ii = 0; ii < 8; ii++)
        for (jj = 0; jj < 8; jj++)
            for (kk = 0; kk < 8; kk++)
                LED(ii, jj, kk, 0, 0, 0);

}
