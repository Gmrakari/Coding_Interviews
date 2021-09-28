

/*
 * Date:2021-09-26 20:12
 * filename:01_因子分解.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> calc(int n) {
	vector<int> ret;
	for (int i = 1;i <= n;i++) {
		if (n % i == 0) {
			ret.push_back(i);	
		}
	}
	return ret;
}

//n是不小于的那一个数
int res(int n) {
	vector<int> res;
	vector<int> temp;
	vector<int> ret;
	for (int i = 1; i <= 100;i++) {
		res = calc(i);	
		if (res.size() < 2) 
			continue;
		for (int i = 1; i <= (int)res.size();i++) {
			for (int j = 0; j < i; j++) {
				if (res[i] - res[j] >= n) {
					temp.push_back(res[i]);
					ret = temp;
					continue;
				}
				else {
					break;
				}
			}
		}
	}	
	return ret.back();
}

int test() {
	cout << res(2) << endl;

	return 0;
}



int main() {

	int i = 2029099;
	vector<int> res = calc(i);

	for (int j = 0; j < (int)res.size();j++) {
		cout << res[j] << ' ';
	}
	cout << endl;
	test();
	cout << endl;

}
