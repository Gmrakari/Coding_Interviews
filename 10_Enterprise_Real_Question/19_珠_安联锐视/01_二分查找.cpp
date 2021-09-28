

/*
 * Date:2021-09-28 19:58
 * filename:01_二分查找.cpp
 *
 */

#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int binary_search(int arr[], int len, int key) {
	int left = 0;
	int right = len;
	while (left < right) {
		int mid = (right + left) / 2;

		if (arr[mid] == key) return mid;
		if (arr[mid] > key) 
			right = mid;
		else if (arr[mid] < key) 
			left = mid + 1;
	}
	return -1;
}

void test() {
	int arr[] = {1, 3, 5, 7, 9};

	int len = sizeof(arr) / sizeof (arr[0]);
	int key = 7;
	cout << "arr:";
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << endl;
	cout << "arr len:";
	cout << len << endl;
	cout << "find key:" << key << endl;

	cout << "find return index,not found return -1:";
	cout << binary_search(arr, len, key) << endl;
}

int main() {
	test();
}
