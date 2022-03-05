

/*
 * Date:2022-03-05 13:37
 * filename:078_subsets.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		ret.clear();
		path.clear();
		backtrack(nums, 0);
		return ret;
	}
	void backtrack(vector<int>& nums, int startIndex) {
		ret.push_back(path);
		if ((int)nums.size() <= startIndex)
			return ; 
		for (int i = startIndex; i < (int)nums.size(); i++) {
			path.push_back(nums[i]);
			backtrack(nums, i + 1);
			path.pop_back();
		}
	}
private:
	vector<vector<int>> ret;
	vector<int> path;
};

void test() {
	vector<int> vec = {1, 2, 3};
	vector<vector<int>> ret;
	Solution test;
	ret = test.subsets(vec);
	for (int i = 0;i < (int)ret.size(); i++) {
		for (int j = 0; j < (int)ret[i].size(); j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main() {
	test();
}
