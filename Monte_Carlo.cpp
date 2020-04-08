#include "headers.h"

Monte_Carlo :: Monte_Carlo(function<vector<double> (int, int, pair<int, int>)> generate_random_numbers)
{
    random_num_gen = generate_random_numbers;
}

double Monte_Carlo :: generate_pi()
{
    pair<int, int> r = make_pair(6,1);
    vector<double> tmp = random_num_gen(5, 7, r);
    return 3.14;
}
