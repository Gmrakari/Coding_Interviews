

/*
 * Date:2021-07-16 23:10
 * filename:02_strlen_and_sizeof_difference.cpp
 *
 */

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
	const char* str = "name";

	cout << "sizeof(str):" << sizeof(str) << endl;
	cout << "strlen(str):" << strlen(str) << endl;
	return 0;
}
