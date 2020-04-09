#include "headers.h"

Monte_Carlo :: Monte_Carlo(int number_of_processes, int rank, function<vector<long long> (int, int)> generate_random_numbers)
{
    num_procs = number_of_processes;
    random_num_gen = generate_random_numbers;
    prank = rank;
}

double Monte_Carlo :: generate_pi()
{
    vector<long long> tmp = random_num_gen(5, 7);
    return 3.14;
}
