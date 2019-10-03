#ifndef __CURVE_H
#define __CURVE_H

#include <stdio.h>

float smooth_curve(float * sample, int n,int smooth_factor, float * smooth);

float amplitude(float * input, int m,float Amp);

int get_data(FILE* datafile, float* data, int sz_data);

int waves();

#endif
