#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mainf(double* data, int n)
{
	if(data == NULL) return 0; //if the data array is null return 0
	if(n==0) return 0;         // if the data count is 0 return 0
	if(n==1) return *data;     // if the data count is 1 then return the first data point


	double acc = 0;
	for(int i=0; i,n ; i++)
	{
		acc += data[i];
	}

	return acc/n;
}