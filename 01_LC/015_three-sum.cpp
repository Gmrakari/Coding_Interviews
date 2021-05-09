
/*
 * Date:2021-05-06 18:52
 * filename:015_3-sum.cpp
 *
 */

/*
 *
题目：三数之和
 
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。


示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
 

提示：
0 <= nums.length <= 3000
-105 <= nums[i] <= 105

*/

class Solution
{
public:
	vector<vector<int>> threesum(vector<int>& nums)
	{
		int n = nums.size();
		sort(nums.begin(),nums.end());
		vector<vector<int>> ans;

		for(int first = 0; first < n;++first)
		{
			if(first > 0 && nums[first] == nums[first - 1])
			{
				continue;
			}
			int third = n - 1;
			int target = -nums[first];

			for(int second = first + 1;second < n;++second)
			{
				if(second > 0 && nums[second] == nums[second - 1])
				{
					continue;
				}
				while(second < third && nums[second] + nums[third] > target)
				{
					--third;
				}
				if(second == third)
				{
					break;
				}
				if(nums[second] + nums[third] == target)
				{
					ans.push_back(nums[first],nums[second],nums[third]);
				}
			}
		}
		return ans;
	}
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};

        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] > 0)
            {
                return res;
            }
            if( i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(right > left)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(right > left && nums[right] == nums[right - 1] ) right--;
                    while(right > left && nums[left] == nums[left + 1] ) left++;

                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
