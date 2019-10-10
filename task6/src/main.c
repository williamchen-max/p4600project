#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "curve.h"

void main(int argc, char** argv)
{
	unsigned char resultBuffer[256];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;
	ViUInt32 ResultCount;
	ViUInt32 CH;
	ViUInt32 Voltage;

	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	ViChar ch[5];
	ViChar voltage[34];
	char dataBuffer[2500];

	
	int y[2500];

	int lsb;
	int msb;

	float data[2500];
	float new_data[2500];
	float min,peak;
	float volt;

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::?*INSTR",	&resourceList,&num_inst,description);
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);

				/*viWrite(scopeHandle,"CH1:VOLts 1",16,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);*/

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);      
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer ); 
				
				

					if(status == VI_SUCCESS)
						{
							viWrite(scopeHandle,"DAT:SOU CH1\n",12,&ResultCount);
							viWrite(scopeHandle,"DAT:SOU? \n",9,&CH);
							status = viRead(scopeHandle,ch,3,&CH);
							printf("usded: %s\n",ch);
						}
					else
					{
						printf("\n Ch set to %s ", ch);
					}

					if(status == VI_SUCCESS)
						{
							viWrite(scopeHandle,"CH1:SCAle? \n",11,&Voltage);
							status = viRead(scopeHandle,voltage,3,&Voltage);
							printf("voltage = %s\n",voltage);
						}
					else
					{
						printf("\n voltage not read ");
					}

					if(status == VI_SUCCESS)
						{
							viWrite(scopeHandle,"CURV?\n",6,&resultCount);
							sleep(2);
							status = viRead(scopeHandle,dataBuffer,2500,&resultCount);
						}
					else
					{
						printf("\n voltage not read ");
					}

				sscanf(voltage,"%f",volt);

				float bits = volt/256;
				fflush(stdout);

				for(int i = 0; i<2500; i++)
				{
					y[i] = dataBuffer[i];
					data[i] = y[i]*bits;					
					
					//printf("\nRaw = %x,  Read = %d",y,y);
					//printf("\n %f",y[i]);
				}

				printf("data complete");fflush(stdout);

				for(int i = 0; i<2500; i++)
				{
					scanf("%f",data[i]);
					if(data[i]>peak)
					{
						peak = data[i]; 
					}
					if(data[i]<min)
					{
						min = data[i]; 
					}
				}

				float Amp = (peak-min)/2;

				printf("\n peak = %f \n min = %f",peak,min);
				printf("\n amplitude = %f",Amp);
/*
				float* curve[2500];
				smooth_curve(data,2500,5,curve);

				float Amplitude;
				amplitude(curve,2500,Amplitude);
				printf("the amplitude of the wave is %f",Amplitude);
*/
			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}
}