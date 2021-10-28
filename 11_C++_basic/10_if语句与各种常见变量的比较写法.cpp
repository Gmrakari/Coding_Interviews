

/*
 * Date:2021-10-28 09:12
 * filename:10_if语句与各种常见变量的比较写法.cpp
 *
 */

#include <iostream>

using namespace std;

void func_int() {
	int x;
	if (x == 0) {}
	if (x != 0) {}
}

void func_float () {
	const float EPSINON = 0.00001;
	float x;
	if ((x >= -EPSINON) && (x <= EPSINON))
		return ;
}

void func_bool() {
	bool flag;
	if (flag) {}

	if (!flag) {}
}


void fun_pointer() {
	char *p;
	if (p == NULL) {}

	if (p != NULL) {}
	
	//if (p) 让人误解为p是bool型变量，注意避免
}
