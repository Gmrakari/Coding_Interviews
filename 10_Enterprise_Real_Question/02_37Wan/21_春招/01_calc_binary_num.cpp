
/*
 * Date:2021-04-17 23:59
 * filename:统计二进制中1的个数
 */

#include <bits/stdc++.h>
using namespace std;

int Solution_1(int n)
{
	int cnt = 0;
	while(n)
	{
		n = (n - 1) & n;
		cnt++;
	}
	return cnt;
}

int Solution_2(int n)
{
	int res = 0;
	while(n)
	{
		if(n & 1)
		{
			++res;
		}
		n = n >> 1;
	}
	return res;
}

int main()
{
	unsigned int n;
	cin >> n;
	int cnt = 0;

	cout << Solution_1(n) << endl;

	cout << Solution_2(n) << endl;

	return 0;
}
