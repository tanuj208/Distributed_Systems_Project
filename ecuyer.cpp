#include "headers.h"

Ecuyer :: Ecuyer(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> Ecuyer :: generate_random_numbers(int count, int seed)
{
	cout<<"Ecuyer"<<endl;
    y10[0] = seed % m1;
	vector<long long> tmp;
	return tmp;
}
