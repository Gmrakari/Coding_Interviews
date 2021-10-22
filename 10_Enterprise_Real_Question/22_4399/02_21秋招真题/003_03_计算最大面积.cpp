

/*
 * Date:2021-10-21 21:25
 * filename:03_计算最大面积.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int max_area(vector<int> &vec) {
	sort(vec.rbegin(), vec.rend());
	return vec[1] * 2;
}

int main() {
	vector<int> vec = {1,11,2,5,10,6,3};
	int ret = max_area(vec);
	cout << ret;
	cout << endl;
}
