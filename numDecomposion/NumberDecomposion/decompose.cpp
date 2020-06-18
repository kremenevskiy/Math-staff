#include "decompose.h"

Decompose::Decompose()
{

}


QString Decompose::decomposeNum(llong a){
	QVector<int> nums;
	llong def = a;
	QString result;

	int i = 2;
	while(a != 1){
		if(a % i == 0){
			a /= i;
			nums.append(i);
			continue;
		}
		i++;
	}

	for(int i = 0; i < nums.size(); i++){
		if(nums[i]){
			int count = 1;
			for(int j = i + 1; j < nums.size(); j++){
				if (nums[i] == nums[j]){
					count ++;
					nums[j] = 0;
				}
			}
			if(count > 1){
				result += QString::number(nums[i]) + "^" + QString::number(count) + " * ";

			}
			else if(count == 1){
				result += QString::number(nums[i]) + "^1 * ";
			}

		}
	}
	result.remove((result.length() - 2), 2);

	if(nums.size() && result.isEmpty()){
		result += QString::number(def);
	}

	return result;
}
