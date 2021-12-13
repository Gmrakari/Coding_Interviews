

/*
 * Date:2021-12-13 10:01
 * filename:01_Base_and_Derived_output.cpp
 *
 */

#include <iostream>
using namespace std;

class Base
{
    public:
    void virtual Func()
    {
        cout<<"Base"<<endl;
    }
};

class Derived : public Base
{
    public:
    void virtual Func()
    {
        cout<<"Derived "<<endl;
    }
};

int main ()
{
    Base* pBase = new Base();
    pBase ->Func();
    Derived * pDerived = (Derived*)pBase;
    pDerived->Func();
    delete pBase;

    pDerived  =  new Derived();
    pBase = pDerived;
    pBase->Func();

    delete pDerived;
    return 0;
}
