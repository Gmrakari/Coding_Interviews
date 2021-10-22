

/*
 * Date:2021-10-20 20:20
 * filename:01_十进制转二进制.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

void calc(int i) {
	int temp = 0;
	vector<int> res;
	if (i == 0) cout << "0";
	while (i > 0) {
		temp = i % 2;
		res.push_back(temp);
		i = i / 2;
	}
	auto first = res.rbegin();
	auto end = res.rend();
	while (first != end) {
		cout << *first;
		first++;
	}
	cout << endl;
}

int main() {

	for (int i = 0;i < 33;i++) {
		//cout << i << " ";
		calc(i);
	}
}
