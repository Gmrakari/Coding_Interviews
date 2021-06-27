

/*
 * Date:2021-06-21 10:15
 * filename:122_best-time-to-buy-and-sell-stock-ii.cpp
 *
 */

/*
 * Relative:
 * 121 -1次
 * 122 -无数次
 * 123 -2次
 * 309 -冷却
 * 188 -k次交易
 * 714 -手续费
 *
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int res = 0;
        for(int i = 1; i < (int)prices.size();i++)
        {
            int diff = prices[i] - prices[i - 1];
            if(diff > 0)
            {
                res += diff;
            }
        }
        return res;
    }
};

/*
 * 动态规划
 * 本题和121-买卖股票的最佳时机的唯一区别是本题股票可以买卖多次了
 * (注意只有一支股票，所以再次购买前要出售掉之前的股票)
 *
 * 在动规五部曲种，这个区别主要是体现在递推公式上，其它都和121-买卖股票的最佳时机一样
 *
 * 重申dp数组的含义
 *		dp[i][0] 表示第i天持有股票所得现金
 *		dp[i][1] 表示第i天不持有股票所得最多现金
 *
 * 如果第i天持有股票即dp[i][0],那么可以由两个状态推出来
 *		第i - 1天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所得金 即:dp[i - 1][0]
 *		第 i 天买入股票，所得现金就是昨天不持有股票的所得现金减去今天得股票价格,即dp[i - 1][1] = dp[i - 1][0] - prices[i]
 *
 * 注意 这里和121买卖股票的最佳时机唯一不同的地方，就是推导dp[i][0]的时候，第i天买入股票的情况
 * 在121买卖股票的最佳时机种，因为股票全程之恶能买卖一次，所以如果买入股票，那么第i天持有股票即dp[i][0]一定是-prices[i]
 * 而本题，因为一支股票可以买卖多次，所以当第i天买入股票的时候，所持有的现金可能由之前买卖过的利润
 *
 * 那么第i天持有股票即dp[i][0]，如果是第i天买入股票，所得现金就是昨天不持有股票的所得现金 减去 今天的股票价格 即dp[i - 1][1] - prices[1]
 *
 * 如果第i天不持有股票即dp[i][1]，那么依然可以由两个状态推出来
 *		第i - 1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即dp[i - 1][1]
 *		第i天卖出股票，所得现金就是按照今天股票的价格卖出后所得现金 即:prices[i] + dp[i - 1][0]
 * 注意这里和121买卖股票的最佳时机就是一样的逻辑，卖出股票收获利润(可能是负值)
 *
 */

class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
			int len = prices.size();
			vector<vector<int>> dp(len, vector<int>(2));
			dp[0][0] -= prices[0];
			dp[0][1] = 0;
			for (int i = 1;i < len;i++) {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);//唯一不同点
				dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
			}
			return dp[len - 1][1];
    }
};
int main() {
	vector<int> vec = {7, 1, 5, 3, 6, 4};
	Solution so;
	cout << so.maxProfit(vec) << endl;

	Solution_2 so_2;
	cout << so_2.maxProfit(vec) << endl;
	return 0;
}
