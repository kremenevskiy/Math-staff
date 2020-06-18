#ifndef VIZHENER_H
#define VIZHENER_H

#include <QString>


class Vizhener
{
public:
	Vizhener();
	static QString encrypt(QString text, QString key);
	static QString decrypt(QString text, QString key);

};

#endif // VIZHENER_H
