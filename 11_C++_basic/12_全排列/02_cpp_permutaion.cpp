

/*
 * Date:2021-12-17 16:02
 * filename:02_cpp_permutaion.cpp
 *
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int p = *a;
	*a = *b;
	*b = p;
}

void perm(int list[], int k, int m)
{
	if (k == m)
	{
		copy(list,list + m + 1,ostream_iterator<int>(cout," "));
		cout << endl;
		return;
	}
	for (int i = k; i <= m; i++)
	{
		swap(&list[k],&list[i]);
		perm(list, k + 1,m);
		swap(&list[k],&list[i]);
	}
}

int main() {
	int arr[] = {1,2,3}; 
	int m = sizeof(arr) / sizeof(arr[0]);
	perm(arr, 0, m - 1);
}
