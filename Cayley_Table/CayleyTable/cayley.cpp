#include "cayley.h"

Cayley::Cayley()
{

}


QString Cayley::buildAddTbl(int n){
	QString Table = "    ";

//	int *table = new int*[n];
	for(int i = 0; i < n; i++){
		if(i == 0){
			for(int k = 0; k < n; k++){
				Table += QString::number(k) + "  ";
			}
			Table += "\n";
		}
		for(int j = 0; j < n; j++){
			if(j == 0){
				Table += QString::number(i) + "  ";
			}
			Table += QString::number((i + j) % n) + "  ";
		}
		Table += "\n";
	}
	return Table;

}


QString Cayley::buildMultyTbl(int n){
	QString Table = "    ";

	for(int i = 0; i < n; ++i){
		if(i == 0){
			for(int k = 0; k < n; k++){
				Table += QString::number(k) + "  ";
			}
			Table += "\n";
		}
		for(int j = 0; j < n; ++j){
			if(j == 0){
				Table += QString::number(i) + "  ";
			}
			Table += QString::number((i*j) % n) + "  ";
		}
		Table += "\n";
	}

	return Table;
}
