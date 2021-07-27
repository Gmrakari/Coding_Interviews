

/*
 * Date:2021-07-24 15:45
 * filename:03_最长对称字串.cpp
 *
 */

/*
 *
【题目描述】
定义前后两端完全一致的字符串为对称字符串，如"abba"、"caddac"，编写程序，输出字符
串"abcdefiiaaovivoovivcaideumncca"的最长对称子字符串。
（注："aba"这种不算为对称字符串）

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * 暴力枚举 或者 使用Manacher算法
 *
 */

string getMaxMirrorString(string str) {
	string maxStr = "";
	int maxStep = 0;
	int step = 0;

	//顺序便利字符串，以i为中心点，查找对称字串;
	for (int i = 0; i < (int)str.length();i++) {
		for (step = 0; i - step >= 0 && i + step + 1 < (int)str.length(); step++) {
			if (str[i - step] != str[i + step + 1]) 
				break;
		}
		if (step > maxStep) {
			maxStep = step;
			maxStr = str.substr(i - step + 1, i + step);
		}
	}
	return maxStr;
}

string longgestPalingrome(string s) {
	if (s.length() <= 0)
		return "";
	int n = s.length();
	vector<vector<int>> dp(s.length(), vector<int>(s.length()));
	int start = 0;
	int max = 1;
	for (int i = 0;i < n; i++) {
		for (int j = 0; j <= i;j++) {
			if (j == i) {
				dp[i][i] = 1;
			}else if ( i - j == 1 && s[i] == s[j] ) {
				dp[j][i] = 1;
			} else if (i - j > 1 && s[i] == s[j] && dp[j + 1][i - 1] == 1) {
				dp[j][i] = 1;
			}

			if (dp[j][i] == 1 && max < i - j + 1) {
				max = i - j + 1;
				start = j;
			}
		}
	}
	return s.substr(start, max + start);
}

int main() {
	//string str = getMaxMirrorString("abcdefiiaaovivoovivcaideumncca");
	string str = longgestPalingrome("abcdefiiaaovivoovivcaideumncca");
	cout << "original          :abcdefiiaaovivoovivcaideumncca" << endl;
//	cout << "getMaxMirrorString:" << str << endl;
	cout << "getMaxMirrorString:" << str << endl;
}
