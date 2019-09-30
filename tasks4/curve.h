#ifndef __CURVE_H
#define __CURVE_H

#include <stdio.h>

float smooth_curve(float * sample, int n,int smooth_factor, float * smooth);

float amplitude(float * input, int m,float Amp);

int waves();

#endif
