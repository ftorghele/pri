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

#include <string>

typedef enum {
	direct_mapped, fully_associative, set_associative
} ASSOCIATIVITY;

struct CacheLine {
	std::string tag;
};

class Cache {

public:

	Cache(unsigned _size, unsigned _lineSize, ASSOCIATIVITY _associativity,
			unsigned _associativityLevel = 1) : size(_size), lineSize(_lineSize),
			associativity(_associativity), associativityLevel(_associativityLevel),
			numSets((_size/_lineSize) / _associativityLevel) {

		storage = new CacheLine*[numSets];
		for (unsigned i = 0 ; i < numSets ; i++) storage[i] = new CacheLine[associativityLevel];

		hitRate = missRate = usedCacheLines = 0;

	}

	~Cache() {
		for (unsigned i = 0; i < numSets; i++) delete [] storage[i];
		delete [] storage;
	}

	void read(unsigned addr, unsigned size) {
		std::cout << "read\t" << addr << "\t" << size << std::endl;
	}
	void store(unsigned addr, unsigned size) {
		std::cout << "store\t" << addr << "\t" << size << std::endl;
	}
	void load(unsigned addr, unsigned size) {
		std::cout << "load\t" << addr << "\t" << size << std::endl;
	}
	void modify(unsigned addr, unsigned size) {
		std::cout << "modify\t" << addr << "\t" << size << std::endl;
	}

	unsigned getHitRate() {
		return hitRate;
	}

	unsigned getMissRate() {
		return missRate;
	}

	unsigned getUsedCacheLines() {
		return usedCacheLines;
	}

private:
	CacheLine **storage;
	unsigned size;
	unsigned lineSize;
	ASSOCIATIVITY associativity;
	unsigned associativityLevel;
	unsigned numSets;

	unsigned hitRate, missRate, usedCacheLines;

};

#endif /* CACHE_H_ */
