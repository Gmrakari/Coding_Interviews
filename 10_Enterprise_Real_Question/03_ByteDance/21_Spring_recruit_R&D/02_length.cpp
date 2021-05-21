

/*
 * Date:2021-05-11 20:10
 * filename:02_length.cpp
 *
 */

#include <bits/stdc++.h>
#include <cstring>
using namespace std;

int main()
{
	char *p = "word";
	char s[] = {"word"};

	cout << "*p : " << p << endl;

	cout << "strlen(p)" << strlen(p) << endl;

	cout << "sizeof(p) / sizeof(p[0]) = " << (sizeof(p) / sizeof(p[0])) << endl;

	cout << endl;
	cout << endl;
	
	cout << "s[] = {" << s << "}" << endl; 

	cout << "strlen(s)" << strlen(s) << endl;

	cout << "sizeof(s)  / sizeof(s[0]) = " << sizeof(s) / sizeof(s[0]) << endl;
}
