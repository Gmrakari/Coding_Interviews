

/*
 * Date:2021-10-26 10:26
 * filename:16_指针引用数组的应用.c
 *
 */

#include <stdio.h>

int main() {
	int a[] = {1, 2, 3, 4, 5};
	int* ptr = (int*)(&a + 1);
	printf("*(a + 1) : %d,*(ptr - 1): %d\n",*(a + 1), *(ptr - 1));
	return 0;
}
