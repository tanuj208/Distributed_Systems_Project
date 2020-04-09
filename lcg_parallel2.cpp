#include "headers.h"

LCG_Parallel2 :: LCG_Parallel2(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel2 :: generate_random_numbers(int count, int seed)
{
	cout<<"Method 2"<<endl;
	vector<long long> tmp;
	return tmp;
}
