

/*
 * Date:2022-03-23 12:27
 * filename:06_top_kth_nums.cpp
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>//priority_queue

namespace m_qs {
	int partition(std::vector<int> &arr, int low, int high) {
		if (low == high)
			return low;

		int i = low, j = high + 1;
		int val = arr[low];

		while (true) {
			while (arr[++i] > val) {
				if (i == high)
					break;
			}
			while (arr[--j] < val) {
				if (j == low)
					break;
			}
			if (i >= j)
				break;
		}
		std::swap(arr[i], arr[j]);
		return j;
	}

	int rsort(std::vector<int> &arr, int low, int high, int k) {
		int i = partition(arr, low, high);

		if ((i - low) == (k - 1)) 
			return i;
		else if ((i - low) < (k - 1)) 
			return rsort(arr, i + 1, high, k - i);
		else
			return rsort(arr, low, i - 1, k);
	}

	std::vector<int> topK(std::vector<int> arr, int k) {
		if (k > (int)arr.size()) 
			return arr;
		int index = rsort(arr, 0, arr.size() - 1, k);
		return std::vector<int>(arr.begin(), arr.begin() + index + 1);
	}

}

namespace alcarl {
	class Solution {
	public:
		//小顶堆
		class mycomparsion {
		public:
			bool operator()(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
				return lhs.second > rhs.second;
			}
		};

		std::vector<int> topK(std::vector<int> &nums, int k) {
			//统计元素出现频率
			std::unordered_map<int, int> map;//map<nums[i], 对应出现的次数>
			for (int i = 0; i < (int)nums.size(); i++) {
				map[nums[i]]++;
			}

			//对频率排序
			//定义一个小顶堆，大小为k
			std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, mycomparsion> pri_que;

			//用固定大小为k的小顶堆，扫描所有频率的数值
			for (std::unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
				pri_que.push(*it);
				if ((int)pri_que.size() > k) {
					pri_que.pop();
				}
			}

			//找出前k个高频元素，因为小顶堆先弹出的是最小的，所以倒序输出到数组
			std::vector<int> result(k);
			for (int i = k - 1; i >= 0; i--) {
				result[i] = pri_que.top().first;
				pri_que.pop();
			}
			return result;
		}
	};
}
//求第k大的数
namespace m_qs {
	class Solution {
	public:
		std::vector<int> quicksort(std::vector<int> &nums, int start, int end, int k) {
			if (start >= end) return nums;
			int base = nums[start];
			int i = start;
			int j = end;

			while (i < j) {
				while (i < j && nums[j] >= base) //从右往左，寻找比base小的数
					j--;
				std::swap(nums[i], nums[j]);
				while (i < j && nums[i] <= base) 
					i++;
				std::swap(nums[i], nums[j]);
			}
			if ((int)nums.size() - i < k) //如果base右边的数超过k个，则第k大数肯定在base右边，此时就不需要对base左边的进行排序
				quicksort(nums, start, i - 1, k);
			quicksort(nums, i + 1, end, k);
			return nums;
		}
		int findkth(std::vector<int> arr, int n, int k) {
			quicksort(arr, 0, n - 1, k);
			return arr[n - k];
		}
	};
}

void test_01() {
	std::vector<int> arr = {1,2,3,4,5,6,7,9,10};

	int k = 4;

	std::vector<int> vec = m_qs::topK(arr, k);
	for (auto i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main() {
	test_01();
}
