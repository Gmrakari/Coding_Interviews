

/*
 * Date:2021-06-24 11:00
 * filename:121-best-time-to-buy-and-sell-stock.cpp
 *
 */

/*
 * 暴力 找最优间距
 */

class Solution_1{
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 0; i < prices.size();i++) {
            for (int j = i + 1; j < prices.size();j++) {
                maxprofit = max(maxprofit, prices[j] - prices[i]);
            }
        }
        return maxprofit;
    }
};

/*
 * 贪心
 * 因为股票就买卖一次，那么贪心的想法很自然就是取最左最小值
 * 取最右最大值，那么得到的差值就是最大利润
 *
 * 定义一个最小值 & 最大值是当前的 - 最小的
 */
 
class Solution_2{
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf,maxprofix = 0;
        for (int price : prices) {
            maxprofix = max(maxprofix, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofix;
    }
};

class Solution_3 {
public:
	int maxProfit(vector<int>& prices) {
		int n = (int)prices.size();
		int profit = 0;
		int cost = INT_MAX;
		for (int price : prices) {
			cost = min(cost, price);
			profit = max(profit, price - cost);
		}
		return profit;
	}
};

/*
 * 动态规划
 *
 * 1.确定dp数组(dp table)以及下标的含义
 * dp[i][0]表示第i天持有股票所得最多现金，一开始现金是0，
 * 那么加入第i天买入股票现金就是-price[i],这是一个负数
 * dp[i][1]表示第i天不持有股票所得最多现金
 *
 * 2.确定递推公式
 * 如果第i天持有股票即dp[i][0],那么可以由两个状态推出来
 *		第i - 1 天就持有股票，那么就保持现状，所得现金就是昨天持有股票的所有现金 即:dp[i - 1][0]
 *		第 i 天 买入股票，所得现金就是买入今天的股票后所得现金即 -prices[i]
 * 那么dp[i][0]应该选所得现金最大的，所以dp[i][0] = max(dp[i - 1][0], -prices[i]);
 *
 * 如果第i天不持有股票即dp[i][1]，也可以由两个状态推出来
 *		第i - 1天不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即dp[i - 1][1]
 *		第i天卖出股票，所得现金就是按照今天股票加价格卖出后所得现金 即:prices[i] + dp[i - 1][0]
 * 同样dp[i][1]取最大的,dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0])
 *
 * 3.dp数组初始化
 * 由递推公式dp[i][0] = max(dp[i - 1][0], -price[i]) 和 dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
 * 其基础都是要从dp[0][0] 和 dp[0][1]推导出来
 *
 * 那么dp[0][0]表示第0天持有股票，此时的持有股票就一定买入股票了，因为不可能由前一天推出来，
 * 所以dp[0][0] -= prices[0];
 *
 * dp[0][1]表示第0天不持有股票，不持有股票，那么现金就是0，所以dp[0][1] = 0;
 *
 * 4.确定遍历顺序
 * 从递推共公式可以看出dp[i] 都是由dp[i - 1]推导出来，那么一定是从前往后遍历
 *
 * 5.举例推导dp数组
 * 见ipad
 *
 */

class Solution_4 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if ( len == 0 ) return 0;
		vector<vector<int>> dp(len, vector<int>(2));
		dp[0][0] -= prices[0];	//一开始不持有股票
		dp[0][1] = 0;

		for (int i = 1; i < len; i++) {
			dp[i][0] = max(dp[i - 1][0], -prices[i]);
			dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
		}
		return dp[len - 1][1];
	}
};

//优化

class Solution_5 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> dp(2, vector<int>(2));//只需要开辟2 * 2的二维数组
		do[0][0] -= prices[0];
		dp[0][1] = 0;
		for (int i = 1; i < len;i++) {
			dp[i %2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
			dp[i %2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
		}
		return dp[(len - 1) % 2][1];
	}
};
