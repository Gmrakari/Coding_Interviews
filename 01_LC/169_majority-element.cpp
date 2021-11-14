

/*
 * Date:2021-05-14 10:43
 * filename:169_majority-element.cpp
 *
 */

/*
 * 方法一:
 * 哈希表
 * unordered_map
 */

class Solution
{
	public:
		int majorityElement(vector<int>& nums){
			//unordered_map,key放元素,value统计个数
			unordered_map<int,int> count;
			int cnt = 0,majority = 0;
			for(auto num : nums)
			{
				count[num]++;
				if(count[num] > cnt)
				{
					majority = num;
					cnt = count[num];
				}
			}
			return majority;
		}
};

/*
 * 方法二:
 * 排序
 */

class Solution
{
	public:
		int majorityElement(vector<int>& nums){
			//返回排序的中间下标就是众数
			//OlogN
			sort(nums.begin(),nums.end());
			return nums[nums.size() / 2];
		}
};

/*
 * 分治法
 * 左右两边
 */

class Solution
{
	public:
		int count_in_range(vector<int> &nums,int target,int lo,int hi)
		{
			int count = 0;
			for(int i = lo;i <= hi;++i)
			{
				if(nums[i] == target)
					++count;
			}
			return count;
		}
		int majority_element_rec(vector<int> &nums,int lo,int hi)
		{
			if(lo == hi)
			{
				return nums[lo];
			}
			int mid = (lo + hi) / 2;
			int left_majority = majority_element_rec(nums,lo,mid);
			int right_majority = majority_element_rec(nums,mid + 1,hi);
			if(count_in_range(nums,left_majority,lo,hi) > (hi - lo + 1) / 2)
				return left_majority;
			if(count_in_range(nums,right_majority,lo,hi) > (hi - lo + 1) / 2)
				return right_majority;
			return -1;
		}
		int majorityElement(vector<int<& nums)
		{
			return majority_element_rec(nums,0,nums.size() - 1);
		}
};

//Update:2021-11-04 09:51 新解法
namespace find_nums {
	class compare {
		public:
			bool operator()(map<int, int>::iterator lhs, map<int, int>::iterator rhs) const{
				return lhs->second > rhs->second;
			}
	};
	class Solution {
		public:
			int majorityElement(vector<int>& nums) {
				if (nums.size() < 0)
					return 0;

				map<int, int> CountMap;
				for (int i = 0; i < (int)nums.size();++i) {
					CountMap[nums[i]]++;
				}

				multiset<map<int, int>::iterator, compare> SortSet;
				map<int, int>::iterator ite = CountMap.begin();

				while (ite != CountMap.end()) {
					SortSet.insert(ite);
					++ite;
				}

				multiset<map<int, int>::iterator, compare>::iterator it1 = SortSet.begin();
				int majoritynum = (*it1)->first;
				return majoritynum;
			}
	};
}
