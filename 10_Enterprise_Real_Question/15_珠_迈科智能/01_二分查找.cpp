

/*
 * Date:2021-09-14 20:55
 * filename:01_二分查找.cpp
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &vec, int key) {
	int low = vec.front();
	int high = vec.back();

	int flag = 0;
	while(low < high) {
		if ( flag != 1 ) {
			int mid = (high + low) / 2;
			if (mid == key) {
				flag = 1;
				cout << "find key :" << key << endl;;
				return mid;
			}
			else if (mid > key) {
				flag = 0;
				high = mid - 1;
			}
			else if (mid < key) {
				flag = 0;
				low = mid + 1;
			}
		}

	}
	return -1;
}

int binary_search_2(vector<int>& vec, int key) {
	int left = vec.front(); 
	int right = vec.back();
	cout << "left: " << left << " right:" << right << endl;

	int flag = 0;
	while (left < right) {
		if (flag != 1) {
			int mid = (left + right) / 2;
			if (key == mid) {
				flag = 1;
				return mid;
			}
			else if (mid > key) {
				flag = 0;
				right = mid - 1;
			}
			else if (mid < key) {
				flag = 0;
				left = mid + 1;
			}
		}
	}
	return -1;
}


int main() {
	vector<int> vec;
	for (int i = 0; i < 10; ++i) {
		vec.emplace_back(i);
	}

	for (auto j : vec) {
		cout << j << ' ';
	}
	cout << endl;

	cout << binary_search(vec, 2) << endl;
	cout << binary_search_2(vec, 5) << endl;
}
