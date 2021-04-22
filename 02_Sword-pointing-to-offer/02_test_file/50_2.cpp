#include <iostream>
#include <vector>
using namespace std;

bool duplicate(int numbers[],int length,int* duplication)
{
	vector<bool> result(length,false);
	for(int i = 0;i < length;i++)
	{
		if(result[numbers[i]] == false)
		{
			result[numbers[i]] = true;
		}
		else
		{
			duplication[0] = numbers[i];
			return true;
		}
	}
	return false;
}

int main(int argc,const char* argv[])
{
	int numbers[] = {2,3,1,0,2,5,3};
	int length = sizeof(numbers) / sizeof(*numbers);
	int num1 = 1;
	int num2 = 2;
	
	bool ret = duplicate(numbers,length,&num1);
	cout << "ret : " << ret <<  endl;

	ret = duplicate(numbers,length,&num2);
	cout << "ret : " << ret <<  endl;


}
