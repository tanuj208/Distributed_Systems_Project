#include "headers.h"

long long mod_mult(long long a,long long b,long long mod)
{
	return ((a%mod)*(b%mod))%mod;
}

long long mult(long long x,long long y,long long m) { long long prod = 1; while(y>0){ if(y&1) prod = mod_mult(prod,x,m); x=mod_mult(x,x,m); y/=2;} return prod;}
long long inv_mod(long long x,long long y,long long m){ return mod_mult(x,mult(y,m-2,m),m);}
LCG_Parallel1 :: LCG_Parallel1(int number_of_processes, int rank)
{
	num_procs = number_of_processes;
	prank = rank;
}

vector<long long> LCG_Parallel1 :: generate_random_numbers(int count, int seed)
{
	// cout<<"Method 1"<<endl;
	vector<long long> tmp;
	// cout<<count<<" "<<seed<<endl;
	// count = 10;
	int n = count/num_procs;
	// cout<<"idhar"<<prank;
	int x,start;
	for(int i = 0; i<n; i++)
	{
		x = mod_mult(a,prank+i*num_procs,mod); 
		if(i==0 && prank==0)
			start = seed;
		else
			start = ( mod_mult(x,start,mod) + mod_mult(inv_mod(x-1,a-1,mod),b,mod))%mod;
		// cout<<prank<<" "<<start<<endl;
		// cout<<start;
		tmp.push_back(start);
	}
	// for(int i = 0; i)
	return tmp;
}
// Sn+i = (ai * Sn +( (ai - 1) / (a-1) )* b ) %m
