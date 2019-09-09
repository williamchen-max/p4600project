#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	/* // program to do stats, mean and stander deviation*/

	float angle;
	float hypot = 12;
	float opp;
	float mean[30];
	int i;

	// angle =0.1;

	for (i=0;i<30;i++)
	{
	angle = (M_PI/2)*(i/30);
	opp[i] = hypot * sin(angle);

	printf(" \n opposite side = %f cm ", opp[i]);
	}
	printf("angle 5 = %f",opp[4]);

	/*for(angle = 0;angle <= M_PI/2;angle += M_PI/20) // (START ; GOING UNTILL ; STEP)
	{


		opp = hypot * sin(angle);

		printf("opposite side  = %f cm \n\r",opp); // (\n = new line \r = space)

	}
	*/





	printf("Hello World");
	return 0;
}