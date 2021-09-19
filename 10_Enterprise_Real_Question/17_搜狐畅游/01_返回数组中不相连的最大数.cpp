

/*
 * Date:2021-09-18 21:21
 * filename:01_返回数组中不相连的最大数.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int CalcMaxSum(const vector<int>& array) {
	if (array.empty()) {
		return 0;
	}

	int len = array.size();
	if (len == 1) {
		return array[0];
	}

	int ret = 0;
	vector<int> res = vector<int>(array.size(), 0);
	res[0] = array[0];
	res[1] = max(res[0], res[1]);
	int max_num = 0;
	for (int i = 2; i < len;i++) {
		res[i] = max(res[i - 2] + array[i], res[i - 1]);
		ret = res[i];
		if (ret > max_num	) {
			 max_num = ret;	
		}
	}
	return ret;
}

vector<int> init() {
	vector<int> ret = {1,2,3,4,5};
	return ret;
}

int main() {
	cout << CalcMaxSum(init()) << endl;
}
