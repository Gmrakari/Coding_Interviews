

/*
 * Date:2021-06-28 09:23
 * filename:123_最多买卖两次.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:

	/*
	 * 1.确定dp数组以及下标的含义
	 *
	 * dp[i][0] 没有操作
	 * dp[i][1] 第一次买入
	 * dp[i][2] 第一次卖出
	 * dp[i][3] 第二次买入
	 * dp[i][4] 第二次卖出
	 *
	 * dp[i][j] i 代表第i天，j为[0-4]5个状态，dp[i][j]表示第i天状态j所剩最大现金
	 *
	 * 2.确定递推公式
	 *
	 * dp[i][0] = 0;
	 * 
	 * dp[i][1] 
	 * 第i天买入股票了，那么dp[i][1] = dp[i - 1][0] - prices[i]
	 * 第i天没有操作，那么dp[i][1] = dp[i - 1][1]
	 *
	 * 因此:dp[i][1] = max(dp[i - 1][0] - prices[i],dp[i - 1][1])
	 *
	 * dp[i][2]
	 * 第i天卖出股票了，那么dp[i][2] = dp[i - 1][1] + prices[i]
	 * 第i天没有操作，沿用前一天卖出股票的状态,即dp[i][2] = dp[i - 1][2]
	 *
	 * 因此:dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2])
	 *
	 * dp[i][3] 
	 * 第i天买入股票了，那么dp[i][3] = dp[i - 1][2] - prices[i]
	 * 第i天没有操作，那么dp[i][3] = dp[i - 1][3]
	 * 因此:dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
	 *
	 * dp[i][4]
	 * 第i天卖出股票了,那么dp[i][4] = dp[i - 1][3] + prices[i]
	 * 第i天没有操作，沿用前一天卖出股票的状态，即dp[i][4] = dp[i - 1][4]
	 * 因此:dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
	 *
	 * 3.dp数组初始化
	 * 第0天没有操作，dp[0][0] = 0;
	 * 第0天第一次买入操作，dp[0][1] = -prices[0];
	 * 第0天第一次卖出操作，dp[0][2] = 0;
	 * 第0天第二次买入操作，dp[0][3] = -prices[0];
	 * 第0天第二次卖出操作，dp[0][4] = 0;
	 *
	 * 4.确定遍历顺序
	 * 从前往后遍历，因为dp[i],依靠dp[i - 1]的数值
	 *
	 */

	int maxProfit_dp(vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> dp(len, vector<int>(5,0));
		dp[0][0] = 0;
		dp[0][1] = -prices[0];
		dp[0][2] = 0;
		dp[0][3] = -prices[0];
		dp[0][4] = 0;

		for(int i = 1; i < (int)prices.size();i++) {
			dp[i][0] = 0;
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
			dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
			dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
		}
		return dp[len - 1][4];
	}

	/*
	 * leetcode 官方题解里的一种优化空间写法
	 * 思路比较绕 见代码随想录_动态规划专题精讲 P129解释
	 *
	 */

	int maxProfit_dp_optimize(vector<int>& prices) {
		if (prices.size() == 0 ) return 0;
		vector<int> dp(5, 0);
		dp[1] = -prices[0];
		dp[3] = -prices[0];
		for (int i = 1; i < (int)prices.size(); i++) {
			dp[1] = max(dp[1], dp[0] - prices[i]);	
			dp[2] = max(dp[2], dp[1] + prices[i]);	
			dp[3] = max(dp[3], dp[2] - prices[i]);	
			dp[4] = max(dp[4], dp[3] + prices[i]);	
		}
		return dp[4];
	}


	/*
	 * 我觉得这个版本比较直观
	 *
	 */

	int maxProfit_dp_optimize_2(vector<int>& prices) {
		int n = prices.size();
		int buy1 = -prices[0],sell1 = 0;
		int buy2 = -prices[0],sell2 = 0;
		for (int i = 1;i < n;i++) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	} 
};

int main() {
	vector<int> test1 = {3, 3, 5, 0, 0, 1, 4};
	vector<int> test2 = {1, 2, 3, 4, 5};
	vector<int> test3 = {7, 6, 4, 3, 1};
	Solution so;
	cout << "test1: " << endl;
	cout << so.maxProfit_dp(test1) << endl;//6

	cout << "test2: " << endl;
	cout << so.maxProfit_dp(test2) << endl;//4

	cout << "test3: " << endl;
	cout << so.maxProfit_dp(test3) << endl;//0

	cout << "optimize:" << endl;

	cout << "test1: " << endl;
	cout << so.maxProfit_dp_optimize(test1) << endl;//6

	cout << "test2: " << endl;
	cout << so.maxProfit_dp_optimize(test2) << endl;//4

	cout << "test3: " << endl;
	cout << so.maxProfit_dp_optimize(test3) << endl;//0

	cout << "optimize_2:" << endl;

	cout << "test1: " << endl;
	cout << so.maxProfit_dp_optimize_2(test1) << endl;//6

	cout << "test2: " << endl;
	cout << so.maxProfit_dp_optimize_2(test2) << endl;//4

	cout << "test3: " << endl;
	cout << so.maxProfit_dp_optimize_2(test3) << endl;//0

	return 0;
}
