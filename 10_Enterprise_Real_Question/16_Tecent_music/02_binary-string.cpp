

/*
 * Date:2021-09-16 19:37
 * filename:02_binary-string.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		/**
		 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
		 *
		 *
		 * @param num string字符串
		 * @return string字符串
		 */
		string maxLexicographical(string num) {
			// write code here
			string res;
			for (int i = 0; i < (int)num.size();i++) {
				if (i == 0 || i == (int)num.size() - 1) {
					res.push_back('0');
				}
				else {
					res.push_back('1');
				}
			}
			return res;
		}
};

class Solution2 {
public:
	string maxLexicographical(string num) { 
		if (num.size() < 0 || num.size() > 1000) {
			return "";
		}
		string str;
		int j = 0;
		
		for (int i = 0; i < (int)num.size();i++) {
			if (num[i] == '0') {
				j = i;
			}
			

		}
		return num;
	}
};

int main() {

	string str;
	cin >> str;

	Solution test;
	cout << test.maxLexicographical(str) << endl;


}
