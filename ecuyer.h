#ifndef ECUYER_H
#define ECUYER_H

#include "headers.h"

class Ecuyer
{
private:
    int a12 = 1403580;
    int a21 = 527612;
    int a13 = -810728;
    int a23 = -1370589;
    int m1 = 4294967087;
    int m2 = 4294944443;
    vector<vector<int>> A1 { {0, a12, a13}, {1, 0, 0}, {0, 1, 0} };
    vector<vector<int>> A2 { {a21, 0, a23}, {1, 0, 0}, {0, 1, 0} };
    vector<int> y10 {1, 1, 1};
    vector<int> y20 {1, 1, 1};
public:
	int num_procs;
	Ecuyer(int number_of_processes);
	vector<double> generate_random_numbers(int count, int seed, pair<int, int> range);
};

#endif