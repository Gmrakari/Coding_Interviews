/*
 * Date:2021-11-02 16:27
 * filename:03_自增_与_或运算.cpp
 *
 */


#include <iostream>
using namespace std;


int main(int argc,const char* argv[])
{
	int a,b,c,d;
	a = b = c = 1;
	d = ++a||++b&&++c;
	cout << d << endl;
	return 0;
}

