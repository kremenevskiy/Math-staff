#ifndef DIVRMNDR_H
#define DIVRMNDR_H

typedef long long llong;
#include <QString>
#include <QtGlobal>



class DivRmndr
{
public:
	DivRmndr();

	static QString Decompose(llong a, llong b);

};

#endif // DIVRMNDR_H
