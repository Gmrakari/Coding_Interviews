

/*
 * Date:2021-10-25 20:55
 * filename:72_edit_distance.cpp
 *
 */


#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minDistance(string word1, string word2) {
			//dp[i][j], i 代表word1的前i个字符匹配到word2前j个字符的最少步数;
			int m = word1.length();
			int n = word2.length();
			
			vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
			for (int i = 0;i < m + 1;i++) {
				dp[i][0] = i;
			}
			for (int j = 0; j < n + 1;j++) {
				dp[0][j] = j;
			}
			
			//else 有三种操作 insert,delete,replace
			for (int i = 0; i < m + 1;i++) {
				for (int j = 0; j < n + 1;j++) {
					if (word1[i - 1] == word2[j - 1]) 
						dp[i][j] = dp[i - 1][j - 1];
					else { // 1 代表进行了一次 增/删/改 操作
						dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j] + 1, dp[i][j - 1]}) + 1;
					}
				}
			}
			return dp[m][n];
    }
};


string init() {
	string word1 = "horse";
	return word1;
}

string init_2() {
	string word2 = "ros";
	return word2;
}


void test() {

	Solution fun;
	string word1 = init();
	string word2 = init_2();

	cout << fun.minDistance(word1, word2) << endl;
}

int main() {
	test();
}
