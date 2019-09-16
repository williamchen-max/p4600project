#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE * input_file;
	float i ;

	input_file = fopen("sin_function","w");

	for(i=0;i<=pi();i+(pi()/4))
	{
		fprintf(input_file,"%f sin(%f)",sin(i),i);
	}


}



 	

 	