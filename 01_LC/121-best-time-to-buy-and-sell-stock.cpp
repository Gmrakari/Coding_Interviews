

/*
 * Date:2021-06-24 11:00
 * filename:121-best-time-to-buy-and-sell-stock.cpp
 *
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
