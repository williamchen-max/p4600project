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
	viRead(Handle,databuffer,npoint,&resultCount);
	return status;
}

int voltage_read (ViSession* Handle,float* volt)
{
	ViUInt32 Voltage;ViStatus status;
	ViChar voltage[34];

	viWrite(*Handle,"AUTOSet EXECute\n",16,&Voltage);
	sleep(5);
	viWrite(*Handle,"CH1:SCAle?\n",11,&Voltage);
	viRead(*Handle,voltage,256,&Voltage); 

		//printf("voltage = %s\n",voltage);
		sscanf(voltage,"%f",&volt);
		//printf("voltage float = %f\n",*volt);
	
	return status;
}
int voltage_set (ViSession* Handle,float volts)
{
	ViUInt32 resultCount;
	char command[36];
	sprintf(command,"CH1:SCALe %E \n",volts);
	ViStatus status = viWrite(*Handle,command,strlen(command),&resultCount);      
	return status;
}

int scope_open(ViSession defaultRM,ViSession* scopeHandle,ViChar description_SCOPE[VI_FIND_BUFLEN])
{
	ViStatus status = VI_SUCCESS;	
	ViFindList resourceList;
	ViUInt32 num_inst, resultCount;
	
	unsigned char resultBuffer[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0X0699::?*INSTR", &resourceList,&num_inst,description_SCOPE);
	if(status == VI_SUCCESS)
	 {
	 	viOpen(defaultRM,description_SCOPE,VI_NULL,VI_NULL,scopeHandle);
	 	if(status == VI_SUCCESS)
	 	{
	 		viWrite(*scopeHandle,"*IDN?\n",6,&resultCount);      
			viRead(*scopeHandle,resultBuffer,256,&resultCount);
			
			//printf("\nResult count = %d",resultCount);
			//printf("\nResult buffer = %s\n",resultBuffer ); 
	 	}
	 }
	 return status;
}

int fg_open(ViSession defaultRM,ViSession* FGHandle,ViChar description_FG[VI_FIND_BUFLEN])
{
	ViStatus status = VI_SUCCESS;	
	ViFindList resourceList;
	ViUInt32 num_inst,resultCount_FG;

	unsigned char resultBuffer_FG[256];

	status = viFindRsrc(defaultRM,"USB[0-9]::0X1AB1::?*INSTR", &resourceList,&num_inst,description_FG); // find RIGOL FG
	if(status == VI_SUCCESS)
	 {
	 	viOpen(defaultRM,description_FG,VI_NULL,VI_NULL,FGHandle);
	 	if(status == VI_SUCCESS)
	 	{
	 		viWrite(*FGHandle,"*IDN?\n",6,&resultCount_FG);      
			viRead(*FGHandle,resultBuffer_FG,256,&resultCount_FG);

			//printf("\nResult count = %d",resultCount_FG);
			//printf("\nResult buffer = %s\n",resultBuffer_FG ); 
	 	}
	 }
	 return status;
}

int fg_set(ViSession* Handle,int frequency,int vol,int dc, int phase)
{
	ViUInt32 resultCount;
	char command[45]; 
	sprintf(command,":SOUR1:APPL:SIN %d,%d,%d,%d\n",frequency,vol,dc,phase);
	viWrite(*Handle,command,strlen(command),&resultCount);
	viWrite(*Handle,":OUTP1 ON\n",10,&resultCount); 
	return VI_SUCCESS;
}

int scope_set(int chanel,ViSession* Handle)
{
	ViStatus status = VI_SUCCESS;
	ViUInt32 resultCount,CH;
	ViChar ch[5],voltage[34];
	char command[36]; 
	sprintf(command,"DAT:SOU CH%d\n",chanel);
	
	viWrite(*Handle,command,strlen(command),&resultCount);
	viWrite(*Handle,"DAT:SOU? \n",9,&CH); // set up which ch the scope is reading
	status = viRead(*Handle,ch,52,&CH); // read which ch is is recording
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

float data_aquire(ViSession* scopeHandle,int scopech)
{
	ViStatus status = VI_SUCCESS;
	ViChar description_SCOPE[VI_FIND_BUFLEN];
	ViChar description_FG[VI_FIND_BUFLEN];
	ViSession defaultRM;

	
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

	//fg_set(FGHandle,i,1,0,0);//printf("\nFG is initialize\n");fflush(stdout);

	//printf("\nfrequency = %d \n",i);
		scope_set(scopech,*scopeHandle); // set up the scope to the right ch
		//printf("\nscope is initialize\n");fflush(stdout);
		
		voltage_read(*scopeHandle,&scale);
		float bits = scale*10.0/256.0; // calculate the volt per bit of the scale
		//printf("volt / bits = %f \n",bits);fflush(stdout);
		//printf("scale = %f \n",scale);fflush(stdout);
							
			get_curve(*scopeHandle,databuffer,2500);
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
					//printf("%f\n",amplitude_array[n] );fflush(stdout);
					//fprintf(input_file,"%d %f \n",i,amplitude_array[n]);
					//n=n+1;

						
return amplitude;

}

void unserinput()
{
	/*
	if(argc > 1)
				{
					for(a=0;a<8;a++)
					{
						if(argv[a]=="-max")
						{
							sscanf(argv[a+1],"%d",&fmax);
							printf("%d\n",fmax);
						}
						else
						{
							fmax = 15000;	printf("defult max");						
						}
					}
					for(a=0;a<8;a++)
					{
						if(argv[a]=="-min")
						{
							sscanf(argv[a+1],"%d",&f);
							printf("%d\n",fmin);
						}
						else
						{							
							f = 5000;printf("defult min");
						}
					}
					for(a=0;a<8;a++)
					{
						if(argv[a]=="-step")
						{
							sscanf(argv[a+1],"%d",&step);
							printf("%d\n",step);
						}
						else
						{
							step = 1000;printf("defult step");
						}
					}
					for(a=0;a<8;a++)
					{
						if(argv[a]=="-name")
						{
							sscanf(argv[a+1],"%s",&filename);
							input_file = fopen(filename,"w");// write the value in text file
							printf("input valid");
						}
						else
						{
							input_file = fopen("filename","w");printf("defult name");
						}

					}		
					
					
				}
				else
				{
					fmax = 15000;
					f = 5000;
					step = 1000;
		
					input_file = fopen("filename","w");// write the value in text file
					printf("no input");
				}*/
}


				