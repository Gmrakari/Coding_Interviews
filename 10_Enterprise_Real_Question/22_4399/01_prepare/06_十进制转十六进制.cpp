

/*
 * Date:2021-10-21 08:09
 * filename:06_十进制转十六进制.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	vector<int> res;
	cin >> n;
	while (n) {
		int temp = n % 16;
		res.push_back(temp);
		n = n / 16;
	}

	auto first = res.rbegin();
	auto end = res.rend();

	while(first != end) {
		switch (*first) {
			case 10:
				cout << 'A';
				first++;
				break;
			case 11:
				cout << 'B';
				first++;
				break;
			case 12:
				cout << 'C';
				first++;
			  break;
			case 13:
				cout << 'D';
				first++;
				break;
			case 14:
				cout << 'E';
				first++;
				break;
			case 15:
				cout << 'F';
				first++;
				break;
			default:
				cout << *first;
				first++;
				break;
		}
	}
	cout << endl;
}
