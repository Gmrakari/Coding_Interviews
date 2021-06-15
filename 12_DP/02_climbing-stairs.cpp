

/*
 * Date:2021-06-15 11:27
 * filename:02_climbing-stairs.cpp
 *
 */
#include <iostream>
#include <new>
using namespace std;

class Solution {
	public:
		int climbStairs(int n) {
			if (n == 0 || n == 1 || n == 2) return n;
			int *res = new int[n];
			res[0] = 1;
			res[1] = 2;
			for (int i = 2;i < n;i++) {
				res[i] = res[i - 1] + res[i - 2];
			}
			return res[n - 1];
			delete [] res;
		}
};

int main() {
	Solution su;
	cout << su.climbStairs(4) << endl;
	return 0;
}
