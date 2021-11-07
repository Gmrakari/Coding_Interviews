

/*
 * Date:2021-11-07 14:44
 * filename:14_delete和delete[]的真正区别.cpp
 *
 */

/*
 * delete释放new释放的单个对象指针指向的内存
 * delete[] 释放new分配的对象数组指针指向的内存
 * int *a = new int[10];
 * delete a			//1
 * delete[] a;	//2
 *
 * 1、针对简单类型，使用new分配后的不管是数组还是非数组形式内存空间用两种方式均可 如:
 *	int*a = new int[10];
 *	delete a;
 *	delete[] a;
 *	这种情况中的释放效果相同，原因在于:分配简单类型内存时，内存大小已经确定，系统可以记忆并且进行管理，
 *	在析构时，系统并不会调用析构函数，它直接通过指针可以获取实际分配的内存空间，哪怕是一个数组空间（在分配过程中
 *	系统会记录分配内存的大小等信息，此信息保存在结构提_CrtMemBlockHeader中
 *
 * 2、针对class，两种方式体现出具体差异
 * 当你通过下列方式分配一个类对象数组:
 * class A {
 * private:
 *	char *m_cBuffer;
 *	int m_nLen;
 *
 * public:
 *   A() {
 *		m_cBuffer = new char[m_nLen];
 *   }
 *   ~A() {
 *		delete[] m_cBuffer;
 *   }
 * };
 *
 * A *a = new A[10];
 * delete a;					//仅仅释放了a指针指向的全部内存空间，但是只调用了a[0]对象的析构函数 剩下的从a[1]到a[9]
 * 这9个用户自行分配的m_cBuffer对应内存空间将不能释放 从而造成内存泄漏
 *
 * delete[] a;			//调用使用类对象的析构函数释放用户自己分配内存空间并且 释放了a指针指向的全部内存空间
 *
 * 所以总结就是：如果ptr代表一个用new申请的内存返回的内存空间地址，即所谓的指针，那么:
 * delete ptr 代表用来释放的内存，且只用来释放ptr指向的内存
 * delete[] rg 用来释放rg指向的内存，还逐一调用数组中的每个对象的destructor
 *
 * 关于new[]和delete[]，其中又分为两种情况:1、为基本数据类型分配和回收空间;2、为自定义类型分配和回收空间
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Base {
	public:
		Base() {
			cout << "Create a Base class" << endl;
		}
		~Base() {
			cout << "Delete a Base class" << endl;
		}
};

int main() {
	Base* pBase = new Base[3];
	//delete pBase;

	//pBase = new Base[3];
	delete[] pBase;
	return 0;
}

/*
 * output:
 *

Create a Base class
Create a Base class
Create a Base class
Delete a Base class
munmap_chunk(): invalid pointer
Aborted (core dumped)
-------------------------------------------- 
Create a Base class
Create a Base class
Create a Base class
Delete a Base class
Delete a Base class
Delete a Base class

*/

/*
 * 只使用delte的时候只出现了一个Delte a Base class,而使用delete[]的时候出现3个Delete a Base class
 * 不过不管使用delete还是delete[]那三个对象的内存中都被删除，既然存储位置都标记为可写，但是使用delete的时候只调用了
 * pBase[0]的系够函数，而使用了delete[] pBase则调用了3个pBase对象的析构函数。
 *
 * 你过内类使用了操作系统资源(Socket, File, Thread等)，单纯把类的对象从内存中删除是不妥当的，因为没有调用对象的析构函数
 * 会导致系统资源不被释放，如果是Socket则会造成Socket资源不被释放，最明显的就是端口号不被释放，系统最大的端口号是65535
 * 如果端口号被占用了，你就不能上网了，如果File资源不被释放，你就永远不能修改这个文件了，甚至不能读这个文件（除非注销或者重启）;
 * 如果线程不被释放，这它总在后台运行，浪费内存和CPU资源，这些资源的释放还是要依靠类的析构函数
 */

