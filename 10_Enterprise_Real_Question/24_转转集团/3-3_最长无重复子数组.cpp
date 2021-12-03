

/*
 * Date:2021-12-03 20:30
 * filename:3-3_最长无重复子数组.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxLength(vector<int>& arr) {
		if (arr.size() == 0) 
			return 0;

		unordered_set<int> s;
		int maxlenth = 0;
		int right = 0;
		for (int i = 0;i < (int)arr.size(); ++i) {
			while (right < (int)arr.size() && 0 == s.count(arr[right])) {
				s.insert(arr[right]);
				right++;
			}
			maxlenth = max(maxlenth, right - i);
			s.erase(arr[i]);
		}
		return maxlenth;
	}
};


void test() {
	Solution t;
	vector<int> vec = {1, 3, 5, 7, 9};
	vector<int> vec2 = {1, 50, 2, 3, 4, 4};
	cout << t.maxLength(vec) << endl;
	cout << t.maxLength(vec2) << endl;
}

int main() {
	test();
}
