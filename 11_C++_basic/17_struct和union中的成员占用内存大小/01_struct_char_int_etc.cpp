

/*
 * Date:2021-11-12 08:26
 * filename:01_struct_char_int_etc.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct IntTest {
	int IntValue;
};

void test1() {
	cout << "sizeof(IntTest):int:"; //4
	cout << sizeof(IntTest) << endl;
}

struct CharTest {
	char CharValue;
};

void test2() {
	cout << "sizeof(CharTest):char:"; //1
	cout << sizeof(CharTest) << endl;
}

struct DoubleTest {
	double DoubleValue; //8
};

void test3() {
	cout << "sizeof(DoubleTest):double:";
	cout << sizeof(DoubleTest) << endl;
}

struct PointerTest {
	int* PointerValue; //4
											//错 是8个，因为int占用4个，指针占用4个 一共有8个
};

void test4() {
	cout << "sizeof(PointerTest):pointer:";
	cout << sizeof(PointerTest) << endl;
}

struct N_Class_Test { //1

};

void test5() {
	cout << "sizeof(N_Class_Test):null member class:";
	cout << sizeof(N_Class_Test) << endl;
}

struct normal_data {
	int IntValue;			//4
	char CharValue;   //1
	double D_Value;   //8
	int* p;           //4
										
										/*
										 * 因为int 4,int* 为8,double 也为8 为了对齐 int填充4个，char填充7个 4*8 = 32t
										 */
};

void test6() {
	cout << "sizeof(normal_data):int char double pointer:";
	cout << sizeof(normal_data) << endl;

	cout << "sizeof(intvalue):" << sizeof(normal_data) / sizeof(int) << endl;
	cout << "sizeof(charValue):" << sizeof(normal_data) / sizeof(char) << endl;
}

struct A {
	int a;	 //4
	char b;  //1 -->4
	double c;//8
	char d; //1 --4
	int e;	//4
};

void test7() {
	cout << "sizeof(A) int char double char int:" << sizeof(A) << endl;// 24 4+4 + 8 + 4 + 4
}

struct B {
	double a;
	char b;
	int c;
	char str[10];
	int* p;
	int array[3];
}B_data;

void test8() {
	cout << "--------------------------" << endl;
	cout << "sizeof(double,char,int,char array,pointer,int array):" << sizeof(B) << endl;

	printf("double a address :%p\n",&B_data.a);
	printf("char b address :%p\n",&B_data.b);
	printf("int c address :%p\n",&B_data.c);
	printf("char str array address :%p\n",&B_data.str);
	printf("int pointer address :%p\n",&B_data.p);
	printf("int array address:%p\n",&B_data.array);
	//printf("%p",&B_data.a);
	cout << "--------------------------" << endl;
}

struct C {
	double a;
	char b;
	int c;
	char str[9];
	int* p;
	int array[3];
};

void test9() {
	cout << "sizeof(double,char,int,char array,pointer,int array):" << sizeof(C) << endl;
}

struct D {
	int a;
	int* p;
	char c;
	double d;
	int e;
	char f[20];
	int g;
	
	struct D *t;
};

void test10() {
	cout << "sizeof(int int* char doule int char int):" << sizeof(D) << endl;
}

struct E {
	int b;	     //4
	struct temp {
		int a;	  //4
		char b;   //1 -- 4
		double c; //8
	}temp;			//4 + 4 + 8 = 16
};	          //16 + 4 = 20 + 4 => 24

void test11() {
	cout << "struct of struct sizeof:" << sizeof(E) << endl;
}


struct bool_type {
	bool d;
};

void test12() {
	cout << "bool_type:" << sizeof(bool_type) << endl;
}

struct float_type {
	float f_type;
};

void test13() {
	cout << "float_type:" << sizeof(float_type) << endl;
}


int main() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
}
