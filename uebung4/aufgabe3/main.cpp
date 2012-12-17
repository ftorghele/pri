/*
 * main.cpp
 *
 *  Created on: Dec 13, 2012
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#include <iostream>
#include <cassert>

#include <iostream>
#include "ringbuffer.h"
#include "readpolicy.h"
#include "writepolicy.h"

#define SIZE 5

int main(){
	RingBuffer<unsigned, WriteOverwritePolicy, ReadDefaultValuePolicy > rb1(SIZE);
	RingBuffer<unsigned, WriteOverwritePolicy, ReadDefaultValuePolicy > rb2(SIZE);

	// Todo: Selbstzuweisung
	// Todo: Copy-Construktor

	return 0;
}

