#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

 char letter = 57;  // assign the ascii code
 //char letters = '9'; // assign the character \n = new line , \t = indent, \\ = slash,
 char* word = "Hello World"; //rename sa a pointer which store as array
 char* cursor = word;
 char words[13]; // set up the text array normal way ; no \0 character at the end

 while(*cursor != '\0')   // while loop check condition at the begining
 {
 	printf("%c \n",*cursor);
 	cursor++;
 }

 do // check condition at the end
  {
 	printf("%c \n",*cursor); // printf( "" <- is a format string, variable) can just use the variable in the printf
 	cursor++;
 }
// format specifiers
// printf () %d = interger,%f = float, %c char, %s = string

// scan/ input of a number/data
	char input[64];
	float inputx;

 	printf("please enter a number");
 	scanf("%f",&inputx);
 	printf("\n input was %f",inputx);

 	// printf / scanf   -> to and from console
 	// sprintf / sscanf -> to and from string

 	char a[65];
 	char b = "number %f";
 	char c = "2.74 1.87";

 	sscanf(c, "%f %f",&x,&y);

 	sprintf(a,"number %f",x);
 	sprintf(a,b,x);

 	// fprintf / fscanf -> to and from files

 	FILE * input_file;

	float x;
	float y;

	input_file = fopen("data.dat","r"); // read only

	if(input_file !=NULL) // CHECK IF IS OPEN
	{
		fscanf(input_file,"%f %f",&x,&y);

		fclose(input_file);
	}

	fscanf(input_file,"%f %f",&x,&y);

	fclose(input_file);

	input_file = fopen("hello.txt","w"); // overwirte existing

	fprintf(input_file,"Hello from x %f and y",x,y);

	fclose(input_file);

	input_file = fopen("hello.txt","a"); // add to existing file end

	fprintf(input_file,"Hello from x %f and y",x,y);



}