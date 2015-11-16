#include <stdio.h>
#include <immintrin.h>
#include <stdint.h>
#include <omp.h>

double compute_pi_baseline(size_t N);
double compute_pi_baseline_AVX(size_t N);
double compute_pi_openmp(size_t N, int threads);