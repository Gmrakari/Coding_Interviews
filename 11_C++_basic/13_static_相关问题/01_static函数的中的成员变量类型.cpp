

/*
 * Date:2021-11-05 08:54
 * filename:13_static函数的中的成员变量类型.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

namespace fun{
	static void func() {
		static int a = 10;
		printf("%d\n",a);

	}

	int a = 8;
}

/*
 * 1.静态成员变量
 * 静态成员变量是一种特殊的成员变量，类体中的数据成员声明时前面加上关键字static,即成为该类的静态数据成员，
 * 即静态成员变量。静态成员变量实际上就是类域中的全局变量，必须初始化，且只能在类体外。
 * 初始化时不受private和protected访问限制
 */

class Student {
private:
	char *name;
	int age;
	float score;
	static int num;//static variable

public:
	Student(char *, int, float);
	void say();
};

//方法一
int Student::num = 0;//静态成员变量的初始化同时赋值，初始化可不加static

//方法二
/*
Student::num = 0;//通过类来访问
Student stu;//通过对象来访问，与通过类访问等效
stu.num = 0;

*/

Student::Student(char *name, int age, float score) {
	this->name = name;
	this->age = age;
	this->score = score;
	num++;
}

void Student::say() {
	//在普通成员函数中可以访问静态成员变量
	cout << name << "的年龄是" << age << ",成绩是" << score << "(当前共" << num << "名学生)" << endl;
}

/*
 * 上面的代码申明了静态成员变量num
 *
 * 静态成员变量属于类，不属于某个具体的对象。
 * 如上面的代码，即使创建多个对象，也只为num分配一份内存，所有对象使用的是这份内存中的数据，当某个对象修改了num，
 * 也会影响到其他的对象。static成员变量不占用对象内存，在所有对象外开辟内存，不创建对象也可以访问
 *
 * static成员变量和普通static变量一样，编译时在静态数据区分配内存，到程序结束时才释放。这就意味着static成员变量
 * 不随着对象的创建而分配内存，也不随着对象的销毁而释放内存。
 * 而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。
 *
 * static成员变量初始化不赋值会被默认初始化，一般为0,静态数据区的变量都有默认的初始值，而动态数据区（堆区、栈区）
 * 的变量默认值是垃圾值
 *
 */

namespace derive_data{
	class base {
		public:
			static int num; //声明
	};

	int base::num = 0; //静态成员变量的真正定义

	class derived : public base {};//继承派生动作
}


void test_func() {
	fun::func();
	cout << endl;
}

void test_static_variable() {
	//使用匿名对象
	//匿名对象就是没有明确的给出名字的对象，是对象的一直简写形式
	//一般匿名对象只使用一次，而且匿名对象只在堆内存中开辟空间，而不存在栈内存的引用
	(new Student("小明", 15, 90))->say();
	(new Student("李磊", 16, 80))->say();
	(new Student("张华", 16, 99))->say();
	(new Student("王康", 14, 60))->say();
	cout << endl;
}

namespace member_fun {
	class base {
		public:
			static int staticVar;
			int _var;
			void foo1(int i = staticVar) {
				cout << i << endl;
			}//正确，staticVar为静态数据成员
			/*
			 * void foo2(int i = _var) {
			 *   //错误,_var为普通数据成员
			 * }
			 *
			 */
	};
}

int member_fun::base::staticVar = 0;

void test_static_derived() {
	derive_data::base a;
	derive_data::derived b;
	a.num++;
	cout << "base class static data number num is " << a.num << endl;

	b.num++;
	cout << "derived class static data number num is " << b.num << endl;

	//结论:
	//静态成员变量可以被自己所在类派生类的对象共享
}

void test_fun_member() {
	member_fun::base a;
	a.foo1();
}

//静态成员函数
//1.静态成员变量函数的地址可用普通函数指针储存，而普通成员函数地址需要用类成员函数指针来储存
class Base {
	public:
	static int func1();
	int func2();
};

int (*pf1)() = &Base::func1;//普通的函数指针
int (Base::*pf2)() = &Base::func2;//成员函数指针

//2.静态成员函数不可以调用类的非静态成员。因为静态成员函数不含this指针
//3.静态成员函数不可以同时声明为virtual,const,volatile函数

class Base1 {
	public:
		//virtual static void func1();//'virtual' can only appear on non-static member functions
		//static void func2() const;//static member function cannot have 'const' qualifier (FixIt)
		//static void func3() volatile;//static member function cannot have 'volatile' qualifier (FixIt) 
};

/*
 * 静态函数不包含有编译器提供的隐藏的this指针，它在类没有实例化的时候就存在，所以可以直接用(类名::函数)来调用，
 * 
 * ▲▲并且由于没有this指针，所以也就没有特定的成员供它使用，因为类没有实例化前，这些类成员变量不存在,
 * 系统也没有分配空间给这些变量，且没有this指针，也无法调用这些成员变量，所以他只能使用那些类没有实例化就已经存在静态变量。
 * 
 * 静态成员是可以独立访问的，也就是说，无须创建任何对象实例就可以访问
 *
 * 普通成员函数即非静态函数因为new时传递了一个默认的this指针，所以意味着每一个对象都有一组自己的成员变量，这就意味着他可以
 * 使用这些成员变量，同时也可以使用静态成员变量，因为这些变量在对象还没有new出来之前就已经存在
 *
 * 普通成员函数要通过对象调用，所以要求首先建立一个对象;
 * 而静态成员函数可不建立对象就可以被使用。
 * 因此，与类的非静态数据成员无关的成员函数，虽然可以被定义为非静态函数，但是如果定义为静态函数的话在使用上会更加方便
 * 另外，如果类的成员函数想作为回调函数来使用，一般情况下只能将它定义为静态成员才行
 *
 * 备注：
 * 类在实例化的时候，是通过new关键字来进行的，new时会默认提供一个隐藏的this指针，该指针的作用只要是用来访问实例对象的成员变量的
 *
 */

int main() {
	test_func();
	test_static_variable();
	test_static_derived();
	test_fun_member();

	return 0;
}


