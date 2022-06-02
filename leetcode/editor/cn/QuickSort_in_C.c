/**
 * 
 * @filename:QuickSort_in_C.c
 * @function:
 * @return:
 * @author:Zhanyou Zhou (gmrakari@outlook.com)
 * @date:2022/5/31 9:32
 * 
 */

#include "include/langCHeader.h"

void m_swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    void m_swap(int *a, int *b);
    int pv = arr[low];

    while (low < high) {
        while (low < high && pv < arr[high]) {
            high--;
        }
        m_swap(&arr[low], &arr[high]);
        while (low < high && pv > arr[low]) {
            low++;
        }
        m_swap(&arr[low], &arr[high]);
    }
    return low;
}

void qs(int arr[], int low, int high) {

    if (low < high) {
        int pv = partition(arr, low, high);
        qs(arr, 0, pv - 1);
        qs(arr, pv + 1, high);
    }
}

void quicksort(int arr[], int len) {
    qs(arr, 0, len - 1);
}


void test() {
    int arr[] = {1, 2, 23, 4, 7, 10, 0, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("before:");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, len);

    printf("after :");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    test();
}
