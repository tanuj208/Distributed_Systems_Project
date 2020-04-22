#ifndef LCGPARALLEL3_H
#define LCGPARALLEL3_H

#include "headers.h"

class LCG_Parallel3 : public LCG
{
private:
    int a2 = 1140671485;
    int b2 = 12820163;
	int num_procs;
	int prank;
	long long get_pth_random_no(int p, int seed);
	vector<long long> gen_nums(int seed, int cnt);
	int distribute_task(int total_work);
public:
	LCG_Parallel3(int number_of_processes, int rank);
	vector<long long> generate_random_numbers(int count, long long seed);
};

#endif