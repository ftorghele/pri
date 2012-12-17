/*
 * readpolicy.h
 *
 *  Created on: Dec 13, 2012
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef READPOLICY_H_
#define READPOLICY_H_

#include <iostream>

class ReadDefaultValuePolicy {
protected:
	template<typename T>
	static T read(T &data, unsigned &start, unsigned &end) {
		return data[end];
	}
};

class ReadExceptionPolicy {
protected:
	template<typename T>
	static T read(T &data, unsigned &start, unsigned &end) {
		if (start == end) {
			throw "Read Exception";
		} else {
			return data[end];
		}
	}
};

#endif /* READPOLICY_H_ */
