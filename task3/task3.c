#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE * input_file;
	int i =0;
	float x =0,rad = 0;

	input_file = fopen("sin_function","w");

	for(i=0;i<360;i++)
	{
		rad = i*M_PI/180;
		

		x = sin(rad);

		fprintf(input_file,"%f %f\n",x,rad);

		printf("the angle is %d degree and %f radian the sin value is %f \n", i,rad,x);
	}
/*	if (fscanf(input_file,"%f %f",&x,&rad)!=EOF)
	{
		fclose(input_file);
		printf("\n\n file close :)");
	}
*/
return 0;
}



 	

 	