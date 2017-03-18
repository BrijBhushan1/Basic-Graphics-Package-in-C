#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include "mygraphics.h"

//DDA Alogrithm for Line Drawing
void mylineDDA(float x1,float y1,float x2,float y2)
{
  printf("Enter the coordinates of the starting point:");
  scanf("%f%f",&x1,&y1);
  printf("Enter the coordinates of the ending point:");
  scanf("%f%f",&x2,&y2);

     initwindow(1000,1000);

  float x=500,y;
 for(y=0;y<=1000;y++)
  {
    putpixel(x,y,9);
  }
   y=500;
 for(x=0;x<=1000;x++)
 {
    putpixel(x,y,9);
 }
  x1 = x1 + 500;
  y1 = 500 - y1;

  x2 = 500 + x2;
  y2 = 500  - y2;

  float dx,dy, steps;

  dx = fabs( x2-x1);
  dy= fabs(y2-y1);

  if(dx>dy)
         steps=dx;
  else
    steps= dy;

 float deltaX,deltaY;

 deltaY= dy/steps;
 deltaX= dx/steps;

 putpixel(x1,y1,10);

 x=x1;
 y=y1;
 int k;
 for(k=1;k<steps;steps++)
 {
     x = x+deltaX;
     y = y+deltaY;
     putpixel(x,y,10);

 }
 delay(20000);
   closegraph();

}
// Bresenhm Alogrithm for Line Drawing

void mylineBresenhm(float x1,float y1,float x2,float y2)
{
     int gd = DETECT, gm;
      float dx, dy, p, end;
     // float x1, x2, y1, y2;
      float x, y;
      initgraph(&gd, &gm, "");
      printf("works only for M > 1");
      printf("Enter Value of X1: ");
      scanf("%f", &x1);
      printf("Enter Value of Y1: ");
      scanf("%f", &y1);
      printf("Enter Value of X2: ");
      scanf("%f", &x2);
      printf("Enter Value of Y2: ");
      scanf("%f", &y2);

      dx = abs(x1 - x2);
      dy = abs(y1 - y2);

      p = 2 * dy - dx;

      if(x1 > x2)
      {
            x = x2;
            y = y2;
            end = x1;
      }
      else
      {
            x = x1;
            y = y1;
            end = x2;
      }
      putpixel(x, y, 10);
      while(x < end)
      {
            x = x + 1;
            if(p < 0)
            {
                  p = p + 2 * dy;
            }
            else
            {
                  y = y + 1;
                  p = p + 2 * (dy - dx);
            }
            putpixel(x, y, RED);
      }
      delay(20000);
      closegraph();
}

void mylineWuAlgo (float x1,float y1,float x2,float y2)
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"");
    float dx,dy,m,r;
    float x,y,z,l;
    printf("start point  x1 =  ");
    scanf("%d",&x1);
    printf("start point  y1 =  ");
    scanf("%d",&y1);
    printf("last point  x2 =  ");
    scanf("%d",&x2);
    printf("last point  y2 =  ");
    scanf("%d",&y2);
   x=200;
    y=150;
    z=100;
    l=110;

    if(x>z)
    {
        m=x;
        x=z;
        z=m;
        m=y;
        y=l;
        l=m;
    }
    r=x;
    dx=z-x;
    dy=l-y;
    x=floor(x+1/2);
    y=y+m*(x-r);
    float yinter,xgap;
    yinter=y+m;
    xgap=x+(1/2)-r;
    putpixel(x,floor(y),((floor(y)+1-y)*xgap));
    putpixel(x,floor(y)+1,(y-(floor(y))*xgap));

    float xf,yf,xfgap,i;
    xf=floor(z+1/2);
    yf=l+m*(xf-z);
    xfgap=z+(1/2)-(floor(x+1/2));

    putpixel(xf,floor(yf),((floor(yf)+1-yf)*xfgap));
    putpixel(xf,floor(yf)+1,(yf-(floor(yf))*xfgap));
    for(i=x+1; i<xf-1; i++)
    {
        putpixel(r,floor(yinter),(floor(yinter)+1-yinter));
    putpixel(r,floor(yinter)+1,(yinter-(floor(yinter))+1));
      r=r+1;
      yinter=yinter+m+1;
    }
      delay(9000);
    closegraph();
}

void mypolylineBresenhm(float x1,float y1,float x2,float y2)
{
   int gd = DETECT, gm;
      float dx, dy, p, end;
//      float x1, x2, y1, y2;
      float x, y;
      initgraph(&gd, &gm, "");
      printf("works only for M > 1");
      printf("Enter Value of X1: ");
      scanf("%f", &x1);
      printf("Enter Value of Y1: ");
      scanf("%f", &y1);
      printf("Enter Value of X2: ");
      scanf("%f", &x2);
      printf("Enter Value of Y2: ");
      scanf("%f", &y2);

      dx = abs(x1 - x2);
      dy = abs(y1 - y2);

      p = 2 * dy - dx;

      if(x1 > x2)
      {
            x = x2;
            y = y2;
            end = x1;
      }
      else
      {
            x = x1;
            y = y1;
            end = x2;
      }
      putpixel(x, y, 10);
      putpixel(x+1, y+1, 10);
      putpixel(x+2, y+2, 10);
      putpixel(x+3, y+3, 10);
      putpixel(x+4, y+4, 10);
      while(x < end)
      {
            x = x + 1;
            if(p < 0)
            {
                  p = p + 2 * dy;
            }
            else
            {
                  y = y + 1;
                  p = p + 2 * (dy - dx);
            }
            putpixel(x, y, 10);
      putpixel(x+1, y+1, 10);
      putpixel(x+2, y+2, 10);
      putpixel(x+3, y+3, 10);
      putpixel(x+4, y+4, 10);
      }
      delay(20000);
      closegraph();
}

void mycircle_cartesian(int xc, int yc,int r)
{
    initwindow(800, 800);
// int xc,yc,r;
int x=400,y;
for(y=0;y<=800;y++)
{
    putpixel(x,y,9);
}
y=400;
for(x=0;x<=800;x++)
{
    putpixel(x,y,9);
}
   printf("Enter the coordinates of the centre of the circle:");
   scanf("%d %d ",&xc,&yc);
   printf("");
   printf("Enter the radius of the circle");
   scanf("%d",&r);

   xc= xc +400;
   yc= 400 - yc;
   putpixel(floor(xc - r + 0.5),floor(yc + 0.5),9);
   putpixel(floor(xc + r + 0.5),floor(yc + 0.5),9);

   for(x=(floor(xc - r + 0.5) + 1);x <= (floor(xc + r + 0.5) - 1); x++)
   {
       y = yc + sqrt((r*r)-((xc-x)*(xc-x)));
       putpixel(x,floor(y+0.5),9);
       y = yc - sqrt((r*r)-((xc-x)*(xc-x)));
       putpixel(x,floor(y+0.5),9);
       x=x+1;
   }


   delay(10000);
   closegraph();
}

void myellipse_cartesian(float xc,float yc,float rx,float ry)
{
     initwindow(800, 800);
    float x=400,y;
 for(y=0;y<=800;y++)
  {
    putpixel(x,y,9);
  }
y=400;
 for(x=0;x<=800;x++)
 {
    putpixel(x,y,9);
 }


//  float xc,yc,rx,ry;
   printf("Semi major Axes:");
   scanf("%f", &rx );
   printf("Semi minor Axes:");
   scanf("%f", &ry );
   printf("Enter the coordinates of the centre of the ellipse:");
   scanf("%f%f", &xc, &yc);


   xc= xc +400;
   yc= 400 - yc;

   putpixel(floor(xc + rx + 0.5),floor(yc +0.5),9);
   putpixel(floor(xc - rx + 0.5),floor(yc  +0.5),9);
   putpixel(floor(xc + 0.5),floor(yc + ry +0.5),9);
   putpixel(floor(xc + 0.5),floor(yc -ry + 0.5),9);

  if(rx>ry)
  {
   x= floor ((rx+0.5) - 1);
  }
  else
  {
    y= floor ((ry+0.5 )- 1);
  }

if(rx>ry)
{
    while(x>0)
    {
        y = floor(sqrt((ry*ry)- ((ry*ry)/(rx*rx))*(x*x)) + 0.5);

        putpixel((floor(xc + 0.5))+x,(floor(yc +0.5))+y,9);
        putpixel((floor(xc + 0.5))-x,(floor(yc +0.5))+y,9);
        putpixel((floor(xc + 0.5))+x,(floor(yc +0.5))-y,9);
        putpixel((floor(xc + 0.5))-x,(floor(yc +0.5))-y,9);

        x = x-1;
    }
}
else
{
    while(y>0)
    {
        x = floor(sqrt((rx*rx)- ((rx*rx)/(ry*ry))*(y*y)) + 0.5);

        putpixel((floor(xc + 0.5))+x,(floor(yc +0.5))+y,9);
        putpixel((floor(xc + 0.5))+x,(floor(yc +0.5))-y,9);
        putpixel((floor(xc + 0.5))-x,(floor(yc +0.5))+y,9);
        putpixel((floor(xc + 0.5))-x,(floor(yc +0.5))-y,9);
        y = y-1;

    }
}

delay(20000);
   closegraph();
}

void myellipse_parametric(float xc,float yc,float rx,float ry)
{
     initwindow(800, 800);
    float x=400,y;
 for(y=0;y<=800;y++)
  {
    putpixel(x,y,9);
  }
y=400;
 for(x=0;x<=800;x++)
 {
    putpixel(x,y,9);
 }


//  float xc,yc,rx,ry;
   printf("Semi major Axes:");
   scanf("%f", &rx );
   printf("Semi minor Axes:");
   scanf("%f", &ry );
   printf("Enter the coordinates of the centre of the ellipse:");
   scanf("%f%f", &xc, &yc);


   xc= xc +400;
   yc= 400 - yc;

   putpixel(floor(xc + rx + 0.5),floor(yc +0.5),9);
   putpixel(floor(xc - rx + 0.5),floor(yc  +0.5),9);
   putpixel(floor(xc + 0.5),floor(yc + ry +0.5),9);
   putpixel(floor(xc + 0.5),floor(yc -ry + 0.5),9);

   double theta=1;
   float radian =(3.14/180);
   double delta_theta=1;
   while(theta<(90))
   {
       x= rx * cos(theta*radian);
       y= ry * sin(theta*radian);

       putpixel(floor(xc+x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc+x+0.5),floor(yc-y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc-y+0.5),9);


       theta = theta + 1;

   }

   delay(20000);
   closegraph();
}

void myparallelline(float x1,float y1,float x2,float y2)
{
    initwindow(1000,1000);
  float x,y;
  //x1,y1,x2,y2;

  printf("Enter the coordinates of the starting point:");
  scanf("%f%f",&x1,&y1);
  printf("Enter the coordinates of the ending point:");
  scanf("%f%f",&x2,&y2);

  float dx,dy, steps;

  dx = fabs( x2-x1);
  dy= fabs(y2-y1);

  if(dx>dy)
         steps=dx;
  else
    steps= dy;

 float deltaX,deltaY;

 deltaY= dy/steps;
 deltaX= dx/steps;

 putpixel(x1,y1,10);
 putpixel(x1+20,y1+20,10);

 x=x1;
 y=y1;
 int k;
 for(k=1;k<steps;steps++)
 {
     x = x+deltaX;
     y = y+deltaY;
     putpixel(x,y,10);
     putpixel(x+20,y+20,10);

 }
 delay(20000);
   closegraph();
}
void mycircle_midpoint(float xc, float yc,float r)
{
    initwindow(800, 800);
// float xc,yc,r;
int x=400,y;
int p;
for(y=0;y<=800;y++)
{
    putpixel(x,y,9);
}
y=400;
for(x=0;x<=800;x++)
{
    putpixel(x,y,9);
}
   printf("Enter the coordinates of the centre of the circle:");
   scanf("%f%f",&xc,&yc);
   printf("Enter the radius of the circle");
   scanf("%f",&r);

float X,Y;
  xc= xc +400;
   yc= 400 - yc;

   x=0;
   y= floor(r+0.5);
   X=x;
   Y=2*y;
   p=floor(5/4-r+0.5);


        putpixel((floor(xc+0.5)+x),((floor(yc+0.5))+y),10);
        putpixel((floor(xc+0.5)+x),((floor(yc+0.5))-y),10);
        putpixel((floor(xc+0.5)-x),((floor(yc+0.5))+y),10);
        putpixel((floor(xc+0.5)-x),((floor(yc+0.5))-y),10);

        while(x<y)
        {
            x=x+1;
            X=X+2;
            if(p<0)
            {
                p=p+X+1;
            }
            else
            {
                Y=Y -2;
                p=p+X+1-Y;
                y=y-1;
            }
             putpixel((floor(xc+0.5)+x),((floor(yc+0.5))+y),10);
             putpixel((floor(xc+0.5)+x),((floor(yc+0.5))-y),10);
             putpixel((floor(xc+0.5)-x),((floor(yc+0.5))+y),10);
             putpixel((floor(xc+0.5)-x),((floor(yc+0.5))-y),10);

             putpixel((floor(xc+0.5)+y),((floor(yc+0.5))+x),10);
             putpixel((floor(xc+0.5)+y),((floor(yc+0.5))-x),10);
             putpixel((floor(xc+0.5)-y),((floor(yc+0.5))+x),10);
             putpixel((floor(xc+0.5)-y),((floor(yc+0.5))-x),10);

        }

        //delay(30000);
         getch();
        closegraph();

}
void mycircle_parametric(int xc, int yc,int r)
{
    initwindow(800, 800);
// float xc,yc,r;
float x=400,y;
for(y=0;y<=800;y++)
{
    putpixel(x,y,9);
}
y=400;
for(x=0;x<=800;x++)
{
    putpixel(x,y,9);
}
   printf("Enter the coordinates of the centre of the circle:");
   scanf("%f %f ",&xc,&yc);
   printf("Enter the radius of the circle");
   scanf("%f",&r);

   xc= xc +400;
   yc= 400 - yc;

   putpixel(floor(xc + 0.5),floor(yc + r +0.5),9);
   putpixel(floor(xc + 0.5),floor(yc - r +0.5),9);
   putpixel(floor(xc + r + 0.5),floor(yc - r +0.5),9);
   putpixel(floor(xc - r + 0.5),floor(yc + 0.5),9);

   double theta=1;
   float radian =(3.14/180);
   double delta_theta=1;
   while(theta<(45))
   {
       x= r * cos(theta*radian);
       y= r * sin(theta*radian);

       putpixel(floor(xc+x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc+x+0.5),floor(yc-y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc-y+0.5),9);
       putpixel(floor(xc+y+0.5),floor(yc+x+0.5),9);
       putpixel(floor(xc+y+0.5),floor(yc-x+0.5),9);
       putpixel(floor(xc-y+0.5),floor(yc+x+0.5),9);
       putpixel(floor(xc-y+0.5),floor(yc-x+0.5),9);

       theta = theta + 1;

   }

   if(theta == 45)
   {
       x= r * cos(theta*radian);
       y= r * cos(theta*radian);

       putpixel(floor(xc+x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc+x+0.5),floor(yc-y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc+y+0.5),9);
       putpixel(floor(xc-x+0.5),floor(yc-y+0.5),9);
   }

   delay(50000);
   closegraph();
}
