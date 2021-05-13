

/*
 * Date:2021-05-13 16:30
 * filename:905_sort-array-by-parity.cpp
 *
 */

#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*
 * 实现思路:
 * left指向开头,right指向尾部
 * 当left < right 时
 * 一直往右移 直到nums[left] 的元素指向偶数 (& 1 == 1) 那么left++;
 * 一直往左移 直到nums[right] 的元素指向奇数 (& 1 == 0) 那么right--;
 * 交换nums[left] 和 nums[right] 位置，此时奇数在前，偶数在后。
 */

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& nums){
		int right = nums.size() - 1;
		int left = 0;

		while(left < right)
		{
				while(left < right && (nums[left] & 1) == 1){
					left++;
				}
				while(left < right && (nums[right] & 1) == 0){
					right--;
				}
				swap(nums[left],nums[right]);
		}

		return nums;
	}

	void print(vector<int> &vec)
	{
		for(int i = 0; i < vec.size();i++)
		{
			cout << vec[i] << " ";
		}
		cout << endl;
	}
};


int main()
{
	Solution su;
	int arr[] = {1,123,512,2,51,61,67,3,20,10};
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << "len :" << len << endl;
	vector<int> vec(arr,arr+len);
	su.print(vec);
	su.sortArrayByParity(vec);
	su.print(vec);

}
