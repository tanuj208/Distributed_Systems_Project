#include "headers.h"

Monte_Carlo :: Monte_Carlo(function<vector<int> (int, int)> generate_random_numbers)
{
    random_num_gen = generate_random_numbers;
}
double Monte_Carlo :: get_dist(pair<double, double> pt1, pair<double, double> pt2)
{
    double x_dist = pt1.first - pt2.first;
    double y_dist = pt1.second - pt2.second;
    double dist = x_dist * x_dist + y_dist * y_dist;
    return sqrt(dist);
}

double Monte_Carlo :: generate_pi()
{
    pair<int, int> range = make_pair(-1,1);
    int seed = 7;
    int count = 10000;
    int precision = 10000;
    vector<int> x_cor = random_num_gen(count, seed);
    vector<int> y_cor = random_num_gen(count, seed);

    int count_inside_circle = 0;
    pair<double, double> circle_center = make_pair(0, 0);
    for(int i=0;i<count;i++)
    {
        double x = convert_to_range(x_cor[i], range, precision);
        double y = convert_to_range(y_cor[i], range, precision);
        pair<double, double> random_pt = make_pair(x, y);
        double dist = get_dist(circle_center, random_pt);
        if(dist <= 1)
            count_inside_circle++;
    }
    cout<<count_inside_circle<<endl;
    double pi = 4 * (double)count_inside_circle / (double)count;

    // srand(seed);
    // int cnt2=0;
    // for(int i=0;i<count;i++)
    // {
    //     double x = rand() % 20001;
    //     x -= 10000;
    //     x/=10000;
    //     double y = rand() % 20001;
    //     y -= 10000;
    //     y/=10000;
    //     pair<double, double> tmp = make_pair(x, y);
    //     if(get_dist(circle_center, tmp) <= 1)
    //     cnt2++;
    // }
    // cout<<cnt2<<" "<<4*(double)cnt2 / (double) count<<endl;
    return pi;
}
