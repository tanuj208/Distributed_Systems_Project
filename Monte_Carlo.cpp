#include "headers.h"

Monte_Carlo :: Monte_Carlo(function<vector<int> (int, int, pair<int, int>)> generate_random_numbers)
// Monte_Carlo :: Monte_Carlo(vector<int> generate_random_numbers(int, int, pair<int, int>))
{
    random_num_gen = generate_random_numbers;
}

double Monte_Carlo :: generate_pi()
{
    pair<int, int> r = make_pair(6,1);
    vector<int> tmp = random_num_gen(5, 7, r);
    return 3.14;
}
