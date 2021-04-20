
#include <iostream>
using namespace std;

class SealedClass
{
	public:
		static SealedClass* GetInstance()
		{
			cout << "SealedClass* GetInstance()..." << endl;
			return new SealedClass();
		}
	private:
		SealedClass() {  }
		~SealedClass() {  };
};

class Base : public SealedClass
{

};

int main()
{
	SealedClass *pb = Base::GetInstance();
	Base base;

	return 0;
}
