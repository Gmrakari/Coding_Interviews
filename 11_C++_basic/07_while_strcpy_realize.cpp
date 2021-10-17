

/*
 * Date:2021-10-15 23:03
 * filename:2021-10-15_while_test.cpp
 *
 */

#include <iostream>
using namespace std;

char* strcpy4(char *p1, char *p2) {
	if (p1 == NULL || p2 == NULL)
		return NULL;

	while (*p2) {
		cout << "*p2:" << *p2 << " "; 
		cout << "*p1:" << *p1 << " "; 
		*p1++ = *p2++;

	} 

	return p1;
}

char* strcpy3(char *p1, char *p2) {
	if (p1 == NULL || p2 == NULL)
		return NULL;
	while(*p1++ = *p2++) ;
	return p1;
}

void test01() {
	char p1[] = "";
	char p2[] = "abc";
	strcpy4(p1, p2);

	cout << "p1:";
	cout << p1 << endl;
}

void test02() {
	char p1[] = "";
	char p2[] = "abc";
	strcpy3(p1, p2);
	
	cout << "p1:" << p1 << endl;
}


int main() {
	cout << "while 1" << endl;

	int i = 5;
	while (i--) 
		cout << i << " ";

	cout << endl;
	cout << "while 2:" << endl;
	int k = 5;
	while (k--) {
		cout << k << " ";
	}
	cout << endl;
	test01();
	test02();
}


