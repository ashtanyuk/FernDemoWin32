#pragma once

#include "resource.h"
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define MAXIT 20
#define XSIZE 90
#define YSIZE 90
#define XSHIFT 300


// Fern fractal
// http://algolist.manual.ru/graphics/fern.php

class Fern
{
	double x,y,newx,newy;
	int count;
public:
	Fern()
	{
		srand (time(NULL));		
	}
	void setCount(int N){count=N;}
	void Draw(HDC hdc)
	{
		while (--count)
		{
			int i,rand_num;
			x = (double) rand() / 50000.0;
			y = (double) rand() / 50000.0;
			for (i = 0; i < MAXIT; i++)
			{
				rand_num = rand();
				if (rand_num < 0.01 * RAND_MAX)
		        {
					newx = 0;
					newy = 0.16 * y;
					x = newx;
					y = newy;
				 }
				else
				if (rand_num < 0.86 * RAND_MAX)
				{
					newx = (0.85 * x) + (0.04 * y);
					newy = (-0.04 * x) + (0.85 * y) + 1.6;
					x = newx;
					y = newy;
				}
				else
				if (rand_num < 0.93 * RAND_MAX)
				{
					newx = (0.2 * x) - (0.26 * y);
					newy = (0.23 * x) + (0.22 * y) + 1.6;
					x = newx;
                    y = newy;
                }
                else
                  {
                     newx = (-0.15 * x) + (0.28 * y);
                     newy = (0.26 * x) + (0.24 * y) + 0.44;
                     x = newx;
                     y = newy;
                  }
			}  /* for loop */
			//if ((x >= -5.0) && (x <= 5.0) && (y >= 0.0) && (y <= 10.0))
			 SetPixel(hdc,x*XSIZE+XSHIFT,y*YSIZE,RGB(0,0,0));
		 
	  } 
	}
};