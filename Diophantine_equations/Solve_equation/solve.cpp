#include "solve.h"

Solve::Solve()
{

}


QString Solve::findSolution(int a, int b, int c){
	QString result = "";

	int gcd = GCD(a, b);
	if (gcd < 0)
		gcd *= -1;

	result += "GCD - " + QString::number(gcd) + ".\n";
	if(c % gcd != 0){
		result += "No sulution in integer numbers!";
		return result;
	}
	else{
		result += "gcd | c -> Equation have roots in integers\n\n";
	}



	int a1 = a/gcd;
	int b1 = b/gcd;
	int c1 = c/gcd;

	result += "a1 = a / gcd\nb1 = b / gcd\na1*u + b1*v = 1\n\n";


	int u = 0;
	int v = 0;
	gcd_exp(a1, b1, u, v);

	if (a1*u + b1*v != 1){
		u *= -1;
		v *= -1;
	}

	result += "u = " + QString::number(u) + " | v = " + QString::number(v) + "\n";
	result += "1 = " +QString::number(a1) + " * " + QString::number(u) + " + " + QString::number(b1) + " * " + QString::number(v) + "\n\n";

	int x = c / gcd * u;
	int y = c / gcd * v;

	result += "x* = " + QString::number(x) + "\n";
	result += "y* = " + QString::number(y) + "\n\n";

	result += "All roots:\n {(x* + b/gcd * t, y* - a/gcd *t) t from Z}\n\n";
	result += "Especially: x = " + QString::number(x) + " + " + QString::number(b1)  + " * t : (t from Z)\n";
	result += "Especially: y = " + QString::number(y) + " - " + QString::number(a1)  + " * t : (t from Z)\n";


	return result;
}


llong Solve::GCD(llong a, llong b){
	if(!b)
		return a;
	else
		return GCD(b, a % b);
}


int Solve::gcd_exp (int a, int b, int & x, int & y){
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd_exp(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

