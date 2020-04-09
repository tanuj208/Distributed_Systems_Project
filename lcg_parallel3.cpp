#include "headers.h"

LCG_Parallel3 :: LCG_Parallel3(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel3 :: generate_random_numbers(int count, int seed)
{
	cout<<"Method 3"<<endl;
	vector<long long> tmp;
	return tmp;
}
