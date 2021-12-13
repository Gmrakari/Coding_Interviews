

/*
 * Date:2021-12-13 10:03
 * filename:test.cpp
 *
 */

#include<iostream>
#include<string>

using namespace std;

class Pet
{
	string name;
	public:
		Pet(string p=" "){
			name=p;
		}
		string getName()const {
			return name;
		}
		virtual void call() const = 0;
};

class Dog: public Pet{
	public:
		Dog(string n):Pet(n){

		}
		void call()const {
			cout<<"##"<<" ";
		}
};

class Cat:public Pet{
	public:
		Cat(string n):Pet(n){}
		void call()const {
			cout<<"**";
		}
};

void f(Pet *p){
	p->call();
}

int main()
{
	Pet pet0("#");  //(1)
	Dog pet1("*");//(2)
	Cat pet2("$");//(3)
	f(&pet1);//(4)
	f(&pet2);//(5)
	return 0;
}
