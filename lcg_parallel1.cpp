#include "headers.h"

LCG_Parallel1 :: LCG_Parallel1(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel1 :: generate_random_numbers(int count, int seed)
{
	vector<long long> tmp;
	int n = count/num_procs;
	long long x,start;
	for(int i = 0; i<n; i++)
	{
		x = mod_mult(a,prank+i*num_procs,mod); 
		if(i==0 && prank==0)
			start = seed;
		else
			start = ( mod_mult(x,start,mod) + mod_mult(inv_mod(x-1,a-1,mod),b,mod))%mod;
		tmp.push_back(start);
	}
	return tmp;
}
