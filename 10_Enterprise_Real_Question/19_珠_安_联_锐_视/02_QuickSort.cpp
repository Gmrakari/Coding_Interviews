

/*
 * Date:2021-09-28 20:28
 * filename:02_QuickSort.cpp
 *
 */

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
	int pv = nums[low];
	while (low < high) {
		while (low < high && nums[high] >= pv) {
			high--;
		}
		swap(nums[low], nums[high]);

		while (low < high && nums[low] <= pv) {
			low++;
		}
		swap(nums[low], nums[high]);
	}
	return low;	
}

void QuickSort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int pv = partition(nums, low, high);
		QuickSort(nums, low, pv - 1);
		QuickSort(nums, pv + 1, high);
	}
}

void QS(vector<int>& nums, int len) {
	QuickSort(nums, 0, len - 1);
}

void print(vector<int> nums) {
	cout << "print vector:";
	for (int i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {

	vector<int> vec = {1,1124,6,6,3,77,8224,3732,14};
	cout << vec.size() << endl;
	print(vec);

	QS(vec, vec.size());
	print(vec);

}
