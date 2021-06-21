

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

int main() {
	vector<int> vec = {7, 1, 5, 3, 6, 4};
	Solution so;
	cout << so.maxProfit(vec) << endl;
	return 0;
}
