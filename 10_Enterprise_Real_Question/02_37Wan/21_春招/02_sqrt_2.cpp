
/*
 * Date:2021-04-18 09:35
 * filename:不用库函数求sqrt(2),精确到小数点后10位
 */

#include <bits/stdc++.h>
using namespace std;
const double N = 0.0000000001;

double Solution_1(double &left,double &right)
{
	double mid;
	while(right > left)
	{
		mid = (left + right) / 2;
		double tmp = mid * mid  - 2;
		if(abs(tmp) <= N)
		{
			return mid;
		}
		else if(tmp < 0)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return mid;
}


int main()
{
	double left = 1.4;
	double right = 1.5;
	double ret = Solution_1(left,right);
	cout << ret << endl;
	return 0;
}
