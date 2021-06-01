

/*
 * Date:2021-06-01 10:16
 * filename:01_const_ptr_and_ptr_const.cpp
 *
 */

/*
 * const char *ptr 、char const *ptr、 char *ptr const 三者的区别
 * const char *ptr 和 char const *ptr 一样
 */

/*
 * 如果const位于星号的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
 * 如果const位于星号的右侧，const就是修饰指针本身，即指针本身是常量。
 *
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	char str[] = "hello world";
	const char *ptr = str;

	/*
	 * 定义一个指向字符常量的指针，这里，ptr是一个指向 char* 类型的常量，
	 * 所以不能用ptr来修改所指向的内容，换句话说，*ptr的值为const，不能修改。
	 * 但是ptr的声明并不意味着它指向的值实际上就是一个常量，而只是意味着对ptr而言，
	 * 这个值是常量。
	 *
	 */
	cout << "const char *ptr:";
	for (int i = 0; *ptr != '\0';ptr++) {
		cout << ptr[i];
	}
	cout << endl;
	
	//ptr[0] = 'g'; read-only ptr[0],不能修改

	cout << "char str[]:";
	for (int i = 0; i < int(sizeof(str)/sizeof(str[0]));i++) {
		cout << str[i];
	}
	cout << endl;

	str[0] = 'g';


	cout << "print str after str[0] = 'g' change:";
	cout << str << endl;

	//reassign
	ptr = str;
	cout << "reassign and print ptr after str[0] = 'g' change:";
	for (int i = 0; *ptr != '\0';ptr++) {
		cout << ptr[i];
	}
	cout << endl;

	
	char str_1[] = "hello world";
	char* const ptr_1 = str_1;

	/*
	 * 定义一个char * const ptr_1 只读的指针
	 */

	/*
	 * 定义一个常量的字符串指针，这里，ptr_1是一个常量的字符串指针
	 * 所以不能用ptr_1来修改它的指向，换句话说，ptr_1的指针为const，不能修改。
	 * 指针不能够被重定向
	 *
	 */

	cout << "char* const ptr_1 = :";
	cout << ptr_1 << endl;

	char str_2[] = "gello world";
	
	//ptr_1 = str_2; //报错 因为char* const 修饰的是不可改变的指针,就是不能再指向其它

	return 0;
}
