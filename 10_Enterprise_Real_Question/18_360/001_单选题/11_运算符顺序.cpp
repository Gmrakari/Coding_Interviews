

/*
 * Date:2021-10-12 10:34
 * filename:11_运算符顺序.cpp
 *
 */

#include <iostream>
using namespace std;

int main() {
	int x, y = 1;
	int a, b;
	x = (a = 5) + (b = 8);
	x *= y + 7;
	cout << x << endl;
	return 0;
}
