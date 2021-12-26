

/*
 * Date:2021-12-26 08:44
 * filename:03_copy-reference-difference.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	std::string str1("trend");
	std::string str2("micro");

	std::string& strs = str1;
	std::string* ptrs = &str1;
	strs = str2;
	ptrs = &str2;

	cout << strs << endl;
	cout << *ptrs << endl;
}
