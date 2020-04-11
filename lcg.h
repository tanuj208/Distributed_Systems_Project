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
	long long mod_mult(long long a,long long b,long long mod);
	long long mult(long long x,long long y,long long m);
	long long inv_mod(long long x,long long y,long long m);
};

#endif