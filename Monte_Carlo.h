#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<long long> (int, int) > random_num_gen;
	double get_dist(pair<double, double> pt1, pair<double, double> pt2);
	double convert_to_range(long long number, pair<int, int> range, int precision);
	int num_procs;
	int prank;
public:
	Monte_Carlo(int number_of_processes, int rank, function < vector<long long> (int, int) >);
	double integration(long long seed);
	double generate_pi(long long seed);
};

#endif