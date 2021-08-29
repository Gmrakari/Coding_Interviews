#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Date:2021-03-10 09:48
 * Author:Gmrakari
 * Filename:13.cpp
 */

template <class T>
struct display {
	void operator() (const T& x) const {
		cout << x << ' ';
	}
};

int partition(vector<int>& vec, int low, int high) {
	int pv = vec[low];
	
	while (low < high) {
		while (low < high && pv <= vec[high]) {
			high--;
		}
		swap(vec[low], vec[high]);
		while (low < high && pv >= vec[low]) {
			low++;
		}
		swap(vec[low], vec[high]);
	}
	return low;
}


void QSort(vector<int>& vec, int low, int high) {
	int partition(vector<int>& vec, int low, int high);

	if (low < high) {
		int pv = partition(vec, low, high);
		QSort(vec, low, pv - 1);
		QSort(vec, pv + 1, high);
	}
}


void QuickSort(vector<int>& vec, int len) {
	void QSort(vector<int>& vec, int low, int high);
	QSort(vec, 0, len - 1);
}

void test() {
	void QuickSort(vector<int>& vec, int len);
	int array[] = {1,3,5,7,9,2,4,6,8,0,12};
	
	vector<int> vec(array, array + sizeof(array)/sizeof(int));

	int len = vec.size();

	cout << "before:";
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;
	
	cout << "QuickSort:";
	void QuickSort(vector<int>& vec, int len);
	QuickSort(vec, len);
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;

}

int main(int argc,const char* argv[])
{
	void test();
	test();
}
