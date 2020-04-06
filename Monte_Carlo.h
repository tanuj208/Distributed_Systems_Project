#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<int> (int, int, pair<int, int>) > random_num_gen;
	// vector<int> (*random_num_gen) (int, int, pair<int, int>);
public:
	Monte_Carlo(function < vector<int> (int, int, pair<int, int>) >);
	double generate_pi();
};

#endif