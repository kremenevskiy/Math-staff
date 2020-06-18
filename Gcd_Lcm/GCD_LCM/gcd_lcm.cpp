#include "gcd_lcm.h"

Gcd_Lcm::Gcd_Lcm()
{

}


llong Gcd_Lcm::GCD(llong a, llong b){
	if (!b)
		return a;
	return GCD(b, a % b);
}


llong Gcd_Lcm::LCM(llong a, llong b){
	llong lcm = a * b / GCD(a, b);
	return lcm;
}
