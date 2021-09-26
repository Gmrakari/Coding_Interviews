

/*
 * Date:2021-09-26 10:13
 * filename:283_move-zeroes.cpp
 *
 */

/*
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
struct display {
	void operator()(const T& x) {
		cout << x << ' ';
	}
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
			int i = 0,j = 0;
			for (i = 0; i < (int)nums.size();i++) {
				if (nums[i] != 0) {
					nums[j++] = nums[i];
				}
			}

			for (i = j;i < (int)nums.size();i++) {
				nums[i] = 0; 
			}
    }
};

int main() {
	vector<int> vec = {1,123,512,0,12,0,5,0,6,0,0,6};
	Solution test;

	test.moveZeroes(vec);
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;
}
