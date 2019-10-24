#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "curve.h"
#include <string.h>
#include "LCR_Meter.h"

int get_curve(ViSession Handle,char* databuffer,int npoint)
{
	ViUInt32 resultCount;
	ViStatus status;
	unsigned char resultbuffer[256];
	viWrite(Handle,"CURV?\n",6,&resultCount);   
	sleep(2);   
	viRead(Handle,resultbuffer,npoint,&resultCount);
	return status;
}

int voltage_set (ViSession Handle,float volts)
{
	ViUInt32 resultCount;
	char command[36];
	sprintf(command,"CH1:SCALe %E \n",volts);
	ViStatus status = viWrite(Handle,command,strlen(command),&resultCount);      
	return status;
}

int scope_open(ViChar description_SCOPE[VI_FIND_BUFLEN])
{
	ViStatus status = VI_SUCCESS;	
	ViSession defaultRM, scopeHandle;
	ViFindList resourceList;
	ViUInt32 num_inst, resultCount;
	
	unsigned char resultBuffer[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0X0699::?*INSTR", &resourceList,&num_inst,description_SCOPE);
	if(status == VI_SUCCESS)
	 {
	 	viOpen(defaultRM,description_SCOPE,VI_NULL,VI_NULL,&scopeHandle);
	 	if(status == VI_SUCCESS)
	 	{
	 		viWrite(scopeHandle,"*IDN?\n",6,&resultCount);      
			viRead(scopeHandle,resultBuffer,256,&resultCount);
			
			printf("\nResult count = %d",resultCount);
			printf("\nResult buffer = %s\n",resultBuffer ); 
	 	}
	 }
	 return status;
}

int fg_open(ViChar description_FG[VI_FIND_BUFLEN])
{
	ViStatus status = VI_SUCCESS;	
	ViSession defaultRM, FGHandle;
	ViFindList resourceList;
	ViUInt32 num_inst,resultCount_FG;

	unsigned char resultBuffer_FG[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0X1AB1::?*INSTR", &resourceList,&num_inst,description_FG); // find RIGOL FG
	if(status == VI_SUCCESS)
	 {
	 	viOpen(defaultRM,description_FG,VI_NULL,VI_NULL,&FGHandle);
	 	if(status == VI_SUCCESS)
	 	{
	 		viWrite(FGHandle,"*IDN?\n",6,&resultCount_FG);      
			viRead(FGHandle,resultBuffer_FG,256,&resultCount_FG);

			printf("\nResult count = %d",resultCount_FG);
			printf("\nResult buffer = %s\n",resultBuffer_FG ); 
	 	}
	 }
	 return status;
}

int fg_set(float frequency,ViSession Handle)
{
	ViUInt32 resultCount;
	char command[36]; 
	sprintf(command,":SOUR1:APPL:SIN,%E,1\n",frequency);
	viWrite(Handle,command,strlen(command),&resultCount);
	return VI_SUCCESS;
}

int scope_set(int chanel,ViSession Handle)
{
	ViStatus status = VI_SUCCESS;
	ViUInt32 resultCount,CH;
	ViChar ch[5],voltage[34];
	char command[36]; 
	sprintf(command,"DAT:SOU CH%d\n",chanel);
	
	viWrite(Handle,command,strlen(command),&resultCount);
	viWrite(Handle,"DAT:SOU? \n",9,&CH); // set up which ch the scope is reading
	status = viRead(Handle,ch,52,&CH); // read which ch is is recording
	return status;
}

int Error_Handling(int error)
{
		if (error == 0)
	{
		exit(EXIT_FAILURE);
	}
		if (error == 1)
	{
		exit(EXIT_FAILURE);
	}
		if (error == 2)
	{
		exit(EXIT_FAILURE);
	}
		if (error == 3)
	{
		exit(EXIT_FAILURE);
	}
		if (error == 4)
	{
		exit(EXIT_FAILURE);
	}
}

/*int data_aquire(float f, float fmax, int step, float amplitude)
{
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
				for(i=f;i<fmax;i+step)
				{
					fg_set(i,FGHandle);

					if(status == VI_SUCCESS)
					{
						scope_set(1,scopeHandle); // set up the scope to the right ch
						
						if(status == VI_SUCCESS)
						{
							voltage_set(scopeHandle,1);
							get_curve(scopeHandle,databuffer,2500);
							float bits = volt*10/256; // calculate the volt per bit of the scale
						
							for(int i = 0; i<2500; i++) // obtain the datapoint and convert to floating point
							{
								y[i] = databuffer[i];
								data[i] = y[i]*bits;					
							}
							//printf("data complete");fflush(stdout);
							float smooth[2500];
							smooth_curve(data,2500,5,smooth); // smooth out the curve

							for(i=0;i<point;i++)
							{
								amp(smooth,amplitude);
								amplitude_array[i] = amplitude;
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
}*/

int data_aquire(float f, float fmax, int step, float amplitude)
{
	for(i=f;i<fmax;i+step)
	{
		fg_set(i,FGHandle);

		if(status == VI_SUCCESS)
		{
			scope_set(1,scopeHandle); // set up the scope to the right ch
					
			if(status == VI_SUCCESS)
			{
				voltage_set(scopeHandle,1);
				get_curve(scopeHandle,databuffer,2500);
				float bits = volt*10/256; // calculate the volt per bit of the scale
						
				for(int i = 0; i<2500; i++) // obtain the datapoint and convert to floating point
				{
					y[i] = databuffer[i];
					data[i] = y[i]*bits;					
				}
				//printf("data complete");fflush(stdout);
				float smooth[2500];
				smooth_curve(data,2500,5,smooth); // smooth out the curve
				for(i=0;i<point;i++)
				{
					amp(smooth,amplitude);
					amplitude_array[i] = amplitude;
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


				