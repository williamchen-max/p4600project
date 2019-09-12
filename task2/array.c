#include <stdio.h>
#include <stdlib.h>

int main()
{
	int array [] = {12,14,16,18};

	//printf("%d",array[2]);

	int* cursor = array;
	int i =0;

	for(i=0;i<90;i++)
	{
		printf("\n%d",*cursor);
		cursor ++;
	}
}	