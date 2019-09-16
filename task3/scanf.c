#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float inputx ;
do{
	printf("please enter a number\n"); fflush(stdout);fflush(stdin);

	int correct = scanf("%f",&inputx);

	if (correct ==1)
	{
		printf("\nscanf return %d. input was %f", correct,inputx);
		fflush(stdout);
		return 0;
	}
	else
	{
		printf("\nwrong human\n");fflush(stdout);
		
	}

	
	}while(scanf("%f",&inputx)==0);
	return 0;

 }



 	

 	