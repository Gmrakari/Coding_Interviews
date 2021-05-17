
/*
 * Date:2021-04-18 09:35
 * filename:不用库函数求sqrt(2),精确到小数点后10位
 */

#include <bits/stdc++.h>
using namespace std;
double N = 0.0000000001;

int main()
{
	double left = 1.4;
	double right = 1.5;

	double mid = (left + right) / 2;

	while(right - left > N)
	{
		if(mid * mid > 2)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
		mid = (left + right) / 2;
	}
	cout << mid << endl;
	return 0;
}
