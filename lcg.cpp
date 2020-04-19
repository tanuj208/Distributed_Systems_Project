#include "headers.h"

long long LCG :: mod_mult(long long a,long long b,long long mod)
{
    return ((a%mod)*(b%mod))%mod;
}

long long LCG :: power(long long x,long long y,long long m)
{
    long long prod = 1;
    while(y>0)
    {
        if(y&1)
            prod = mod_mult(prod,x,m);
        x=mod_mult(x,x,m);
        y/=2;
    }
    return prod;
}

long long LCG :: inv_mod(long long x,long long y,long long m)
{
    return mod_mult(x,power(y,m-2,m),m);
}
