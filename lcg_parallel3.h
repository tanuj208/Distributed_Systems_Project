#ifndef LCGPARALLEL3_H
#define LCGPARALLEL3_H

#include "headers.h"

class LCG_Parallel3 : public LCG
{
private:
    int a2 = 1140671485;
    int b2 = 12820163;
public:
	int num_procs;
	LCG_Parallel3(int number_of_processes);
	vector<long long> generate_random_numbers(int count, int seed);
};

#endif