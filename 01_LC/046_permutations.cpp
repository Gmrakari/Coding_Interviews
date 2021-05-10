

/*
 * Date:2021-05-10 23:25
 * filename:046_permutations.cpp
 *
 */

class Solution{
public:
	void backtrack(vectot<vector<int>>& res,vector<int>& output,int first,int len)
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
