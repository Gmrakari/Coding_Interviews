

/*
 * Date:2021-09-28 20:14
 * filename:704_binary_search.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
			if (nums.size() < 0) return 0;
			int left = 0;
			int right = nums.size();

			while(left <= right) {
				int mid = (left + right) / 2;
				if (nums[mid] == target) {
					return mid;
				}
				if (nums[mid] > target) {
					right = mid - 1;
				}
				else if (nums[mid] < target) {
					left = mid + 1;
				}
			}
			return 0;
    }
		//求平方根
		int m_sqrt(int x) {
			if (x == 0 || x == 1) return x;
			int left = 0;
			int right = x;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (mid * mid == x) return (int)mid;
				if (mid * mid > x) 
					right = (int)(mid - 1); 
				else if (mid * mid < x) 
					left = (int)(mid + 1);
			}
			return right;
		}
};

int main() {

	vector<int> vec = {1, 3, 4, 5, 6, 8};
	Solution test;
	cout << test.search(vec, 6) << endl;

	cout << test.m_sqrt(5) << endl;

}
