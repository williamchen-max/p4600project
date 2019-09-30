#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program a physicist would write! remember to use the -lm option with your compiler when including this file */ 
 
 float find_mean(float* input,int count)
 {
 	int i=0;
 	float sum;
 	float average;

 	for(i=0;i<(count);i++) // add all the number
	{
		sum +=input[i];	
	}
	
	average = sum/count; // divided by total number

	//printf("\nMean = %.3e",average);
	return average;
 }

float st_dev( float* input, int count)
 {
 	int i=0;
 	float sum_diff;
 	float sum;
 	float average;

/* for(i=0;i<(count);i++) // add all the number
	{
		sum +=input[i];	
	}
	
	float mean = sum/count; // divided by total number*/
	//float mean = find_mean(input,count);

/*JAMES:
	The for loop below is going to call find_mean every single element in the array. Since it then loops through the
	array you are going to go through every element count*count times!

	call find_mean once and store the value in a variable in this function before this loop starts.
*/

	for(i=0; i<count; i++) // the square difference of each data
	{
		sum_diff += pow((input[i]-find_mean(input,count)),2);

	}
	

	float std_dev = sqrt(sum_diff/(count-1)); // calculation of stander deviation

	/*JAMES: Keep printing separate from the calculation function */
	printf("\n Standard deviation = %.3e", std_dev);
	

 }

 float stat(float* input, int count)
 {
 	float sum = 0;
 	float sq_sum = 0;
 	int i ;

 	for(i = 0; i<count; i++ )
 	{
 		sum += input[i];
 		sq_sum += input[i] * input[i];
 	}
 	float mean = sum/count;
 	float variance = sq_sum / count-mean * mean;
 	printf("\nMean = %.3e",mean);
	printf("\nStandard deviation = %.3e", sqrt(variance));

 	return sqrt(variance);

 }




int main()
{
	float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};


	st_dev(data,32);

	return 0;
}