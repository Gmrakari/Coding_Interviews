

/*
 * Date:2021-06-28 09:23
 * filename:122_可以买卖多次.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

	/*
	 * dp[i][0] 第i天 持有股票所得最多现金
	 * dp[i][1] 第i天 不持有股票所得最多现金
	 *
	 * 第i - 1天持有股票没那么就保持现状，所得现金就是昨天持有股票的所得现金 即dp[i - 1][0]
	 * 第i天买入股票,所得现金就是昨天不持有股票的所得现金减去今天的股票的价格 即:dp[i - 1][0] - prices[i]
	 * dp[i][0] = max(dp[i - 1][0],dp[i - 1][0] - prices[i]) 与121唯一不同的地方
	 *
	 * 第i - 1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即:dp[i - 1][1]
	 * 第i天卖出股票，所得现金就是按照今天股票价格加昨天持有股票所得最多现金 即:dp[i - 1][0] + prices[i]
	 * dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
	 *
	 */

	int maxProfit_dp(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) return 0;
		vector<vector<int>> dp(len,vector<int>(2,0));
		dp[0][0] -= prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < len;i++) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);// 与121唯一不同的地方
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[len - 1][1];
	}
};

int main() {
	vector<int> test1 = {7,1,5,3,6,4};
	Solution so;
	cout << "test1: " << endl;
	cout << so.maxProfit_dp(test1) << endl;//7
	return 0;
}
