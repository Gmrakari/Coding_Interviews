

/*
 * Date:2021-09-11 10:08
 * filename:02_fun_call_info.cpp
 *
 */

#include <iostream>
using namespace std;

int inc(int a) { return (++a); };
int multi(int *a, int *b, int *c) { return (*c = *a**b); };
typedef int(FUNC1)(int);
typedef int(FUNC2)(int *, int *, int *);

void show(FUNC2 fun, int arg1, int *arg2) {
	FUNC1 *p = &inc;
	int temp = p(arg1);
	int temp2 = 201;
	fun(&temp2, &arg1, arg2);
	printf("%d\n", *arg2 + temp);
}

int main() {
	int a;
	show(multi, 10, &a);
}

