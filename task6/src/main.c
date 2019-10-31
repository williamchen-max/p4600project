#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "curve.h"
#include "LCR_Meter.h"

void main(int argc, char** argv )
{
	ViStatus status = VI_SUCCESS;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM;
	ViSession scopeHandle, FGHandle;
	
	char databuffer[2500];

	int y[2500];
	int i=0;
	int error;
	int fmax;
	int f ;
	int step;
	int n = 0 ,a=0;

	float data[2500];
	float scale;
	float amplitude;
	
	FILE * input_file;

	char filename[36];

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		scope_open(defaultRM,&scopeHandle,description_SCOPE); //printf("\nOpened %s is scope\n",description_SCOPE);fflush(stdout);

		if(status == VI_SUCCESS)
		{
			fg_open(defaultRM,&FGHandle,description_FG); //printf("\nOpened %s is FG\n",description_FG);fflush(stdout);

			if(status == VI_SUCCESS)
			{
				
				if(argc > 1)
				{
					sscanf(argv[1],"%d",&fmax);
					sscanf(argv[2],"%d",&f);
					sscanf(argv[3],"%d",&step);
					sscanf(argv[4],"%s",filename);
		
					input_file = fopen(filename,"w");// write the value in text file
					printf("input valid");
				}
				else
				{
					fmax = 15000;
					f = 5000;
					step = 1000;
		
					input_file = fopen("filename","w");// write the value in text file
					printf("no input");
				}

				int point = (fmax-f)/step;
				float amplitude_array[point];

				for(i=f;i<fmax;i+=step)
				{
					fg_set(&FGHandle,i,1,0,0);//printf("\nFG is initialize\n");fflush(stdout);
					printf("\nfrequency = %d \n",i);
					amplitude = data_aquire(&scopeHandle,1);
					amplitude_array[n] = amplitude;
					fprintf(input_file,"%d %f \n",i,amplitude_array[n]);
					n=n+1;
				}
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
	
