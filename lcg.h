#ifndef LCG_H
#define LCG_H

#include "headers.h"

class LCG
{
protected:
	int mod = 2147483647;
	int a = 2147483629;
	int b = 2147483587;
public:
	vector<long long> generate_random_numbers(int count, int seed);
};

#endif