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

void main(int argc ,char** argv )
{
	FILE* inputfile;

	if(argc <2)
	{
		
	}
	inputfile = fopen(argv[1]);
}