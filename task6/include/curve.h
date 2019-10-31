#ifndef __CURVE_H
#define __CURVE_H

#include <stdio.h>

float smooth_curve(float * sample, int datapoint,int smooth_factor, float * smooth);

float amp_stat(float * input, int m);

int get_data(FILE* datafile, float* data, int sz_data);

int waves();

float amp(float * data);

#endif
