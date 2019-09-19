#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char** argv )
{
	int i = 0;
	for (i=0;i<argc;i++){
		printf("\n %s",argv[i]);
	}

	return 0;
}