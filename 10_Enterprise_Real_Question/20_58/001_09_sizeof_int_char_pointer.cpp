

/*
 * Date:2021-10-10 19:37
 * filename:001_09_sizeof_int_char_pointer.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int intValue = 58;
	char str[] = "Wuba100";
	const char* ch = str;
	cout << "sizeof(intValue):" << sizeof(intValue) << endl;
	cout << "sizeof(str):" << sizeof (str) << endl;
	cout << "sizeof(ch):" << sizeof(ch) << endl;
}
