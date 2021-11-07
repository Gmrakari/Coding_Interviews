
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

/*
 * update:2021-11-07
 * 思路：将十进制数转换成二进制数再统计1的个数
 */
class Calc {
	public:
		int transfer(int n) {
			vector<int> ret;
			if (n == 0) {
				return 0;
			}

			int temp;
			while (n > 0) {
				temp = n % 2;
				n = n / 2;
				ret.push_back(temp);
			}
			int cnt = 0;
			
			/*
			auto first = ret.rbegin();
			auto last = ret.rend(); 
			
			int cnt = 0;
			while (first != last) {
				if (*first == 1) {
					cnt++;
				}
				first++;
			}
			return cnt;
			*/
			for (vector<int>::iterator first = ret.begin(); first != ret.end();first++) {
				if( *first == 1 ) {
					cnt++;
				}
			}
			return cnt;
		}
};

int main()
{
	unsigned int n;
	cin >> n;

	cout << Solution_1(n) << endl;

	cout << Solution_2(n) << endl;

	Calc test;
	cout << "test:" << test.transfer(n) << endl;

	return 0;
}
