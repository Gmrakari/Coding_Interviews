

/*
 * Date:2021-09-25 16:51
 * filename:04_test.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int i = 0, j = 0;
    int temp = 0;
    vector<int> res;
    for (i = 0;i < n; i++) {
        scanf("%d", &temp);
        res.push_back(temp);
    }

    int ret;
    for (i = res.size() / 2;;) {
        for (j = 0; j < i; j++) {
            if (res[i] > res[j]) {
                ret = 1;
            }
            else {
                ret = 0;
                break;
            }
        }
    }

    for (i = res.size() / 2;;) {
        for (j = res.size();;j--) {
            if (res[j] > res[i]) {
                ret = 1;
            }
            else {
                ret = 0;
                break;
            }
        }
    }

	cout << ret << endl;
	return 0;

}
