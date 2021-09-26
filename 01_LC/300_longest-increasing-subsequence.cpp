

/*
 * Date:2021-09-26 10:24
 * filename:300_longest-increasing-subsequence.cpp
 *
 */

/*
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。

例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。


示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
			vector<int> res;
			for (int i = 0; i < (int)nums.size(); i++) {
				auto it = lower_bound(res.begin(), res.end(), nums[i]);
				if (it == res.end()) {
					res.push_back(nums[i]);
				}
				else {
					*it = nums[i];
				}
			}
			return res.size();
    }
    int lengthOfLIS_dp(vector<int>& nums) {
			if (nums.size() == 0) return 0;
			int i = 0;
			vector<int> dp(nums.size() + 1);
			for(i = 0; i < (int)nums.size();i++) {
				dp[i] = 1;
			}
			int res = 1;

			for (i = 1; i < (int)nums.size();i++) {
				for (int j = 0;j < i;j++) {
					if (nums[j] < nums[i]) {
						dp[i] = max(dp[i], dp[j] + 1);
					}
				}
				res = max(dp[i], res);
			}
			return res;
		}
};

int main() {

	vector<int> vec = {10,9,2,5,3,7,101,18};
	vector<int> my_vec = {10,9,2,5,3,7,101,18};
	vector<int> vec_2 = {0,1,0,3,2,3};
	vector<int> my_vec_2 = {0,1,0,3,2,3};
	vector<int> vec_3 = {0,0,0,0,0,0};
	vector<int> my_vec_3 = {0,0,0,0,0,0};
	Solution test;
	cout << "test1: ";
	cout << test.lengthOfLIS(vec) << endl;
	cout << test.lengthOfLIS_dp(my_vec) << endl;

	cout << "test2: ";
	cout << test.lengthOfLIS(vec_2) << endl;
	cout << test.lengthOfLIS_dp(my_vec_2) << endl;
	cout << "test3: ";
	cout << test.lengthOfLIS(vec_3) << endl;
	cout << test.lengthOfLIS_dp(my_vec_3) << endl;


}
