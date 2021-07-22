

/*
 * Date:2021-07-22 23:02
 * filename:03_大小端存储.cpp
 *
 */

/*
 * 小端存储:字数据的低字节存储在低地址中
 * 大端存储:字数据的高字节存储在低地址中
 *
 */

//sample 32bit的数字0x1234
//small endian:
//地址内容0x4000 0x4001 
//				0x34    0x12

//big endian
//地址内容0x4000 0x4001
//				0x12   0x34

#include <iostream>
using namespace std;

union endian {
	int a;
	char ch;
};

int main() {
	{
		//test-1
		int a = 0x1234;
		char c = (char)(a);

		if (c == 0x12) {
			cout << "big endian" << endl;
		}
		else if (c == 0x34) {
			cout << "small endian" << endl;
		}

	}

	{
		//test-2
		endian value;
		value.a = 0x1234;
		//a 和 ch 共用4字节的内存空间
		if (value.ch == 0x12) {
			cout << "big endian" << endl;
		}
		else if (value.ch == 0x34) {
			cout << "little endian" << endl;
		}
	}
	return 0;
}
