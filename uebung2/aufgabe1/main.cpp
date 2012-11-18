/*
 * main.cpp
 *
 *  Created on: Nov 14, 2012
 *      Author: torghele
 */

#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

#define SM (sysconf (_SC_LEVEL1_DCACHE_LINESIZE) / sizeof (double))

using namespace std;

int main() {
	srand(time(NULL));

	int mode;
	int N = 1000;
	timeval start, end;
	unsigned sec, usec;

	double mul1[1000][1000];
	double mul2[1000][1000];
	double res[1000][1000];

	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			mul1[i][j] = rand()%10;
			mul2[i][j] = rand()%10;
			res[i][j] = 0;
		}
	}

	cout << "1, 2, or 3:";
	cin >> mode;

	gettimeofday(&start, 0);

	if(mode == 1) {

		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < N; ++k)
					res[i][j] += mul1[i][k] * mul2[k][j];

	} else if(mode == 2) {

		double tmp[N][N];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				tmp[i][j] = mul2[j][i];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < N; ++k)
					res[i][j] += mul1[i][k] * tmp[j][k];

	} else if(mode == 3) {

	//	for (int i = 0; i < N; i += SM)
	//		for (int j = 0; j < N; j += SM)
	//			for (int k = 0; k < N; k += SM)
	//				for (int i2 = 0, int rres = &res[i][j], int rmul1 = &mul1[i][k]; i2 < SM; ++i2, rres += N, rmul1 += N)
	//					for (int k2 = 0, rmul2 = &mul2[k][j]; k2 < SM; ++k2, rmul2 += N)
	//						for (int j2 = 0; j2 < SM; ++j2)
	//							rres[j2] += rmul1[k2] * rmul2[j2];

	} else cout << "wrong input! aborting.." << endl;
	gettimeofday(&end, 0);

	sec = end.tv_sec - start.tv_sec;
	usec = end.tv_usec - start.tv_usec;
	if(usec < 0) {
		usec += 1000000;
		sec--;
	}

	cout << "time used: " << sec << ':' << usec << endl;

    return 0;
}
