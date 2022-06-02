/**
 * 
 * @filename:sizeof_struct_and_strlen_etc.c
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/30 10:06
 * 
 */

#include "../include/langCHeader.h"

struct A {
    int a;       //4   //4
    char b[5];  // 5  //5 --3
    short c;    //2   //2  填补到 上面
                     //total == 12
    char *p;   //4   //4
    double d;  //8   //8
}A;



struct B {
    int a;            //4
    int* p;           //4
    char c;           //1
    double d;         //8
    int e;            //4
    char f[20];       //1*20 = 20
    int g;            //4

                      // a(4) + p(4) + c(1) + d(8) + e(4) + f(1*20)  = 48,
                      // 48 + g(4) = 52 然后52按8的倍数取整，52 补 4 = 56
                      //total = 56
    struct B *t;
};

struct C {
    int b;	     //4
    struct temp {
        int a;	  //4
        char b;   //1 -- 4
        double c; //8
    }temp;			// 4 + 4 + 4 = 12, 12 + 8 = 20, 按最小倍数8取整就是20 +4 = 24
};

void testa() {
    printf("sizeof(struct A):%d\n", sizeof(A));
}

void testb() {
    printf("sizeof(struct B):%d\n",sizeof(struct B));
}

void testc() {
    printf("sizeof(struct C):%d\n",sizeof(struct C)); //16
}
struct intPoint {
    int* p;
};

void test() {
    printf("sizeof(intPoint):%d\n", sizeof(struct intPoint));  //24
}

void teststr_1() {
    char *str = "word";
    printf("teststr_1 strlen(str):%d\n", strlen(str)); //4
}

void teststr_2() {
    char *str = "wordand";
    printf("teststr_2 strlen(str):%d\n", strlen(str)); //7
}

void teststr_3() {
    char *str = "word\0and";
    printf("teststr_3 strlen(str):%d\n", strlen(str)); //4
}

void teststr_4() {
    char str[] = {'w', 'o', 'r', 'd', 'a', 'n', 'd'};//7
    printf("teststr_4 strlen(str):%d\n", strlen(str));
}

void teststr_5() {
    char str[] = {'w', 'o', 'r', 'd', '\0', 'a', 'n', 'd'};//4
    printf("teststr_5 strlen(str):%d\n", strlen(str));
}

int main() {
    test();
    testa();
    testb();
    testc();
    printf("---------------------\n");

    teststr_1();
    teststr_2();
    teststr_3();
    teststr_4();
    teststr_5();
}
