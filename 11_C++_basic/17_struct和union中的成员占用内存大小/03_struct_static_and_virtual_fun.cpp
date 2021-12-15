

/*
 * Date:2021-12-15 09:24
 * filename:03_struct_static_and_virtual_fun.cpp
 *
 */

#include <iostream>

namespace four_byte {
#pragma pack(push)
#pragma pack(4)
class CTest {
public:
	CTest():m_chData('\0'), m_nData(0) {}
	virtual void mem_fun() {} //4 virtual 存在一个虚函数表，需要4个字节

private:
	char m_chData;				//1 ---pad 3 -->4
	int m_nData;					//4 
	static char s_chData; //0 static成员变量是存储在静态区当中的，它是一个共享的量
												//  static 在堆上  不在类内
												//  static的成员变量属于类域，不算入对象中
};

#pragma pack(pop)
char CTest::s_chData = '\0';
}
// 8 + 1 + 4 + 3 ->16



namespace one_byte {
#pragma pack(push)
#pragma pack(1)
class CTest {
public:
	CTest():m_chData('\0'), m_nData(0) {}
	virtual void mem_fun() {}		//8

private:
	char m_chData;				//1 < 2 1
	int m_nData;					//4 > 2 ->2
	static char s_chData; //同上namespace解释
};
//total 8 + 1 + 4 -->ouput:13

#pragma pack(pop)
char CTest::s_chData = '\0';
}

class static_test {
public:
	virtual void mem_fun() {}
private:
	static char s_chData;
};

char static_test::s_chData = '\0';

int main() {
	printf("sizeof:CTest 4 byte pad:%d\n", (unsigned int)sizeof(four_byte::CTest));
	printf("sizeof:CTest 1 byte pad:%d\n", (unsigned int)sizeof(one_byte::CTest));
	printf("sizeof static_test : %d\n", (unsigned int)sizeof(static_test));
	return 0;
}

