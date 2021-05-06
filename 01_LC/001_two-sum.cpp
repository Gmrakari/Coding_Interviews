/*
两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/xxqfy5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
 * Date:2021-04-14 09:13
 */


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
    	for(int i = 0;i < nums.size() - 1 ;i++)
    	{
    		for(int j = i + 1;j < nums.size();j++)
    		{
    			if(nums[i] + nums[j] == target)
    				{
                        return {i,j};
                    }
    		}
    	}
        return {};
    }
};

/*
 * Hashtable
 */

class Solution2
{
public:
	vector<int> twoSum2(vector<int>& nums,int target)
	{
		unordered_map<int,int> hashtable;
		for(int i = 0;i < nums.size();++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if(it != hashtable.end())
			{
				return (it->second,i);
			}
		}
		return {};
	}
};
