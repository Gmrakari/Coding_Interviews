#include <iostream>
#include <vector>
using namespace std;

int GetNumberOfK(vector<int> data,int k)
{
	int low = 0,high = data.size() - 1;
	if(high == -1) return 0;

	while( low <= high )
	{
		int mid = low + (high - low) / 2;
		if(data[mid] > k) high = mid - 1;
		else if(data[mid] < k) low = mid + 1;
		else
		{
			int count = 0;
			count++;
			int index = mid - 1;
			while(index >= 0 && data[index] == k)
			{
				count++;
				index--;
			}
			index = mid + 1;
			while(index <= data.size() - 1 && data[index] == k)
			{
				count++;
				index++;
			}
			return count;
		}
	}
	return 0;
}


int main(int argc,const char* argv[])
{
	
	int GetNumberOfK(vector<int> data,int k);
	int array[] = {1,2,3,3,3,3,3,4,5};
	vector<int> v(array,array + 9);
	int ret = 0;
	ret = GetNumberOfK(v,3);
	cout << ret << endl;
	
}


