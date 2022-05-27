/**
 *
 * @filename:virtual_polymorphism_output.cpp
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/25 23:52
 *
 */

#include "../include/headers.h"

class A {
public:
    A() {}
    virtual void print() {
        cout << "This is A." << endl;
    }
};

class B : public A {
public:
    B() {}
    void print() {
        cout << "This is B." << endl;
    }
};

int main() {
    B b;
    {
        A a;
        a = b;
        a.print();
    }

    {
        A &a = b;
        a.print();
    }

    {
        A *a = new B();
        a->print();
    }
    return 0;
}