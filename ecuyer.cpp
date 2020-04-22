#include "headers.h"

void print_mat(vector<vector<long long>> mat)
{
	int i,j;
	for(i=0;i<mat.size();i++)
	{
		for(j=0;j<mat[i].size();j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return;
}

Ecuyer :: Ecuyer(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<vector<long long>> Ecuyer ::  mult(vector<vector<long long>> mat1, vector<vector<long long>> mat2, long long mod)
{
	int n = mat1.size();
	vector<vector<long long>> ans(n, vector<long long> (n));
	int i,j,k;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			int val = 0;
			for(k=0;k<n;k++)
			{
				int tmp = (mat1[i][k] * mat2[k][j]) % mod;
				val = (val + tmp) % mod;
			}
			ans[i][j] = val;
		}
	}

	return ans;
}

vector<long long> Ecuyer :: vec_mult(vector<vector<long long>> mat, vector<long long> vec, long long mod)
{
	int n = mat.size();
	vector<long long> ans(n);
	int i,j;
	
	for(i=0;i<n;i++)
	{
		int val = 0;
		for(j=0;j<n;j++)
		{
			int tmp = (mat[i][j] * vec[j]) % mod;
			val = (val + tmp) % mod;
		}
		ans[i] = val;
	}

	return ans;
}

vector<vector<long long>> Ecuyer :: get_identity(int dim)
{
	vector<vector<long long>> ans(dim, vector<long long> (dim));
	int i,j;
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim;j++)
		{
			if(i==j)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
		}
	}
	return ans;
}

vector<vector<long long>> Ecuyer :: get_power(vector<vector<long long>> mat, int exp, long long mod)
{
	int dim = mat.size();
	vector<vector<long long>> cur_mat = mat;
	vector<vector<long long>> ans = get_identity(dim);

	while(exp != 0)
	{
		if(exp % 2 == 1)
			ans = mult(ans, cur_mat, mod);
		exp /= 2;
		cur_mat = mult(cur_mat, cur_mat, mod);
	}
	return ans;
}

int Ecuyer :: distribute_task(int total_work)
{
	int base_task = total_work / num_procs;
	int more_work_proc = total_work - base_task * num_procs;
	int nums_to_gen = base_task;

	if(prank < more_work_proc)
		nums_to_gen ++;

	return nums_to_gen;
}

vector<long long> Ecuyer :: generate_nums(int count, int start_power, int step_size)
{
	vector<vector<long long>> A1_init = get_power(A1, start_power, m1);
	vector<vector<long long>> A2_init = get_power(A2, start_power, m2);

	vector<vector<long long>> A1P = get_power(A1, step_size, m1);
	vector<vector<long long>> A2P = get_power(A2, step_size, m2);

	vector<long long> cur_y1 = vec_mult(A1_init, y10, m1);
	vector<long long> cur_y2 = vec_mult(A2_init, y20, m2);

	int i;
	vector<long long> numbers;
	for(i=0;i<count;i++)
	{
		long long random_no = (cur_y1[0] + cur_y2[0] + 2*m1)%m1;
		numbers.push_back(random_no);

		cur_y1 = vec_mult(A1P, cur_y1, m1);
		cur_y2 = vec_mult(A2P, cur_y2, m2);
	}
	return numbers;
}

vector<long long> Ecuyer :: generate_random_numbers(int count, long long seed)
{
    y10[0] = seed % m1;
	int nums_to_gen = distribute_task(count);
	vector<long long> random_nums = generate_nums(nums_to_gen, prank + 1, num_procs);
	return random_nums;
}
