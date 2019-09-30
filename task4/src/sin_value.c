#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main()
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



 	

 	