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

	ViStatus status = VI_SUCCESS;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM, scopeHandle, FGHandle;
	
	char databuffer[2500];

	int y[2500];
	int i;
	int error;
	//int point = (fmax-f)/step;

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
	return ;*/
	ViStatus status = VI_SUCCESS;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM;
	ViSession scopeHandle, FGHandle;
	
	char databuffer[2500];

	int y[2500];
	int i;
	int error;
	int fmax = 1000;
	int f = 100;
	int step = 100;
	int point = (fmax-f)/step;

	float data[2500];
	float volt;
	float amplitude;
	float amplitude_array[step];

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		scope_open(defaultRM,&scopeHandle,description_SCOPE); //printf("\nOpened %s is scope\n",description_SCOPE);fflush(stdout);

		if(status == VI_SUCCESS)
		{
			fg_open(defaultRM,&FGHandle,description_FG); //printf("\nOpened %s is FG\n",description_FG);fflush(stdout);

			if(status == VI_SUCCESS)
			{
				for(i=f;i<fmax;i+=step)
				{
					fg_set(FGHandle,i,1,0,0);//printf("\nFG is initialize\n");fflush(stdout);

					if(status == VI_SUCCESS)
					{
						printf("frequency = %d \n",i);
						scope_set(1,scopeHandle); // set up the scope to the right ch
						//printf("\nscope is initialize\n");fflush(stdout);

						if(status == VI_SUCCESS)
						{
							int max_range = 10/256;
							
							sleep(5);
							voltage_read(scopeHandle,&volt);
							
							float bits = volt*10.0/256.0; // calculate the volt per bit of the scale
							printf("bits = %f \n volts = %f \n",bits,volt);fflush(stdout);

							//int scale_ok = 0;
							//while (scale_ok == 0)
							{
								get_curve(scopeHandle,databuffer,2500);printf("\ncurve copy\n");fflush(stdout);
							
								for(int a = 0; a<2500; a++) // obtain the datapoint and convert to floating point
								{
									y[a] = databuffer[a];
									data[a] = y[a]*bits;
									//printf("%f\n",data[a]);fflush(stdout);
								}
								//printf("data complete \n");fflush(stdout);
								float smooth[2500];
								smooth_curve(data,2500,5,smooth); // smooth out the curve
								printf("\ncurve smooth\n");fflush(stdout);

								for(int b=0;b<point;b++)
								{
									amplitude_array[b] = amp(smooth);
									
									printf("%f\n",amplitude_array[b] );fflush(stdout);
								}

								/*if (amplitude == max_range)
								{
									scale_ok=1;
								}
								if (amplitude < max_range)
								{
									int new_volt_low = volt - 1 ;
									voltage_set(scopeHandle,new_volt_low);
								}
								if (amplitude > max_range)
								{
									int new_volt_up = volt + 1 ;
									voltage_set(scopeHandle,new_volt_up);
								}*/

							}
						
						}
						else
						{
							printf("\nScope set up incorrect");
							error = 4 ;
							Error_Handling(error);
						}
					}
					else
					{
						printf("\nFG set up incorrect");
						error = 3;
						Error_Handling(error);
					}
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
	
