#include "headers.h"

LCG_Parallel1 :: LCG_Parallel1(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel1 :: generate_random_numbers(int count, int seed)
{
	vector<long long> random_nums;
	int n = count/num_procs;
	long long x,start;
	for(int i = 0; i<n; i++)
	{
		x = power(a, prank+i*num_procs, mod);
		if(i==0 && prank==0)
			start = seed;
		else
			start = ( mod_mult(x,start,mod) + mod_mult(inv_mod(x-1,a-1,mod),b,mod))%mod;
		random_nums.push_back(start);
	}
	return random_nums;
}
