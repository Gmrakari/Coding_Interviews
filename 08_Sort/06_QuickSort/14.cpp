#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Date:2021-10-09 09:43
 * Author:Gmrakari
 * Filename:14.cpp
 */

template <class T>
struct display {
	void operator() (const T& x) const {
		cout << x << ' ';
	}
};

int partition(vector<int>& vec, int low, int high) {
	int pv = vec[high];
	while (low < high) {
		while (low < high && pv <= vec[high]) {
			high--;
		}
		swap(vec[low],vec[high]);
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
		int pivot = partition(vec, low, high); 
		QSort(vec, 0, pivot - 1);
		QSort(vec, pivot + 1, high);
	}
	for_each(vec.begin(), vec.end(), display<int>());
	cout << endl;
}


void QuickSort(vector<int>& vec, int len) {
	void QSort(vector<int>& vec, int low, int high);
	QSort(vec, 0, len - 1);
}

void test() {
	void QuickSort(vector<int>& vec, int len);
	int array[] = {26, 84, 18, 36, 60, 72, 48};
	
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
