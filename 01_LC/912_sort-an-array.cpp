

/*
 * Date:2021-06-20 08:21
 * filename:912_sort-an-array.cpp
 *
 */

#include <bits/stdc++.h>
#include <cstdlib>// Header file needed to use rand

using namespace std;

class Solution {
public:
	int partition(vector<int>& nums, int low, int high) {
		int pv = nums[low];
		while ( low < high ){
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
	void quicksort(vector<int>&nums, int low, int high) {
		if (low < high) {
			int pv = partition(nums,low,high);
			quicksort(nums, low, pv - 1);
			quicksort(nums, pv + 1, high);
		}
	}
  vector<int> sortArray(vector<int>& nums) {
		int low = 0;
		int high = nums.size() - 1;
		quicksort(nums, low, high);
		return nums;
  }

	void print(vector<int>& nums) {
		for(int i = 0; i < (int)nums.size();i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
};

class Solution_2 {
	int partition(vector<int>& nums, int low, int high) {
		int pv = nums[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; ++j) {
			if (nums[j] <= pv) {
				i = i + 1;
				swap(nums[i],nums[j]);
			}
		}
		swap(nums[i + 1], nums[high]);
		return i + 1;
	}
	int randomized_partition(vector<int>& nums,int low, int high) {
		int i = rand() % (high - low + 1) + low;
		swap(nums[high],nums[i]);
		return partition(nums, low, high);
	}

	void randomized_quicksort(vector<int>& nums, int low, int high) {
		if(low < high) {
			int pos = randomized_partition(nums, low, high);
			randomized_quicksort(nums, low, pos - 1);
			randomized_quicksort(nums, pos + 1, high);
		}
	}

public:
	vector<int> sortArray(vector<int>& nums) {
		srand((unsigned)time(NULL));
		randomized_quicksort(nums, 0, (int)nums.size() - 1);
		return nums;
	}

	void print(vector<int>& nums) {
		for(int i = 0; i < (int)nums.size();i++) {
			cout << nums[i] << " ";
		}
		cout << endl;
	}
};


int main() {
	Solution su;
	vector<int> vec = {1,4,2,5,6};
	cout << "test:";
	su.print(vec);
	cout << endl;

	cout << "quicksort:";
	vec = su.sortArray(vec);
	su.print(vec);
	cout << endl;
	return 0;
}
