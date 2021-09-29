

/*
 * Date:2021-09-29 21:10
 * filename:06_NULL_char_fun.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

char* fun(void) {
	char* p = NULL;
	strcpy(p, "hello world!");
	return p;
}

void funchar() {
	char p[] = "hello world";
	printf("%s", p);
	
}

int main() {
	char* p = fun();
	cout << p << endl;
}
