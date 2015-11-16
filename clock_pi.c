#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compute_pi.h"



double compute_time(clock_t start, clock_t end);

int main(int argc, char *argv[])
{
	clock_t start, end;
	int i, loop = 25;
	int N = atoi(argv[1]);

	//Baseline
	start = clock();
	for (i = 0; i < loop; i++) {
		compute_pi_baseline(N);
	}
	end = clock();
	printf("It is result of  Baselime tha dt = %d : %lf second\n", N, compute_time(start, end) / 25);


	//AVX SIMD
	start = clock();
	for (i = 0; i < loop; i++) {
		compute_pi_baseline_AVX(N);
	}
	end = clock();
	printf("It is result of AVX SIMD that dt = %d : %lf second\n", N, compute_time(start, end) / 25);

	//openmp parallel process in 2 thread
	start = clock();
	for (i = 0; i < loop; i++) {
		compute_pi_openmp(N, 2);
	}
	end = clock();
	printf("It is result of openmp that at dt = %d : %lf second with 2 threads\n", N, compute_time(start, end) / 25);

	//openmp parallel process in 4 thread
	start = clock();
	for (i = 0; i < loop; i++) {
		compute_pi_openmp(N, 4);
	}
	end = clock();
	printf("It is result of openmp that at dt = %d : %lf second with 4 threas\n", N, compute_time(start, end) / 25);

	return 0;
}



double compute_time(clock_t start, clock_t end)
{
	double cal;
	cal = (double)(end - start) / CLOCKS_PER_SEC;
	return cal;
}