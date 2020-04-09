#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<long long> (int, int) > random_num_gen;
	double get_dist(pair<double, double> pt1, pair<double, double> pt2);
	double convert_to_range(long long number, pair<int, int> range, int precision);
public:
	int num_procs;
	Monte_Carlo(int number_of_processes, function < vector<long long> (int, int) >);
	double generate_pi();
};

#endif