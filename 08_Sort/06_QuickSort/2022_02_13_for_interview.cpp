
/*
 * Date:2022-02-13 09:36
 * filename:prepare for interview.cpp
 *
 */

/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int partition(vector<int> &arr, int low, int high) {
	int pv = arr[low];
	if (low <= high) {
		while (low <= high && pv > arr[low]) {
			low++;
			swap(arr[low], arr[high]);
		}
		while (low <= high && pv < arr[high]) {
			high--;
			swap(arr[low], arr[high]);
		}
	}
	return low;
}

void qsort(vector<int> &arr, int low, int high) {
	while (low <= high) {
		int pivot = partition(arr, low, high);
		qsort(arr, low, pivot);
		qsort(arr, pivot + 1, high);
	}
}

void sort(vector<int> &arr) {
	qsort(arr, arr[0], arr.size() - 1);
}

void output(vector<int> &arr) {
	if (arr.size() < 0) 
		return ;

	for (int i = 0; i < (int)arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test() {
	vector<int> arr = {1,5,6,21,6,7,2,3};
	cout << "before:" ;
	output(arr);
	cout << "after: ";
	sort(arr);
	output(arr);
}

int main() {
	test();
}

*/

/*
 * err by first time
 */



#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int partition(vector<int> &arr, int low, int high) {
    int pv = arr[low];
    while (low < high) {
        while (low < high && pv <= arr[high]) {
            high--;
        }
        swap(arr[low], arr[high]);
        while (low < high && pv >= arr[low]) {
            low++;
        }
        swap(arr[low],arr[high]);
    }
    return low;
}

void qsort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        qsort(arr, low, pivot - 1);
        qsort(arr, pivot + 1, high);
    }
}

void sort(vector<int> &arr) {
    qsort(arr, 0, arr.size() - 1);
}

void output(vector<int> &arr) {
    if (arr.size() < 0)
        return ;

    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test() {
    vector<int> arr = {1,5,6,21,6,7,2,3};
    cout << "before:" ;
    output(arr);
    cout << "after: ";
    sort(arr);
    output(arr);
}

int main() {
    test();
}
