

/*
 * Date:2021-11-06 10:34
 * filename:13_02_C++中类的static静态成员变量和static静态成员函数.cpp
 *
 */

/*
 * 参考 火焰山大白菜 2018-08-04 11:27:28
 * [https://blog.csdn.net/lms1008611/article/details/81408236]
 *
 */

#include <iostream>
#include <string>

using namespace std;

class test {
	private:
		static int m_value1;//定义类的静态成员变量
	public:
		static int m_value2;//定义类的静态成员变量

	public:
		test() {
			m_value1++;
			m_value2++;
		}
	public:
		static int getValue() { //定义类的静态成员函数
			return m_value1;		
		}
};

int test::m_value1 = 0;	//类的静态成员需要在类外分配内存空间
int test::m_value2 = 0;	//类的静态成员需要在类外分配内存空间

/*
 * 我们在test类中分别定义了一个静态成员变量与静态成员函数
 * 1.静态成员变量
 * -静态成员变量属于整个类所有
 * -静态成员变量的生命期不依赖于任何对象，为程序的生命周期
 * -可以通过类名直接访问公有静态成员变量
 * -所有对象共享类的静态成员变量
 * -可以通过对象名访问公有静态成员变量
 * -静态成员变量需要在类外单独分配空间
 * -静态成员变量在程序内部位于全局数据区(type className::VarName = value)
 *
 * 2.静态成员函数
 * -静态成员函数是类的一个特殊的成员函数
 *  -静态成员函数属于整个类所有，没有this指针
 *  -静态成员函数直接访问静态成员变量和静态成员函数
 *  -可以通过类名直接访问类的共有静态成员函数
 *  -可以通过对象名访问类的公有静态成员函数
 *  -定义静态成员函数，直接使用static关键字修饰即可
 *
 */

int main() {
	test t1;
	test t2;
	test t3;

	cout << "test::m_value2 = " << test::m_value2 << endl; //通过类名直接调用公有静态成员变量，获取对象个数
	cout << "t3.m_value2 = " << t3.m_value2 << endl;			//通过对象名直接调用公有静态成员变量，获取对象个数
	cout << "t3.getValue() = " << t3.getValue() << endl;	//通过对象名调用普通函数获取对象个数

	//cout << t.getValue() << endl;
	
}
