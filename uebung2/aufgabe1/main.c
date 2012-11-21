/*
 * main.c
 *
 *  Created on: Nov 14, 2012
 *      Author: torghele
 */

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <emmintrin.h>

#define SM (CLS / sizeof(double))
#define N 1000

int main() {
	srand(time(NULL));

	struct timeval start, end;
	long long elapsed;

	int i, j, k, i2, j2, k2;

	static double mul1[N][N] __attribute__ ((aligned (CLS)));
	static double mul2[N][N] __attribute__ ((aligned (CLS)));
	static double res[N][N] __attribute__ ((aligned (CLS)));
	static double tmp[N][N] __attribute__ ((aligned (CLS)));
	double *restrict rres;
	double *restrict rmul1;
	double *restrict rmul2;

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			mul1[i][j] = rand()%10;
			mul2[i][j] = rand()%10;
			res[i][j] = 0;
		}
	}

	gettimeofday(&start, 0);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				res[i][j] += mul1[i][k] * mul2[k][j];
	gettimeofday(&end, 0);

	elapsed = 1000000.0 * (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_usec - start.tv_usec);
	printf("time used (original):\t %lld ms\n", elapsed / 1000);

	gettimeofday(&start, 0);
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			tmp[i][j] = mul2[j][i];
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			for (k = 0; k < N; ++k)
				res[i][j] += mul1[i][k] * tmp[j][k];
	gettimeofday(&end, 0);

	elapsed = 1000000.0 * (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_usec - start.tv_usec);
	printf("time used (transposed):\t %lld ms\n", elapsed / 1000);

	gettimeofday(&start, 0);
	for (i = 0; i < N; i += SM)
		for (j = 0; j < N; j += SM)
			for (k = 0; k < N; k += SM)
				for (i2 = 0, rres = &res[i][j],
					rmul1 = &mul1[i][k]; i2 < SM;
					++i2, rres += N, rmul1 += N)
					for (k2 = 0, rmul2 = &mul2[k][j];
						k2 < SM; ++k2, rmul2 += N)
						for (j2 = 0; j2 < SM; ++j2)
						  rres[j2] += rmul1[k2] * rmul2[j2];
	gettimeofday(&end, 0);

	elapsed = 1000000.0 * (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_usec - start.tv_usec);
	printf("time used (sub-matrix):\t %lld ms\n", elapsed / 1000);

    return 0;
}
