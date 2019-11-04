#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include <string.h>
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
					
					scope_set(1,&scopeHandle); // set up the scope to the right ch
					//printf("\nscope is initialize\n");fflush(stdout);

					scale = voltage_read(&scopeHandle);
					float bits = scale*10.0/256.0; // calculate the volt per bit of the scale
					//printf("volt / bits = %f \n",bits);fflush(stdout);
					//printf("scale = %f \n",scale);fflush(stdout);

					get_curve(&scopeHandle,databuffer,2500);
					//printf("\ncurve copy\n");fflush(stdout);
		
					for(int a = 0; a<2500; a++) // obtain the datapoint and convert to floating point
					{
						y[a] = databuffer[a];
						data[a] = y[a]*bits;
						//printf("%f\n",data[a]);fflush(stdout);
					}
					//printf("data complete \n");fflush(stdout);
				
					float smooth[2500];
					smooth_curve(data,2500,5,smooth); // smooth out the curve
					//printf("\ncurve smooth\n");fflush(stdout);
					
					float amplitude = amp_stat(smooth,2496);
					
					
					amplitude_array[n] = amplitude;
					//printf("%f\n",amplitude_array[n] );fflush(stdout);

					fprintf(input_file,"%d\n",i);
					fprintf(input_file,"%f\n",amplitude_array[n]);
					n=n+1;
				}
				fclose(input_file);
				viClose(scopeHandle);
				viClose(FGHandle);

			}
			else
			{
				printf("\nFG not open");
				error = 2;
				Error_Handling(error,&FGHandle,&scopeHandle);
			}
		}
		else
		{
			printf("\nScope not open");
			error = 1;
			Error_Handling(error,&FGHandle,&scopeHandle);
		}
	}	
	else
	{
		printf("\nFailed to open defaultRM");
		error = 0;
		Error_Handling(error,&FGHandle,&scopeHandle);
	}	
	return ;
}
	
