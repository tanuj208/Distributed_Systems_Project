#ifndef LCGPARALLEL1_H
#define LCGPARALLEL1_H

#include "headers.h"

class LCG_Parallel1 : public LCG
{
private:
	int num_procs;
	int prank;
public:
	LCG_Parallel1(int number_of_processes, int rank);
	vector<long long> generate_random_numbers(int count, int seed);
};

#endif