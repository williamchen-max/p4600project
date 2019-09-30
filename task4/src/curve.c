#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "curve.h"

#define FORMATE "%f %f"

int smooth_curve(int argc ,char** argv)
{
	float y;
	FILE * input_file;

	input_file = fopen(argv[1],"r");//open file

	if(input_file !=NULL) // CHECK IF IS OPEN
	{
		int i=0,a=0;
		while(fscanf(input_file,FORMATE,&y)!=EOF)
		{
			++i;
		}
		//printf("%d\n",i);
		rewind(input_file);

		float x[i]; 

		for (a =0;a<i;a++)
		{
			fscanf(input_file,FORMATE,&x[a]);
			//printf("\n%f",x[a]);
		}

		float sum[i];
		float m_avrg[i];
		int c =i-4;
		int b=0;
		//printf("%d\n",c);

		for (b=0;b<c;b++)
		{
			m_avrg[b] =  (x[b]+x[b+1]+x[b+2]+x[b+3]+x[b+4])/5;
			//printf("\n%f %f %f %f %f",x[b],x[b+1],x[b+2],x[b+3],x[b+4]);
			//m_avrg = sum[b]/5;
			printf("%f\n", m_avrg[b]);
		}
	}
	else
	{
		printf("no file found \n\nterminate");
		return 0;
	}
}

void amplitude ()
{
/	float data* sound;
/	float max = 0,min = 0;
	float y;
	FILE * input_file;

	input_file = fopen(argv[1],"r");//open file

	if(input_file !=NULL) // CHECK IF IS OPEN
	{
		int i=0,a=0,b=0;
		while(fscanf(input_file,FORMATE,&y)!=EOF)
		{
			++a;
		}
		//printf("%d\n",a);
		rewind(input_file);

	while(fscanf(input_file,FORMATE,&x)!=EOF)
		{
			for(i=0;i<a;i++)
			if(sound(i)>max)
			{
				max = sound[i]; 
			}
			//printf("%f\n",max);
		}
		rewind(input_file);

	while(fscanf(input_file,FORMATE,&x)!=EOF)
		{
			for(b=0;b<a;b++)
			if(sound(b)<min)
			{
				min = sound[b]; 
			}
			//printf("%f\n",min);
		}
}