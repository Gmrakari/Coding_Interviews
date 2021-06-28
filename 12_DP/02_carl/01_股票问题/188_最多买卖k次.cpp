

/*
 * Date:2021-06-28 09:23
 * filename:188_最多买卖k次.cpp
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 这道题是123 买卖股票的最佳诗集III的进阶版,这里要求至多有k次交易
 *
 * 动态规划5步曲
 *
 * 1.确定dp数组以及下标的含义
 * 使用二维数组dp[i][j]:第i天的状态为j，所剩下的最大现金是dp[i][j]
 * j的状态为:
 * 0 表示不操作
 * 1 第一次买入
 * 2 第一次卖出
 * 3 第二次买入
 * 4 第二次卖出
 * ...
 *
 * 除了0以外，偶数就是卖出，奇数就是买入
 * 题目要求是至多有k笔交易，那么j的范围就定义为2 * k + 1
 * 所以二维dp数组的定义为:
 * vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
 *
 * 2.确定递推公式
 * dp[i][1] 
 * 操作1:第i天买入股票了，那么dp[i][1] = dp[i - 1][0] - prices[i]
 * 操作2:第i天没有操作,那么dp[i][1] = dp[i - 1][1]
 * 因此 dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
 *
 * dp[i][2]
 * 操作1:第i天卖出股票，那么dp[i][2] = dp[i - 1][1] + prices[i]
 * 操作2:第i天没有操作，那么dp[i][2] = dp[i - 1][2]
 * 因此 dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
 *
 * 同理类比:
 * for (int j = 0; j < 2 * k - 1;j += 2) {
 *		dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
 *		dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i], dp[i - 1][j + 2]);
 * }
 *
 * 本题和123最大的区别就是要类比j为奇数就是买，偶数就是卖的状态
 *
 * 3.dp数组的初始化
 * 第0天没有进行操作, dp[0][0] = 0;
 * 第0天第一次买入股票, dp[0][1] = -prices[0];
 * 第0天第一次卖出股票, dp[0][2] = 0;
 * 第0天第二次买入股票, dp[0][3] = -prices[0];
 * 第0天第二次卖出股票，dp[0][4] = 0;
 *
 * 所以同理可以推出dp[0][j]当j为奇数的时候都初始化为-prices[0]
 * for (int j = 1; j < 2 * k - 1; j += 2) {
 *		dp[0][j] = -prices[0];
 * }
 *
 * 在初始化的地方同样类比j为偶数就是买，奇数就是卖的状态
 *
 * 4.确定遍历顺序
 * dp[i]，依靠dp[i - 1]的数值，一定是从前往后
 *
 */


class Solution {
public:
	int maxProfit_dp(int k, vector<int>& prices) {
		if (prices.size() == 0 ) return 0;
		vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1,0));

		for (int j = 1; j < 2 * k; j += 2) {
			dp[0][j] = -prices[0];
		}

		for (int i = 1;i < (int)prices.size();i++) {
			for (int j = 0; j < 2 * k - 1;j += 2) {
				dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
				dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
			}	
		}
		return dp[prices.size() - 1][2 * k];
	}
};

/*
 * 有的解法是定义一个三位数组dp[i][j][k]
 * 第i天，第j次买卖，k代表买还是卖，从定义上来看是比较直观
 * 但三维数组操作起来有些麻烦
 */


int main() {
	vector<int> test1 = {1, 2, 3, 4, 5};
	int k = 2;
	Solution so;
	cout << "test1: " << endl;
	cout << so.maxProfit_dp(k,test1) << endl;//4
	return 0;
}
