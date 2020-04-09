#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<long long> (int, int) > random_num_gen;
	int num_procs;
	int prank;
public:
	Monte_Carlo(int number_of_processes, int rank, function < vector<long long> (int, int) >);
	double generate_pi();
};

#endif