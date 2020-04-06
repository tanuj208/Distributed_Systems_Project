#include "headers.h"

LCG_Parallel1 :: LCG_Parallel1(int number_of_processes)
{
	num_procs = number_of_processes;	
}

vector<int> LCG_Parallel1 :: generate_random_numbers(int count, int seed, pair<int, int> range)
{
	cout<<"Method 1"<<endl;
	vector<int> tmp;
	return tmp;
}
