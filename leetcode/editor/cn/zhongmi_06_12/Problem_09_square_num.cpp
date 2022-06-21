/**
 * 
 * @filename:Problem_09_square_num.cpp
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/6/12 20:45
 * 
 */

#include "../include/headers.h"

int cnt = 1;

void getTotalBricks(int sizes) {
    if (sizes < 0) return ;
    int dp[sizes + 1];
    for (int i = 1; i <= sizes; i++)
        dp[i] = i;
    dp[0] = 0;

    vector<int> ret;
    vector<int> vec;
    for (int i = 1;; i++) {
        if (i * i <= sizes) {
            ret.push_back(i * i);
            vec.push_back(i);
        }
        else
            break;
    }

    int n = ret.size();
    for (int i = 1; i <= sizes; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= ret[j] && dp[i - ret[j]] + 1 < dp[i])
                dp[i] = dp[i - ret[j]] + 1;
        }
    }
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Case #" << cnt++ << ":" << dp[sizes];
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    int n = 6;
    int ret = 0;

    //ret = getTotalBricks(4);
    //cout << ret << endl;

    getTotalBricks(5);
    getTotalBricks(6);
    getTotalBricks(7);
    return 0;
}


