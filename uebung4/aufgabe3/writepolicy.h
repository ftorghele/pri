/*
 * writepolicy.h
 *
 *  Created on: Dec 13, 2012
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef WRITEPOLICY_H_
#define WRITEPOLICY_H_

#include <iostream>

class WriteExceptionPolicy {
protected:
	template<typename T>
	static void write(T &value) {
		// Todo: implement
	}
};

class WriteOverwritePolicy {
protected:
	template<typename T>
	static void write(T &value) {
		// Todo: implement
	}
};

class WriteIgnorePolicy {
protected:
	template<typename T>
	static void write(T &value) {
		// Todo: implement

	}
};

#endif /* WRITEPOLICY_H_ */
