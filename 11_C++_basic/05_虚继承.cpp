

/*
 * Date:2021-09-15 08:36
 * filename:05_虚继承.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class A {
public:
	void fun() {
		cout << "class A fun()" << endl;
	}
	int a;
};

class B : public A{
public:
	void fun() {
		cout << "class B fun()" << endl;
	}
	int b;

};

class C : public A{
public:
	void fun() {
		cout << "class C fun()" << endl;
	}
	int c;
};

class D : public B, public C{
public:
	void fun() {
		cout << "class D fun()" << endl;
	}
	int d;
};


int main() {
	A a;
	B b;
	C c;
	D d;
	a.fun();
	cout << sizeof(a) << endl;

	b.fun();
	cout << sizeof(b) << endl;

	c.fun();
	cout << sizeof(c) << endl;

	d.fun();
	cout << sizeof(d) << endl;

}

/*
 * 虚继承是解决C++多重继承问题的一种手段，从不同途径继承来的同一基类，会在子类中存在多份拷贝。
 * 这将存在两个问题：
 * 其一，浪费存储空间；
 * 第二，存在二义性问题，通常可以将派生类对象的地址赋值给基类对象，
 * 实现的具体方式是，将基类指针指向继承类（继承类有基类的拷贝）中的基类对象的地址，
 * 但是多重继承可能存在一个基类的多份拷贝，这就出现了二义性。
 *
 * 1、D继承了B,C也就继承了两个虚基类指针
 * 2、虚基类表存储的是，虚基类相对直接继承类的偏移（D并非是虚基类的直接继承类，B,C才是）
 */
