

/*
 * Date:2021-05-13 17:25
 * filename:50_powx-n.cpp
 *
 */

class Solution
{
	double my_pow(double x,int n)
	{
		long long N = n;
		N >= 0 ? calc_pow(x,N) : (1 / calc_pow(x,-N));
	}
	double calc_pow(double x,int n)
	{
		double res = 1.0;
		if(x == 0)
		{
			return 1.0;
		}
		while(n)
		{
			if( n & 1 )
			{
				res *= x;
			}
			x *= x;
			n = n / 2;
		}
		return res;
	}

};
