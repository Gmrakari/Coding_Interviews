

/*
 * Date:2021-06-20 21:05
 * filename:00_test.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int tmp;
	int count;

	cin >> tmp;
	cin >> count;

	int test;

	vector<int> vec;
	for(int i = 0;i < tmp;i++) {
		cin >> test;
		vec.push_back(test);
	}

	cout << endl;

	cout << "auto output vec:";
	for(auto j : vec) {
		cout << j << " ";
	}
	

	cout << endl;
}
