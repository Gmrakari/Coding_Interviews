

/*
 * Date:2021-05-10 23:25
 * filename:046_permutations.cpp
 *
 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
		void backtrack(vector<vector<int>>& res,vector<int>& output,int first,int len)
		{
			//所有数都填完了
			if(first == len)
			{
				res.emplace_back(output);
				return ;
			}
			for(int i = first;i < len;++i)
			{
				//动态维护数组
				swap(output[i],output[first]);
				//继续递归填写下一个数
				backtrack(res,output,first + 1,len);
				//撤销
				swap(output[i],output[first]);
			}
		}

		vector<vector<int>> permute(vector<int>& nums)
		{
			vector<vector<int>> res;
			backtrack(res,nums,0,(int)nums.size());
			return res;
		}
};


class Solution_2 {
	public:
		vector<vector<int>> result;
		vector<int> path;
		void backtracking(vector<int>& nums, vector<bool>& used) {
			// 此时说明找到了一组
			if (path.size() == nums.size()) {
				result.push_back(path);
				return ;
			}
			/*
			 * 
			 * 因为排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。
			 * 而used数组，其实就是记录此时path里都有哪些元素使用了，一个排列里一个元素只能使用一次。
			 * 
			 */

			for (int i = 0; i < (int)nums.size();i++) {
				if (used[i] == true) continue;					//path里已经收录的元素，直接跳过
				used[i] = true;
				path.push_back(nums[i]);
				backtracking(nums, used);
				path.pop_back();
				used[i] = false;
			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			result.clear();
			path.clear();
			vector<bool> used(nums.size(), false);
			backtracking(nums, used);
			return result;
		}
};

int main() {
	vector<int> nums = {1,2,3,4};
	//Solution su;
	Solution_2 so;
	vector<vector<int>> res;

	res = so.permute(nums);
	for(int i = 0; i < (int)res.size();i++) {
		for(int j = 0; j < (int)res[i].size();j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
