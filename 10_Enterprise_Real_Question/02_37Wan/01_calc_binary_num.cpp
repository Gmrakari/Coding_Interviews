
/*
 * Date:2021-04-17 23:59
 * filename:统计二进制中1的个数
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	unsigned int n;
	cin >> n;
	int cnt = 0;

	while(n)
	{
		n = (n - 1) & n;
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}
