

/*
 * Date:2021-07-28 11:15
 * filename:46_求1+2+3+...+N.cpp
 *
 */

/*
 * #题意
题目描述

求1+2+3+...+n，

要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

样例输入
3
5

样例输出
6
15

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * 解法一：利用构造函数求解
 *
 */

class Temp {
	public:
		Temp() { ++N; Sum += N; }

		static void Reset() { N = 0; Sum = 0; }
		static unsigned int GetSum() { return Sum; }

	private:
		static unsigned int N;
		static unsigned int Sum;
};

unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

unsigned int Sum_Solution1(unsigned int n) {
	Temp::Reset();

	Temp *a = new Temp[n];
	delete [] a;
	a = NULL;
	return Temp::GetSum();
}

void test_1() {
	unsigned int Sum_Solution1(unsigned int n);
	unsigned int ret = Sum_Solution1(3);
	cout << ret << endl;
}

/*
 * 解法二:利用虚函数求解
 *
 */

class A;
A* Array[2];

class A {
	public:
		virtual unsigned int Sum(unsigned int n) {
			return 0;
		}
};

class B : public A {
	public:
		virtual unsigned int Sum(unsigned int n) {
			return Array[!!n]->Sum(n - 1) + n;
		}
};

int Sum_Solution2(int n) {
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;

	int value = Array[1]->Sum(n);
	cout << value << endl; 

	return value;
}

void test_2() {
	Sum_Solution2(3);
}

/*
 * 解法三：利用函数指针
 *
 */
typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_Terminator(unsigned int n) {
	return 0;
}

unsigned int Sum_Solution3(unsigned int n) {
	static fun f[2] = {Solution3_Terminator, Sum_Solution3};
	return n + f[!!n](n - 1);
}

void test_3() {
	unsigned int Sum_Solution3(unsigned int n);
	unsigned int ret = Sum_Solution3(3);
	cout << ret << endl;
}

/*
 * 解法四：利用模板类型求解
 *
 */

template <unsigned int n> struct Sum_Solution4 {
	enum Value {
		N = Sum_Solution4< n - 1>::N + n
	};
};

template<> struct Sum_Solution4<1> {
	enum Value {
		N = 1
	};
};

void test_4() {
	int ret = Sum_Solution4<3>::N;
	cout << ret << endl;
}


int main() {
	test_1();
	test_2();
	test_3();
	test_4();
}



