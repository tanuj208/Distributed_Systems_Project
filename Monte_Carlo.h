#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "headers.h"

class Monte_Carlo
{
private:
	function < vector<int> (int, int) > random_num_gen;
public:
	Monte_Carlo(function < vector<int> (int, int) >);
	double generate_pi();
};

#endif