/**
 * 
 * @filename:sizeof_structA_B.c
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/6/2 11:06
 * 
 */

#include "../include/langCHeader.h"

void test1() {
    struct A {
        char a;      //1
        long b;      //4
        char c;      //1
        double d;    //8
    };
    printf("sizeof(A):%d\n", sizeof(struct A));
}

void test2() {
    struct B {
        char a;      //1
        char b;      //1
        long c;      //4
        double d;    //8
    };

    printf("sizeof(B):%d\n", sizeof(struct B));

}


int main() {
    test1();   // a + b + c = 12, +double的话按8的倍数最小取整，就是24
    test2();   // a + b + c = 8, +double的话按8的倍数最小取整，就是16
}
