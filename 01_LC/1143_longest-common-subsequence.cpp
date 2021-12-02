

/*
 * Date:2021-12-02 16:27
 * filename:1143_longest-common-subsequence.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1,0));
		for (int i = 1; i <= (int)text1.size(); i++) {
			for (int j = 1; j <= (int)text2.size(); j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} 
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[text1.size()][text2.size()];
	}
};
