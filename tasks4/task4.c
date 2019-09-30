#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "curve.h"

#define FORMATE "%f"

int main(int argc ,char** argv )
{
	float y;

	int i=0;
	//waves();

	FILE * input_file;
	input_file = fopen(argv[1],"r");//open file


	if(input_file !=NULL) // CHECK IF IS OPEN
	{
		int a=0;
		while(fscanf(input_file,FORMATE,&y)!=EOF) // count the number of data
		{
			++a;
		}
		printf("count = %d\n",a);
		rewind(input_file);

		float x[a];
		float smooth[a];

		for (i =0;i<a;i++) // copy any paste all data into x array
		{
			fscanf(input_file,FORMATE,&x[i]);
			//printf("\n%f",x[i]);
		}
		smooth_curve(x,a,smooth);
		
		amplitude(smooth,a);

		
	}
	else
	{
		printf("no file found \n\nterminate");
		return 0;
	}
	

	

}