#include "headers.h"

LCG_Parallel1 :: LCG_Parallel1(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel1 :: generate_random_numbers(int count, int seed)
{
	cout<<"Method 1"<<endl;
	vector<long long> tmp;
	return tmp;
}
