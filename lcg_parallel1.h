#ifndef LCGPARALLEL1_H
#define LCGPARALLEL1_H

#include "headers.h"

class LCG_Parallel1 : public LCG
{
private:
	int num_procs;
	int prank;
	long long get_starting_value(long long seed, int jump_len);
public:
	LCG_Parallel1(int number_of_processes, int rank);
	vector<long long> generate_random_numbers(int count, long long seed);
};

#endif