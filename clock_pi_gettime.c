#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compute_pi.h"

#define CLOCK_ID CLOCK_REALTIME
#define ONE_SEC 1000000000.0


double diff_in_second(struct timespec t1, struct timespec t2);


int main(int argc, char *argv[])
{
	struct timespec start, end;
	int N = atoi(argv[1]);
	int i, loop = 25;
	double cpu_time1;

	// Baseline
	clock_gettime(CLOCK_REALTIME, &start);
	for (i = 0; i < loop; i++) {
		compute_pi_baseline(N);
	}
	clock_gettime(CLOCK_REALTIME, &end);
	cpu_time1 = diff_in_second(start, end);
	printf("cpu time of Baseline = %lf\n", cpu_time1);

	// OpenMP with 2 threads
	clock_gettime(CLOCK_REALTIME, &start);
	for (i = 0; i < loop; i++) {
		compute_pi_openmp(N, 2);
	}
	clock_gettime(CLOCK_REALTIME, &end);
	cpu_time1 = diff_in_second(start, end);
	printf("cpu time of openmp with 2 threads = %lf\n", cpu_time1);


	// OpenMP with 4 threads
	clock_gettime(CLOCK_REALTIME, &start);
	for (i = 0; i < loop; i++) {
		compute_pi_openmp(N, 4);
	}
	clock_gettime(CLOCK_REALTIME, &end);
	cpu_time1 = diff_in_second(start, end);
	printf("cpu time of openmp with 4 threads = %lf\n", cpu_time1);


	return 0;
}

double diff_in_second(struct timespec t1, struct timespec t2)
{
	struct timespec diff;
	if (t2.tv_nsec - t1.tv_nsec < 0) {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
	} else {
		diff.tv_sec  = t2.tv_sec - t1.tv_sec;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
	}
	return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}