

/*
 * Date:2021-10-23 09:55
 * filename:01_宏定义输出.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define MOD(X, Y) X % Y

int main() {
	int x = 67,y = 9;
	printf("%d",MOD(x,y+8)*2);
	cout << endl;
	return 0;
}
