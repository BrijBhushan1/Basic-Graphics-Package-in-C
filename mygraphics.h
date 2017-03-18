
#ifndef MYGRAPHICS_H_INCLUDED
#define MYGRAPHICS_H_INCLUDED

void mylineDDA(float x1,float y1,float x2,float y2);

void mylineBresenhm(float x1,float y1,float x2,float y2);

void mylineWuAlgo (float x1,float y1,float x2,float y2);

void myparallelline(float x1,float y1,float x2,float y2);

void mypolylineBresenhm(float x1,float y1,float x2,float y2);

void mycircle_cartesian(int xc, int yc,int r);

void mycircle_parametric(int xc, int yc,int r);

void myellipse_cartesian(float xc, float yc, float rx, float ry);

void myellipse_parametric(float xc,float yc,float rx,float ry);

void mycircle_midpoint(float xc, float yc,float r);

#endif
