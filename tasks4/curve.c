#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "curve.h"

#define FORMATE "%f"



float smooth_curve(float * sample, int n, float * smooth)
{
	//float* x[n]; 
	//float* m_avrg[n];
	int c =n-4;
	int b=0;

	//printf("%d\n", n);

	for (b=0;b<n;b++)
		{
			smooth[b] =  (sample[b]+sample[b+1]+sample[b+2]+sample[b+3]+sample[b+4])/5;
			//printf("\n%f %f %f %f %f",x[b],x[b+1],x[b+2],x[b+3],x[b+4]);
			//m_avrg = sum[b]/5;

			printf("%f\n", smooth[b]);
		}
	
}

float amplitude(float * input, int m)
{
	float sum = 0,mean,variance, Amplitude,std;
 	float sq_sum = 0;
 	int i ;

 	for(i = 0; i<m; i++ )
 	{
 		sum += input[i];
 		sq_sum += input[i] * input[i];
 	}

 	mean = sum/m;
 	variance = sq_sum / m-mean * mean;
 	std = sqrt(variance);
 	float two = pow(2,0.5);
 	Amplitude = std*two;

 	//printf("\nMean = %.3e \n Standard deviation = %.3e ",mean, std);
 	printf("the amplitude of the wave is %f",Amplitude);
	

 	//return Amplitude;
}


/*

	float max = 0,min = 0;
	int i=0;

	printf("at t");
fflush(stdout);
		while(scanf("%f",samples[i])!=EOF)
		{
			for(i=0;i<m;i++)
			{
				scanf("%f",samples[i]);
				if(samples[i]>max)
				{
					max = samples[i]; 
				}
				if(samples[i]<min)
				{
					min = samples[i]; 
				}
			}
			
		}
		printf("max is %f\n",max);
		printf("min is %f\n",min);
		
		float Amplitude = max-min;
		printf("the amplitude of the wave is %f",Amplitude);		
*/




int waves()
{
	srand((time(NULL)));

	FILE * input_file;
	int i =rand();
	float x =0,rad = 0;

	input_file = fopen("sin","w");

	for(i=0;i<360;i++)
	{
		float r = (float) rand()/(float) RAND_MAX;

		rad = i*M_PI/180;

		
		x = sin(rad);

		x += (r/10);

		fprintf(input_file,"%f \n",x);

		//printf("the angle is %d degree and %f radian the sin value is %f \n", i,rad,x);
	}

return 0;
}