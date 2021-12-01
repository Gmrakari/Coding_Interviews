

/*
 * Date:2021-12-01 21:15
 * filename:04_sizeof_fun_and_member_data.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

void Foo(char str[128]) {
	char chArray[]="http://www.hikvision.com";
	char* p = chArray;

	cout << "sizeof(chArray[]): " << sizeof(chArray) << endl;
	cout << "sizeof(str[128]:): " << sizeof(str) << endl; 
	cout << "sizeof(p): " << sizeof(p) << endl; 
}

int main() {
	char str[128];
	Foo(str);
}
