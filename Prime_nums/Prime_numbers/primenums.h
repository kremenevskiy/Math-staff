#ifndef PRIMENUMS_H
#define PRIMENUMS_H

#include <iostream>
#include <QVector>

typedef unsigned long long ullong;

class PrimeNums
{
public:
	PrimeNums();
	QVector<char> static findNums(ullong N);
};

#endif // PRIMENUMS_H
