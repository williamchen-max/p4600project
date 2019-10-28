#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include "curve.h"
#include <string.h>
/*

int voltage_set (ViSession Handle,float volts);
int get_curve(ViSession Handle,char* databuffer,int npoint);

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

int Data_Aquire(float f, float fmax, int step, float amplitude)
{
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM, scopeHandle, FGHandle;
	
	ViUInt32 resultCount;
	ViUInt32 resultCount_FG;
	ViUInt32 ResultCount;
	ViUInt32 CH;
	ViUInt32 Voltage;
	ViChar ch[5];
	ViChar voltage[34];
	char databuffer[2500];
	unsigned char resultBuffer[256];unsigned char resultBuffer_FG[256];

	int y[2500];
	int lsb;
	int msb;
	int i;

	float data[2500];
	float new_data[2500];
	float min,peak;
	float volt;

	for(i=f;i<fmax;i+step)
	{
		status = viOpenDefaultRM(&defaultRM);
		if(status == VI_SUCCESS)
		{
			status = viFindRsrc(defaultRM,"USB[0-9]::0X0699::?*INSTR", &resourceList,&num_inst,description_SCOPE); // find SCOPE
				if(status == VI_SUCCESS)
				{
					status = viOpen(defaultRM,description_SCOPE,VI_NULL,VI_NULL,&scopeHandle);

					if(status == VI_SUCCESS)
					{
						status = viFindRsrc(defaultRM,"USB[0-9]::0X1AB1::?*INSTR", &resourceList,&num_inst,description_FG); // find RIGOL FG
						if(status == VI_SUCCESS)
						{
							status = viOpen(defaultRM,description_FG,VI_NULL,VI_NULL,&FGHandle);

				if(status == VI_SUCCESS)
				{
				printf("\nOpened %s\nOpened %s\n",description_SCOPE,description_FG);

				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);      
				viRead(scopeHandle,resultBuffer,256,&resultCount);

				printf("\nResult count = %d",resultCount);
				printf("\nResult buffer = %s\n",resultBuffer ); 

				viWrite(FGHandle,"*IDN?\n",6,&resultCount_FG);      
				viRead(FGHandle,resultBuffer_FG,256,&resultCount_FG);

				printf("\nResult count = %d",resultCount_FG);
				printf("\nResult buffer = %s\n",resultBuffer_FG ); 
				
				char command[36]; 
				sprintf(command,":SOUR1:APPL:SIN,%E,1\n",f);
				viWrite(FGHandle,command,strlen(command),&resultCount);

				viWrite(scopeHandle,"DAT:SOU CH1\n",12,&ResultCount);
				viWrite(scopeHandle,"DAT:SOU? \n",9,&CH);
				status = viRead(scopeHandle,ch,52,&CH);
				
					if(status == VI_SUCCESS)
						{
							printf("usded: %s\n",ch);
						}
					else
					{
						printf("\n Failed. Ch set to %s ", ch);
					}
					voltage_set(scopeHandle,1);

					viWrite(scopeHandle,"CH1:SCAle?\n",11,&Voltage);
					status = viRead(scopeHandle,voltage,34,&Voltage);

					if(status == VI_SUCCESS)
						{
							printf("voltage = %s\n",voltage);
						}
					else
					{
						printf("voltage not read \n");
					}

					get_curve(scopeHandle,databuffer,2500);

					sscanf(voltage,"%f",&volt);

					float bits = volt*10/256;
					fflush(stdout);
						
					for(int i = 0; i<2500; i++)
					{
						y[i] = databuffer[i];
						data[i] = y[i]*bits;					
					}
					printf("data complete");fflush(stdout);
			
			float smooth[2500];
			smooth_curve(data,2500,5,smooth);
						
			amp(smooth,amplitude);
			//printf("\n amplitude = %f",amplitude);
			
			}
			else
			{
				printf("\nFailed to open %s",description_SCOPE);
			}
		}		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
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
}
*/