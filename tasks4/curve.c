#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "curve.h"

#define FORMATE "%f"



float smooth_curve(float * sample, int n,int smooth_factor, float * smooth)
{
	//float* x[n]; 
	//float* m_avrg[n];
	
	int a = smooth_factor;
	int c =n-(a-1);
	int i=0,k=0;
	float sum;

		FILE * input_file;
		input_file = fopen("sin_smooth","w");
	//printf("%d\n", n);

	for (i=0;i<c;i++)
		{
			sum=0;
			for(k=0;k<a;k++)
			{

				sum += sample[i+k];
				//printf("%f\n", sum[k]);
			}

			smooth[i] =  sum/a;
	
			printf("%f\n", smooth[i]);
			fprintf(input_file,"%f \n",smooth[i]);
		}
		/*for (i=0;i<n;i++)
		{
			


			smooth[i] =  (sample[i]+sample[i+1]+sample[i+2]+sample[i+3]+sample[i+4])/5;
			


			//printf("%f\n", smooth[i]);


		fprintf(input_file,"%f \n",smooth[i]);
		}*/
	
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

	float peak = 0,trough = 0;
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