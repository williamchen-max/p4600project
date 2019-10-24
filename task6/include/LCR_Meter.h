#ifndef __LCR_METER_H
#define __LCR_METER_H

#include <stdio.h>

int get_curve(ViSession Handle,char* databuffer,int npoint);

int voltage_set (ViSession Handle,float volts);

int scope_open(ViChar description_SCOPE[VI_FIND_BUFLEN]);

int fg_open(ViChar description_FG[VI_FIND_BUFLEN]);

int fg_set(float frequency,ViSession Handle);

int scope_set(int chanel,ViSession Handle);

int Error_Handling(int error);

int data_aquire(float f, float fmax, int step, float amplitude);

#endif
