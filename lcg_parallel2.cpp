#include "headers.h"

LCG_Parallel2 :: LCG_Parallel2(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel2 :: generate_random_numbers(int count, int seed)
{
	vector<long long> random_nums;
	long long start;
	int n = count/num_procs;
	long long x = power(a,prank*num_procs,mod);
	if(prank==0)
		start = seed;
	else
		start = ( mod_mult(x,seed,mod) + mod_mult(inv_mod(x-1,a-1,mod),b,mod))%mod;
	random_nums.push_back(start);
	for(int i =1; i<n; i++)
	{
		start = ( mod_mult(a,start,mod) + b%mod)%mod;
		random_nums.push_back(start);
	}
	return random_nums;
}
