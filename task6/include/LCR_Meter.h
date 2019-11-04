#ifndef __LCR_METER_H
#define __LCR_METER_H

#include <stdio.h>

int get_curve(ViSession* Handle,char* databuffer,int npoint);

float voltage_read (ViSession* Handle);

int voltage_set (ViSession* Handle,float volts);

int scope_open(ViSession defaultRM,ViSession* scopeHandle,ViChar description_SCOPE[VI_FIND_BUFLEN]);

int fg_open(ViSession defaultRM,ViSession* FGHandle,ViChar description_FG[VI_FIND_BUFLEN]);

int fg_set(ViSession* Handle,int frequency,int vol,int dc, int phase);

int scope_set(int chanel,ViSession* Handle);

int Error_Handling(int error,ViSession* FGHandle,ViSession* ScopeHandle);



void unserinput();

#endif
