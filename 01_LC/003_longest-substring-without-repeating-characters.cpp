

/*
 * Date:2021-10-21 10:01
 * filename:003_longest-substring-without-repeating-characters.cpp
 *
 */

/*
 * 无重复字符的最长子串
 *
 */

/*
 * by Leetcode id:大能猫
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.size() == 0)
				return 0;
			int maxlen = 1;
			int flag = 0;
			for (int i = 1; i < (int)s.size();i++) {
				int len = 1;
				for (int j = i;j > flag;j--) {
					if (s[i] != s[j - 1]) //与前面的字符作比较
						len++;
					else {
						flag = j;
						break;
					}
					maxlen = max(maxlen, len);
				}
			}
			return maxlen;
		}
};

void test() {
	string s = "abcde";
	Solution test;
	cout << test.lengthOfLongestSubstring(s) << endl;
}

int main() {
	test();
}
