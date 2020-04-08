#include "headers.h"

Monte_Carlo :: Monte_Carlo(function<vector<int> (int, int)> generate_random_numbers)
{
    random_num_gen = generate_random_numbers;
}

double Monte_Carlo :: generate_pi()
{
    vector<int> tmp = random_num_gen(5, 7);
    return 3.14;
}
