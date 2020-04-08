#ifndef LCGPARALLEL1_H
#define LCGPARALLEL1_H

#include "headers.h"

class LCG_Parallel1 : public LCG
{
public:
	int num_procs;
	LCG_Parallel1(int number_of_processes);
	vector<double> generate_random_numbers(int count, int seed, pair<int, int> range);
};

#endif