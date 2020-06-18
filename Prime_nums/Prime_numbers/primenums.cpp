#include "primenums.h"

PrimeNums::PrimeNums()
{

}


QVector<char> PrimeNums::findNums(ullong N){
	QVector<char> prime(N+1, true);
	prime[0] = prime[1] = false;

	for(ullong i = 2; i <= N; i++){
		if(prime[i]){
			if(i * 1ll * i){
				for(int j = i*i; j <= N; j += i)
					prime[j] = false;
			}
		}
	}
	return prime;
}
