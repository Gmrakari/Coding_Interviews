
/*
 * Date:2021-12-15 09:57
 * filename:char_without_0_ending_result.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

char str1[] = {'s', 't', 'r', '\0'};
char str2[] = {'s', 't', 'r'};


int main() {
	cout << str1 << endl;
	cout << str2 << endl;

	int fun6(int);
	int (*pf)(int) = fun6;

	int a = 15;
	//int n = fun6(&a);
	//cout << (&pf)(a) << endl;
	
	//cout << (pf)(256) << endl;
	cout << pf(256) << endl;
}



