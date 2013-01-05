/*
 * cache.h
 *
 *  Created on: Jan 5, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef CACHE_H_
#define CACHE_H_

#include "ringbuffer.h"
#include "readpolicy.h"
#include "writepolicy.h"

#include <string>

typedef enum {
	direct_mapped, fully_associative, set_associative
} ASSOCIATIVITY;

class Cache {

public:

	Cache(unsigned _size, unsigned _lineSize, ASSOCIATIVITY _associativity,
			unsigned _associativityLevel = 0) : size(_size), lineSize(_lineSize),
			associativity(_associativity), associativityLevel(_associativityLevel) {

		//TODO Ringbuffer?

	}

	void read(unsigned addr, unsigned size) {
		std::cout << "read\t" << addr << "\t" << size << std::endl;
	}
	void store(unsigned addr, unsigned size) {
		std::cout << "read\t" << addr << "\t" << size << std::endl;
	}
	void load(unsigned addr, unsigned size) {
		std::cout << "read\t" << addr << "\t" << size << std::endl;
	}
	void modify(unsigned addr, unsigned size) {
		std::cout << "read\t" << addr << "\t" << size << std::endl;
	}

private:

	unsigned size;
	unsigned lineSize;
	ASSOCIATIVITY associativity;
	unsigned associativityLevel;

};

#endif /* CACHE_H_ */
