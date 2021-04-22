#include <iostream>
using namespace std;

class SealedClass
{
public:
		static SealedCLass* GetInstance()
		{
			if(m_sc == NULL)
			{
				m_sc = new SealedClass();
			}

			return m_sc;
		}

		static void Destroy()
		{
			if( m_sc != NULL )
			{
				delete m_sc;
			}
		}
private:
		SealedClass() {  }
		~SealedClass() {  }

		static SealedClass *m_sc;
};

SealedClass* SealedClass::m_sc = NULL;

class Base : public SealedClass
{

};




int main(int argc,const char* argv[])
{
	SealedClass *pb = SealedClass::GetInstance();
	SealedClass::Destroy();

	pb = NULL;
	return 0;
}
