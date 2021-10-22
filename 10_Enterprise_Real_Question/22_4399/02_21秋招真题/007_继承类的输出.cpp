

/*
 * Date:2021-10-22 16:13
 * filename:007_继承类的输出.cpp
 *
 */
#include <bits/stdc++.h>
using namespace std;

class A {
	public:
		void Func() { FuncImplement();}
	protected:
		virtual void FuncImplement() {
			cout << "A.Func" << endl;
		}
};

class B : public A {
	public:
		void Func() {
			FuncImplement();
		}
	protected:
		virtual void FuncImplement() override {
			cout << "B.Func" << endl;
		}
};

int main() {
	B b;
	A* a = &b;
	a->Func();
	b.Func();
	return 0;
}
