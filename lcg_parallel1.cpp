#include "headers.h"

LCG_Parallel1 :: LCG_Parallel1(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

long long LCG_Parallel1 :: get_starting_value(long long seed, int jump_len)
{
	long long x = power(a, jump_len, mod);
	long long start = (mod_mult(x, seed, mod) + mod_mult(b, inv_mod(x-1, a-1, mod), mod))%mod;
	return start;
}

vector<long long> LCG_Parallel1 :: generate_random_numbers(int count, long long seed)
{
	vector<long long> random_nums;
	int n = count/num_procs;
	long long random_val = get_starting_value(seed, prank + 1);
	long long a_p = power(a, num_procs, mod);
	for(int i = 0; i<n; i++)
	{
		random_nums.push_back(random_val);
		random_val = (mod_mult(a_p, random_val, mod) + mod_mult(inv_mod(a_p-1, a-1, mod), b, mod)) % mod;
	}
	return random_nums;
}
