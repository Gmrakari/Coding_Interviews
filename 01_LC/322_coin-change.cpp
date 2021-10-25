

/*
 * Date:2021-10-25 20:31
 * filename:322_coin-change.cpp
 *
 */

/*
 * 322. 零钱兑换
 * 

 给你一个整数数组 coins ,表示不同面额的硬币;以及一个整数 amount ,表示总金额。

 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回-1 。

 你可以认为每种硬币的数量是无限的。

 示例1：

 输入：coins = [1, 2, 5], amount = 11
 输出：3
 解释：11 = 5 + 5 + 1
 示例 2：

 输入：coins = [2], amount = 3
 输出：-1
 示例 3：

 输入：coins = [1], amount = 0
 输出：0
 示例 4：

 输入：coins = [1], amount = 1
 输出：1
 示例 5：

 输入：coins = [1], amount = 2
 输出：2

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/coin-change

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int coinChange(vector<int>& coins, int amount) {
			int Max = amount + 1;
			vector<int> dp(amount + 1, Max);

			dp[0] = 0;
			for (int i = 1;i <= amount;i++) {
				for (int j = 0;j < (int)coins.size();j++) {
					if (coins[j] <= i) {
						dp[i] = min(dp[i], dp[i - coins[j]] + 1);
					}
				}
			}
			return dp[amount];
		}
};

vector<int> init_1() {
	vector<int> coins = {1,2,5};
	return coins;
}

vector<int> init_2() {
	vector<int> coins = {1};
	return coins;
}

void test() {
	Solution test;
	vector<int> coins = init_1();
	int amount = 11;
	cout << test.coinChange(coins, amount) << endl;
	coins = init_2();
	cout << test.coinChange(coins, amount) << endl;

}

int main() {
	test();
}
