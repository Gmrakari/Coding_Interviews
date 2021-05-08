#include <iostream>
using namespace std;

int add(int num1,int num2)
{
	int sum,carry;
	do
	{
		sum = (num1 ^ num2);
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	}
	while(num2 != 0);
	
	return num1;
}

int main(int argc,const char* argv[])
{
	int add(int num1,int num2);

	int ret = add(5,7);
	
	cout << ret << "\n";
}