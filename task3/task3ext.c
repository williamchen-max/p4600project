#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 
 


float stat(float* input, int count)
 {
 	float sum = 0;
 	float sq_sum = 0;
 	int i ;

 	for(i = 0; i<count; i++ )
 	{
 		sum += input[i];
 		sq_sum += input[i] * input[i];
 	}
 	float mean = sum/count;
 	float variance = sq_sum / count-mean * mean;
 	printf("\nMean = %.3e \n mean = %f",mean,mean);
	printf("\nStandard deviation = %.3e std_ev = %f", sqrt(variance), sqrt(variance));

 	return sqrt(variance);
 }

int main(int argc ,char** argv )
{
	int i=0;
	float x,y;
	

	FILE * input_file;

	input_file = fopen(argv[1],"r"); //open file

	if(input_file !=NULL) // CHECK IF IS OPEN
	{
	
		while(fscanf(input_file,"%f %f",&x ,&y)!=EOF)
		{
			++i;
		}

		printf("number of data is %d\n",i);
		fflush(stdout);

		rewind(input_file);
		printf("file rewinded");
		fflush(stdout);

		float data[i];
	    float num[i],rad[i];
	    int a=0;

		
		for (a =0;a<i;a++)
		{
			fscanf(input_file,"%f %f",&num[a] ,&rad[a] );
			//printf("%f %f\n",num[a] ,rad[a]);
		}
		stat(num,i);
	}
	else
	{
		printf("terminate");
		return 0;
	}

	

	//return 0;
}