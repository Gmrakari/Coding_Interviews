

/*
 * Date:2021-08-11 18:08
 * filename:51_数组中重复的数字.cpp
 *
 */

#include <iostream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	if (numbers == NULL || length <= 0) {
		return false;
	}

	for (int i = 0; i < length; ++i) {
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	for (int i = 0; i < length; ++i) {
		while (numbers[i] != i) {
			if (numbers[i] == numbers[numbers[i]]) {
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}

int main() {
	bool duplicate(int numbers[], int length, int* duplication);
}
