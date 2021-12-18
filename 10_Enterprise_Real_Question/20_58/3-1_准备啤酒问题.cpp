

/*
 * Date:2021-12-17 20:56
 * filename:3-1_准备啤酒问题.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int calculateExtraNum(int totalNum, int exchangeNum) {
		int ret = 0;
		int left = 0;
		int temp;
		while (totalNum > 0) {
			temp = totalNum / exchangeNum;
			left = totalNum % exchangeNum;
			if (left != 0) {
				ret += temp;
				totalNum = temp + left;
			}
			else {
				ret += temp;
				totalNum = temp;
			}
		}
		return ret;
	}
};

void test() {
	Solution s;
	cout << s.calculateExtraNum(20, 4) << endl;
	cout << s.calculateExtraNum(30, 3) << endl;
	cout << s.calculateExtraNum(31, 3) << endl;

}

int main() {
	test();

}
