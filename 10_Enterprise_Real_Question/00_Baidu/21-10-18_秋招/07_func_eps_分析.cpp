

/*
 * Date:2021-10-28 10:13
 * filename:07_func_eps_分析.cpp
 *
 */

#include <iostream>
using namespace std;

int arr[16];
int flag = 1;

void func(void* arr_, float eps_) {
	arr_ = new double[20];
	static char str1[128] = "hello";
	char str2[128] = "world";
	//other process
}

int main() {
	float eps = 0.6181828;
	void *arr2 = NULL;
	func(arr2, eps);
	return 0;
}
