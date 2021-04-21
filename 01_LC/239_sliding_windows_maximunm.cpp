
/*
 * Date:2021-04-21 09:36
 * file:239-滑动窗口的最大值
 */

class Solution
{
public:
	vector<int> maxSlidingWindows(vector<int>& nums,int k)
	{
		vector<int> res;
		deque<int> deque;

		for(int i = 0; i < nums.size();++i)
		{
			//#2
			if(!deque.empty() && deque.front() == i - k)
				deque.pop_front();

			while(!deque.empty() && nums[i] > nums[deque.back()])
				deque.pop_back();

			deque.push_back(i);

			if( i >= k - 1 )
				res.push_back(nums[deque.front()]);
		}
		return res;
	}
};
