#ifndef LCGPARALLEL2_H
#define LCGPARALLEL2_H

#include "headers.h"

class LCG_Parallel2 : public LCG
{
private:
	int num_procs;
	int prank;
public:
	LCG_Parallel2(int number_of_processes, int rank);
	vector<long long> generate_random_numbers(int count, int seed);
};

#endif