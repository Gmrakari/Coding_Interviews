

/*
 * Date:2021-09-14 21:20
 * filename:02_Quick_Sort.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;


int partition(vector<int>& vec, int low, int high) {
	int pv = vec[low];

	while (low < high) {
		while (low < high && vec[high] >= pv) {
			high--;
		}
		swap(vec[low],vec[high]);
		while (low < high && vec[low] <= pv) {
			low++;
		}
		swap(vec[low],vec[high]);
	}
	return low;
}

void QuickSort(vector<int>& vec, int low, int high) {
	if (low < high) {
		int pv = partition(vec, low, high);
		QuickSort(vec, low, pv - 1);
		QuickSort(vec, pv + 1, high);
	}
}

void QuickSort(vector<int>& vec) {
	QuickSort(vec, 0, vec.size() - 1);
}

vector<int> init() {
	vector<int> vec = {10,122,14,5,16,89,0,2,415};
	return vec;
}

int main() {
	vector<int> my_vec = init();
	QuickSort(my_vec);

	for (auto i : my_vec) {
		cout << i << ' ';
	}
	cout << endl;

}
