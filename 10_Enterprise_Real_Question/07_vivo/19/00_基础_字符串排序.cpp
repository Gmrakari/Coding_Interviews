

/*
 * Date:2021-07-27 16:21
 * filename:tmp.cpp
 *
 */


#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string str[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	int length = sizeof(str) / sizeof(str[0]);
	sort(str, str + length);

	for (int i = 0; i < n; i++) {
		cout << str[i] << ' ';
	}
	cout << endl;
}
