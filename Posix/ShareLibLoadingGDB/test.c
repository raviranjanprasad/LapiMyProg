#include "randapi.h"
#include<stdio.h>
#define ITERATIONS      100

/* Find the average of getSRand() returns */
void findAvg(){
	int fsum = 0.0;
	long  i;
	for (i = 0 ; i < ITERATIONS ; i++) {

		fsum += getSRand();

	}
	printf( "getSRand() Average %f\n", (fsum / (float)ITERATIONS) );
}
int main()
{
	long  isum;
        long i;
	/* Initialize the random number API */
	initRand();

	/* Find the average of getRand(10) returns (0..9) */
	isum = 0L;
	for (i = 0 ; i < ITERATIONS ; i++) {

		isum += getRand(10);

	}

	printf( "getRand() Average %d\n", (int)(isum / ITERATIONS) );


        findAvg();

	return 0;
}
 
 


