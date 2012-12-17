/*
 * ringbuffer.h
 *
 *  Created on: Dec 13, 2012
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

#define DEFAULT_SIZE 10

#include <iostream>
#include "readpolicy.h"
#include "writepolicy.h"

template<class T, typename WritePolicy, typename ReadPolicy>
class RingBuffer: private WritePolicy, private ReadPolicy {

public:

	RingBuffer(unsigned n = DEFAULT_SIZE) : size(n), start(0), end(0) {
		data = new T[size];
	}

	~RingBuffer() {
		delete[] data;
	}

	RingBuffer(const RingBuffer &o) {

		delete[] data;

		start = o.start;
		end = o.end;
		size = o.size;

		data = new T[size];

		for (int i = 0; i < size; i++) {
			data[i] = o.data[i];
		}
	}

	RingBuffer& operator=(const RingBuffer &o) {
		if (this == &o) return *this;

		delete[] data;

		start = o.start;
		end = o.end;
		size = o.size;

		data = new T[size];

		for (int i = 0; i < size; i++) {
			data[i] = o.data[i];
		}

		return *this;

	}

	void moveStart() {
		(start + 1 < size) ? start += 1 : start = 0;
		//TODO handling start == end
	}

	void moveEnd() {
		(end + 1 < size) ? end += 1 : end = 0;
		//TODO handling start == end
	}

	unsigned getSize() {
		return size;
	}

	T read() {
		return ReadPolicy::read(data, start, end);
	}

	void write(T &value) {
		WritePolicy::write(value);
	}

private:

	unsigned size;
	T *data;
	unsigned start;
	unsigned end;

};

#endif /* RINGBUFFER_H_ */
