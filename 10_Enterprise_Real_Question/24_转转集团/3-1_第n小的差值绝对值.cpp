

/*
 * Date:2021-11-17 20:06
 * filename:3-1_第n小的差值绝对值.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int theNthSmallestAbsoluteValue(vector<int>& arr, int n) {
		vector<int> res;
		int ret = 0;
		int ans;
		for (int i = 0;i < (int)arr.size(); ++i) {
			for (int j = i + 1; j < (int)arr.size(); ++j) {
				ret = arr[i] - arr[j];
				res.push_back(abs(ret));
			}
		}
		sort(res.begin(), res.end(), less<int>());
		for (int i = 0;i < (int)res.size();i++) {
			if (i == n - 1) {
				ans = res[i];
			}
		}
		return ans;
	}
};

void test() {
	vector<int> arr = {1, 4, 1};
	int n = 1;
	Solution res;
	cout << res.theNthSmallestAbsoluteValue(arr, n) << endl;
}

int main() {
	test();
}
