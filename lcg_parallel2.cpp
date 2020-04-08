#include "headers.h"

LCG_Parallel2 :: LCG_Parallel2(int number_of_processes)
{
	num_procs = number_of_processes;	
}

vector<double> LCG_Parallel2 :: generate_random_numbers(int count, int seed, pair<int, int> range)
{
	cout<<"Method 2"<<endl;
	vector<double> tmp;
	return tmp;
}
