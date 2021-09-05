

/*
 * Date:2021-09-05 09:24
 * filename:03_回文字符串.cpp
 *
 */

/*
 *

【题目描述】
最大回文子串是被研究得比较多的一个经典问题。
最近月神想到了一个变种，对于一个字符串，如果不要求子串连续，那么一个字符串的最大回文子串的最大长度是多少呢。

输入描述:
每个测试用例输入一行字符串（由数字 0-9，字母 a-z、A-Z 构成），字条串长度大于 0 且不大于 1000.

输出描述:
输出该字符串的最长回文子串的长度。（不要求输出最长回文串，并且子串不要求连续）

备注:
因为不要求子串连续，所以字符串 abc 的子串有 a、b、c、ab、ac、bc、abc7 个

输入样例：
adbca

输出样例：
3

说明：
因为在本题中，不要求回文子串连续，故最长回文子串为 aba(或 ada、aca)

*/

/*
 * 直接dp或者使用马拉车算法
 */
#include <string>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>

using namespace std;

bool HandleCase();
int dp[1001][1001];

int n;

int main() {
	while(HandleCase()) {
	}
}

bool HandleCase() {
	string str;
	if (!(cin >> str)) {
		return false;
	}

	string rstr = str;
	std::reverse(rstr.begin(), rstr.end());

	n = str.length();
	memset(dp, 0, sizeof(dp));

	int r = 1;
	dp[0][0] = (str[0] == rstr[0]);
	for (int i = 1; i < n; ++i) {
		dp[i][0] = (str[i] == rstr[0]) || dp[i - 1][0];
		dp[0][i] = (str[0] == rstr[i]) || dp[0][i - 1];
	}

	for (int i = 1; i < n; ++i ) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (str[i] == rstr[i]) {
				dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			}
			r = max(r, dp[i][j]);
		}
	}
	cout << r << endl;
	return true;
}
