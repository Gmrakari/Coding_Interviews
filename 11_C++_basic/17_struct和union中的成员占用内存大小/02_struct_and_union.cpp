

/*
 * Date:2021-12-01 09:31
 * filename:struct and union.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Foo {
	public:
		int _id;			//4
		string _str;  //32
		long _data;   //8
};

//union 以占用字节数最大的算
union data{
	//int a;
	//double b;
	//long long c;
	short d;
	string e;
};

int main() {
	cout << "sizeof class Foo:" << sizeof(Foo) << endl;
	cout << "sizeof union data:" << sizeof(data) << endl;
}
