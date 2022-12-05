/**
 * This file compares the time to multiply matrices
 * both unoptimized and with OMP. 
 */

#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <stdlib.h>

#include "mat.h"

int main(int argc, char* argv[]) {
    struct timespec start;
    struct timespec end;
    //struct timespec res;
    double *a, *b, *c;
    int n;
    int i;

    //n starts awt 100 and goes to 1000
    n = 100;

    for (i = 0; i < 10; i++) 
    {
	a = gen_matrix(n, n);
	b = gen_matrix(n, n);
	c = malloc(sizeof(double) * n * n);

	//start the timer before multiplying
	clock_gettime(CLOCK_REALTIME, &start);
    	mmult(c, a, n, n, b, n, n);
	clock_gettime(CLOCK_REALTIME, &end);//end timer
	//printf("%ld\n", deltaTime(&start, &end)); //print time between start and end
	printf("%ld\n", (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000);
	n = n + 100; //increase n
	free(c);
	free(a);
	free(b); 
    }//end for
}

