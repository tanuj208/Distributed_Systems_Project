#include "headers.h"

Ecuyer :: Ecuyer(int number_of_processes)
{
	num_procs = number_of_processes;	
}

vector<double> Ecuyer :: generate_random_numbers(int count, int seed, pair<int, int> range)
{
	cout<<"Ecuyer"<<endl;
    y10[0] = seed % m1;
	vector<double> tmp;
	return tmp;
}
