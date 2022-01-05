

/*
 * Date:2022-01-05 10:02
 * filename:02_pointer_to_pointer_variable.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

void print(char **str) {
	++str;
	cout << *str << endl;
}

int main() {
	static char *arr[] = {"hello", "world", "c++"};
	char **ptr;
	ptr = arr;
	print(ptr);
	return 0;
}
