#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	int y;
	int* p;

	x = 5;
	y = 7;
	p = &x;

	printf(" x = %d \n y = %d \n p = %p",x,y,p);

	printf("\n*p =%d",*p);

	*p += 2;
	printf("x = %d\n y = %d \n *p = %d ",x,y,*p);

	p
}