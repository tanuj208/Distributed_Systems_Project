#include "headers.h"

Monte_Carlo :: Monte_Carlo(int number_of_processes, int rank, function<vector<long long> (int, int)> generate_random_numbers)
{
    num_procs = number_of_processes;
    random_num_gen = generate_random_numbers;
    prank = rank;
}

double Monte_Carlo :: get_dist(pair<double, double> pt1, pair<double, double> pt2)
{
    double x_dist = pt1.first - pt2.first;
    double y_dist = pt1.second - pt2.second;
    double dist = x_dist * x_dist + y_dist * y_dist;
    return sqrt(dist);
}

double Monte_Carlo :: convert_to_range(long long number, pair<int, int> range, int precision)
{
    int mod = precision * (range.second - range.first) + 1;
    number = (number % mod) + (precision * range.first);
    return (double)number / (double)precision;
}

double func(double x)
{
    double power = (x*x)/2;
    return exp(-power);
}

double Monte_Carlo :: integration()
{
    pair<int, int> range = make_pair(0, 1);
    int seed = 7;
    int count = 100000;
    int precision = 100000;
    vector<long long> random_pts = random_num_gen(count, seed);

    double func_val_sum = 0;
    for(int i=0;i<random_pts.size();i++)
    {
        double pt = convert_to_range(random_pts[i], range, precision);
        double func_val = func(pt);
        func_val_sum += func_val;
    }

    double expected_val;
    if(prank == root_process)
    {
        MPI_Status status;
        for(int pid=1 ; pid<num_procs ; pid++)
        {
            double func_sum;
            MPI_Recv(&func_sum, 1, MPI_DOUBLE, pid, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            func_val_sum += func_sum;
        }
        expected_val = func_val_sum / count;
        MPI_Bcast(&expected_val, 1, MPI_DOUBLE, root_process, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Send(&func_val_sum, 1, MPI_DOUBLE, root_process, send_data_tag, MPI_COMM_WORLD);
        MPI_Bcast(&expected_val, 1, MPI_DOUBLE, root_process, MPI_COMM_WORLD);
    }
    return expected_val;
}

double Monte_Carlo :: generate_pi()
{
    pair<int, int> range = make_pair(-1,1);
    int seed = 7;
    int count = 100000;
    int precision = 100000;
    vector<long long> pts = random_num_gen(2*count, seed);
    pair<double, double> circle_center = make_pair(0, 0);

    int count_inside_circle = 0;
    int total_cnt = pts.size() / 2;
    for(int i=0;i<total_cnt;i+=2)
    {
        double x = convert_to_range(pts[i], range, precision);
        double y = convert_to_range(pts[i+1], range, precision);
        pair<double, double> random_pt = make_pair(x, y);
        double dist = get_dist(circle_center, random_pt);
        if(dist <= 1)
            count_inside_circle++;
    }

    double pi;
    if(prank == root_process)
    {
        int total_coors = total_cnt/2;
        int inside_circle = count_inside_circle;
        MPI_Status status;

        for(int pid=1 ; pid<num_procs ; pid++)
        {
            int tot;
            int inside;
            MPI_Recv(&tot, 1, MPI_INT, pid, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            MPI_Recv(&inside, 1, MPI_INT, pid, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            total_coors += tot/2;
            inside_circle += inside;
        }
        pi = 4 * (double)inside_circle / (double)total_coors;
        MPI_Bcast(&pi, 1, MPI_DOUBLE, root_process, MPI_COMM_WORLD);
    }
    else
    {
        MPI_Send(&total_cnt, 1, MPI_INT, root_process, send_data_tag, MPI_COMM_WORLD);
        MPI_Send(&count_inside_circle, 1, MPI_INT, root_process, send_data_tag, MPI_COMM_WORLD);
        MPI_Bcast(&pi, 1, MPI_DOUBLE, root_process, MPI_COMM_WORLD);
    }

    return pi;
}
