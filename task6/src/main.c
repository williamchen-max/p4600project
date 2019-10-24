#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "curve.h"
#include "LCR_Meter.h"

void main(int argc, char** argv)
{
	/*
	float amplitude;
	float frequency = 1;
	float frequency_max = 1000;
	int step = 100;
	int i;
	int point = (frequency-frequency_max)/step;
	float amplitude_array[point];

	FILE * input_file;
	input_file = fopen("Amplitude","w");

	for(i=0;i<point;i++)
	{
		data_aquire(frequency,frequency_max,step,amplitude);
		amplitude_array[i] = amplitude;

		printf("amplitude = %f",amplitude[i]);
		fprintf(input_file,"%f \n",amplitude[i]);
	}
*/
	ViStatus status = VI_SUCCESS;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM, scopeHandle, FGHandle;
	
	char databuffer[2500];

	int y[2500];
	int i;
	int error;
	int point = (fmax-f)/step;

	float data[2500];
	float volt;
	float amplitude_array[step];

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		scope_open(description_SCOPE); printf("\nOpened %s\n",description_SCOPE);

		if(status == VI_SUCCESS)
		{
			fg_open(description_FG); printf("\nOpened %s\n",description_FG);

			if(status == VI_SUCCESS)
			{

			}
			else
			{
				printf("\nFG not open");
				error = 2;
				Error_Handling(error);
			}
		}
		else
		{
			printf("\nScope not open");
			error = 1;
			Error_Handling(error);
		}
	}	
	else
	{
		printf("\nFailed to open defaultRM");
		error = 0;
		Error_Handling(error);
	}	
	return ;
}
	
}
