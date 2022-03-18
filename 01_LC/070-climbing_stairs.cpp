

/*
 * Date:2021-06-04 09:17
 * filename:070-climbing_stairs.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int climbStairs(int n) {
			if(n == 0 || n == 1 || n == 2) return n;
			int res[n];
			res[0] = 1;
			res[1] = 2;
			for(int i = 2; i < n; ++i) {
				res[i] = res[i - 1] + res[i - 2];
			}
			return res[n - 1];
		}
};

int main() {
	Solution su;
	cout << su.climbStairs(3) << endl;
	return 0;
}
