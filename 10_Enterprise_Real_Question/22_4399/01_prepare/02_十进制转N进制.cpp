

/*
 * Date:2021-10-20 20:20
 * filename:01_十进制转二进制.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<int> res;

	int temp = 0;
	while (n > 0) {
		temp = n % m;
		cout << "temp:" << temp << ' ';
		res.push_back(temp);
		n = n / m;
	}
	cout << endl;

	cout << "res:";
	for (int i = res.size() - 1;i >= 0;i--) {
		cout << res[i];
	}
	cout << endl;

	cout << "iterator:";
	auto first = res.rbegin();
	auto end = res.rend();
	while (first != end) {
		cout << *first;
		first++;
	}
	cout << endl;
}
