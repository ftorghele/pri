/*
 * Number.h
 *
 *  Created on: Okt 29, 2012
 *      Author: torghele
 */

#ifndef NUMBER_H_
#define NUMBER_H_

class Number {

friend std::ostream& operator<<(std::ostream& output, const Number& o);

public:
	Number(float _n);
	Number();
	~Number(void);
	bool operator< (const Number& o);

private:
	float number;
};

#endif /* NUMBER_H_ */
