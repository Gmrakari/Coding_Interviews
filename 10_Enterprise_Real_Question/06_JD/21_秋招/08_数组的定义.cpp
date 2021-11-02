

/*
 * Date:2021-11-02 19:30
 * filename:08_数组的定义.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

void testA() {
	int n = 5, a[n];
	cout << a << endl;
}

void testB() {
	int n;
	cin >> n;
	int a[n];
	cout << a << endl;
}

void testC() {
	const int N = 5;
	int a[N];

	cout << a << endl;
}

void testD() {
	int a(5);
	cout << a << endl;	
}

int main() {
	cout << "testA:" << endl;
	testA(); 
	cout << "testB:" << endl;
	testB();
	cout << "testC:" << endl;
	testC();
	cout << "testD:" << endl;
	testD();
}
