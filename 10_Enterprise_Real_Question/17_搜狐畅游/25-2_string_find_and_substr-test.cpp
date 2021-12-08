

/*
 * Date:2021-12-08 14:45
 * filename:25_test.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string d("20160314");

	string y = d.substr(0, 4);
	cout << "y:" << y << endl;
	int k = d.find("2");
	cout << "k:" << k << endl;
	int i = d.find("3");
	cout << "i:" << i << endl;

	string m = d.substr(k + 2, i - k);
	cout << "m:" << m << endl;

	string dd = d.substr(i + 1, 2);
	cout << "dd:" << dd << endl;

	string n = dd + m + y;
	cout << "n:" << n << endl;

	return 0;
}
