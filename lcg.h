#ifndef LCG_H
#define LCG_H

#include "headers.h"

class LCG
{
private:
	int mod = 2147483647;
	int a = 2147483629;
	int b = 2147483587;
public:
	vector<int> generate_random_numbers(int count, int seed, pair<int, int> range);
};

#endif