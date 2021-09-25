

/*
 * Date:2021-09-25 16:14
 * filename:01_LSN.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int temp;
    int i = 0, j = 0;
    vector<int> nums;
    for (i = 0; i < n;i++) {
    	scanf("%d",&temp);
    	nums.push_back(temp);
    }
	if (n <= 1 || n >= 5000) {
        return 0;
    }

    int res = 1;
    vector<int> dp(nums.size() + 1);

    for (i = 0; i < (int)nums.size(); i++)
        dp[i] = 1;

    for(i = 1; i < (int)nums.size();i++) {
        for (j = 0; j <= i;++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(dp[i], res);
    }

	cout << res << endl;
}
