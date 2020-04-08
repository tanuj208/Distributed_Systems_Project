#include "headers.h"

LCG_Parallel3 :: LCG_Parallel3(int number_of_processes)
{
	num_procs = number_of_processes;	
}

vector<double> LCG_Parallel3 :: generate_random_numbers(int count, int seed, pair<int, int> range)
{
	cout<<"Method 3"<<endl;
	vector<double> tmp;
	return tmp;
}
