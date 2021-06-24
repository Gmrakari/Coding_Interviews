

/*
 * Date:2021-06-24 22:37
 * filename:01_finboacci-number.cpp
 *
 */

/*
 * leetcode:509-fibonacci-number
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int fib(int N) {
		if ( N == 0 || N == 1 ) return N;
		vector<int> dp(N + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2;i <= N;i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[N];
	}
};

int main() {
	Solution so;
	cout << so.fib(4) << endl;
}
