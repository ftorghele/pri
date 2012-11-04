/*
 * Number.cpp
 *
 *  Created on: Okt 29, 2012
 *      Author: torghele
 */

#include <ostream>
#include "number.h"

Number::Number(float _n) : number(_n) { }
Number::Number() : number(0) { }

Number::~Number(void) {}

bool Number::operator< (const Number& o) {
   return number < o.number;
}

std::ostream& operator<<(std::ostream& output, const Number& o) {
	output << o.number;
	return output;
}
