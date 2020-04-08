#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<int> (int, int) > random_num_gen;
	double get_dist(pair<double, double> pt1, pair<double, double> pt2);
	double convert_to_range(int number, pair<int, int> range, int precision)
	{
		int mod = precision * (range.second - range.first) + 1;
		number %= mod;
		number += precision * range.first;
		return (double)number / precision;
	}
public:
	Monte_Carlo(function < vector<int> (int, int) >);
	double generate_pi();
};

#endif