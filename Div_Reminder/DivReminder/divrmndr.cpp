#include "divrmndr.h"

DivRmndr::DivRmndr()
{

}


QString DivRmndr::Decompose(llong a, llong b){

	QString result;
	llong r = 0;
	int q = 0;

	if(a > 0 && b > 0){

		q = a / b;
		r = a % b;

		result = QString::number(b) + " * " + QString::number(q) + " + " + QString::number(r);
	}
	else if(!a){
		result = QString::number(b) + " * " + QString::number(q) + " + " + QString::number(r);
	}
	else if(!b){
		result = "Can't divide by zero!";
	}
	else if(a < 0 && b < 0){
		while(1){
			if (!q){
				r = a - b;
			}
			else{
				r -= b;
			}
			q++;
			if(r >= 0 && r < qAbs(b)){
				break;
			}

		}
		result = QString::number(b) + " * " + QString::number(q) + " + " + QString::number(r);

	}
	else if(a > 0 && b < 0){
		while(1){
			if (!q){
				r = a + b;
			}
			else{
				r += b;
			}
			q--;
			if(r >= 0 && r < qAbs(b)){
				break;
			}

		}
		result = QString::number(b) + " * " + QString::number(q) + " + " + QString::number(r);
	}
	else if(a < 0 && b > 0){
		while(1){
			if (!q){
				r = a + b;
			}
			else{
				r += b;
			}
			q--;;
			if(r >= 0 && r < qAbs(b)){
				break;
			}

		}
		result = QString::number(b) + " * " + QString::number(q) + " + " + QString::number(r);
	}


	return result;
}
