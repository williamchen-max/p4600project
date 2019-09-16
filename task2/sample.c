#include <stdio.h>
#include <stdlib.h>

int divide(int a,int b)
{
	int c = a/b;

	return c;
}

void divideList(int* inp,int divider, int* outp, int len)
{
	int i = 0;
	for(i=0;i<len;i++)
	{
		outp[i] = inp[i]/divider;
	}
}

int main()
{
	int a[] = {1,2,3,4};
	int b[4];

	divideList(a,2,b,4);
}