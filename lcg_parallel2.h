#ifndef LCGPARALLEL2_H
#define LCGPARALLEL2_H

#include "headers.h"

class LCG_Parallel2 : public LCG
{
public:
	int num_procs;
	LCG_Parallel2(int number_of_processes);
	vector<int> generate_random_numbers(int count, int seed, pair<int, int> range);
};

#endif