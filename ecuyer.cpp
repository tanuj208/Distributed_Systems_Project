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

Ecuyer :: Ecuyer(int number_of_processes)
{
	num_procs = number_of_processes;	
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

vector<double> Ecuyer :: generate_random_numbers(int count, int seed, pair<int, int> range)
{
    y10[0] = seed % m1;
	vector<double> random_numbers;

	int i;
	vector<vector<long long>> cur_mat1 = A1;
	vector<vector<long long>> cur_mat2 = A2;
	vector<long long> cur_y1 = y10;
	vector<long long> cur_y2 = y20;
	int decimal_factor = 10000;
	for(i=0;i<count;i++)
	{
		cur_y1 = vec_mult(A1, cur_y1, m1);
		cur_y2 = vec_mult(A2, cur_y2, m2);
		long long random_no = (cur_y1[0] + cur_y2[0] + 2 * m1) % m1;
		int modulus = 1 + decimal_factor*(range.second-range.first);
		random_no = (random_no % modulus) + (decimal_factor*range.first);
		double no = (double)random_no / decimal_factor;
		random_numbers.push_back(no);
	}

	// for(i=0;i<random_numbers.size();i++)
	// 	cout<<random_numbers[i]<<" ";
	// cout<<endl;

	return random_numbers;
}
