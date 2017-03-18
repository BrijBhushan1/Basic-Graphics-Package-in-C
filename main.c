#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include "mygraphics.h"

int main()
{
    int option;
    float x1, x2, y1, y2;
    float xc,yc,r ,rx ,ry;

    printf("1.Line Drawing(DDA algo)\n"
           "2.Line Drawing(Bresenham's Algo)\n"
           "3.Line Drawing(Wu's Algo)\n"
           "4.Polyline Drawing(Bresenham's Algo)\n"
           "5.Parallel line (Bresenham Algo)\n"
           "6.Circle(Cartesian Method)\n"
           "7.Circle(Parametric Algo)\n"
           "8.Ellipse(Cartesian method)\n"
           "9.Ellipse(Parametric Algo)\n"
           "10.Circle(Midpoint Algo)");

      printf("\n\n");
      printf("Select the option according your choice:\n");
      scanf("%d",&option);

    if(option==1)
        {
         mylineDDA(x1,y1,x2,y2);
        }

    else if(option==2)
        {
         mylineBresenhm(x1,y1,x2,y2);
        }
    else if(option==3)
        {
          mylineWuAlgo(x1,y1,x2,y2);
        }
    else if(option==4)
        {
           mypolylineBresenhm(x1,y1,x2,y2);
        }
    else if(option==5)
        {
     myparallelline(x1,y1,x2,y2);
        }
    else if(option==6)
       {
        mycircle_cartesian(xc,yc,r);
       }
    else if(option==7)
        {
            mycircle_parametric(xc,yc,r);
        }
    else if(option==8)
        {
          myellipse_cartesian(xc,yc,rx,ry);
        }
    else if(option==9)
        {
          myellipse_parametric(xc,yc,rx,ry);
        }
     else if(option==10)
        {
          mycircle_midpoint(xc,yc,r);
        }
    else
        printf("Plz enter according to the option shown on the screen:\n\n");
    }

