#ifndef SOLVE_H
#define SOLVE_H

typedef long long llong;

#include <QString>

class Solve
{
public:
	Solve();


	static QString findSolution(int a, int b, int c);


	static llong GCD(llong a, llong b);

	static int gcd_exp (int a, int b, int & x, int & y);


};

#endif // SOLVE_H
