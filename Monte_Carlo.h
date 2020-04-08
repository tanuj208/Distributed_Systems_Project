#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<double> (int, int, pair<int, int>) > random_num_gen;
public:
	Monte_Carlo(function < vector<double> (int, int, pair<int, int>) >);
	double generate_pi();
};

#endif