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

template <typename T, typename WritePolicy,typename ReadPolicy>
class RingBuffer: private WritePolicy, private ReadPolicy {
public:

	RingBuffer(unsigned _size = 10) : size(_size), start(0), end(0) {
		data = new T[size];
	}

	~RingBuffer() {
		delete[] data;
	}

	T& operator=(const T &o) {
		if (this == &o) {
			return this;
		}
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

private:

	unsigned size;
	T *data;
	unsigned start;
	unsigned end;

};

#endif /* RINGBUFFER_H_ */
