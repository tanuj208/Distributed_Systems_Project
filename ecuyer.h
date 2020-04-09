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
    long long m1 = 4294967087;
    long long m2 = 4294944443;
    int prank;
	int num_procs;
    vector<vector<long long>> A1 { {0, a12, a13}, {1, 0, 0}, {0, 1, 0} };
    vector<vector<long long>> A2 { {a21, 0, a23}, {1, 0, 0}, {0, 1, 0} };
    vector<long long> y10 {1, 1, 1};
    vector<long long> y20 {1, 1, 1};

    vector<vector<long long>> mult(vector<vector<long long>> mat1, vector<vector<long long>> mat2, long long mod);
    vector<long long> vec_mult(vector<vector<long long>> mat, vector<long long> vec, long long mod);
    vector<vector<long long>> get_identity(int dim);
    vector<vector<long long>> get_power(vector<vector<long long>> mat, int exp, long long mod);
    int distribute_task(int total_work); // <Base task to everybody, number of processes doing 1 task more>
    vector<long long> generate_nums(int count, int start_power, int step_size);

public:
	Ecuyer(int number_of_processes, int rank);
	vector<long long> generate_random_numbers(int count, int seed);
};

#endif