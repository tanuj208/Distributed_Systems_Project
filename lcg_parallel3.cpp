#include "headers.h"

LCG_Parallel3 :: LCG_Parallel3(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

long long LCG_Parallel3 :: get_pth_random_no(int p, int seed)
{
	long long x = power(a, p, mod);
	long long r_no = (mod_mult(x, p, mod) + mod_mult(b, inv_mod(x-1, a-1, mod), mod))%mod;
	return r_no;
}

int LCG_Parallel3 :: distribute_task(int total_work)
{
	int base_task = total_work / num_procs;
	int more_work_proc = total_work - base_task * num_procs;
	int nums_to_gen = base_task;

	if(prank < more_work_proc)
		nums_to_gen ++;

	return nums_to_gen;
}

vector<long long> LCG_Parallel3 :: gen_nums(int seed, int cnt)
{
	vector<long long> random_nums;
	int i;
	long long last_num_generated = seed;
	for(i=0;i<cnt;i++)
	{
		long long new_num = (mod_mult(last_num_generated, a2, mod) + b2) % mod;
		random_nums.push_back(new_num);
		last_num_generated = new_num;
	}
	return random_nums;
}

vector<long long> LCG_Parallel3 :: generate_random_numbers(int count, int seed)
{
	long long new_seed = get_pth_random_no(prank+1, seed);
	int nums_to_gen = distribute_task(count);
	vector<long long> random_nums = gen_nums(new_seed, nums_to_gen);
	return random_nums;
}
