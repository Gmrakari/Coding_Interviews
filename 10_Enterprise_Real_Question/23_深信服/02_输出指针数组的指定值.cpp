

/*
 * Date:2021-10-23 10:21
 * filename:02_输出指针数组的指定值.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	char ch[] = "abc\0def";
	char *p = ch;
	printf("%c",*p+4);
	cout << endl;
}
