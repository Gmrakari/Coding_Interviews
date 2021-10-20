

/*
 * Date:2021-10-20 21:26
 * filename:05_test.c
 *
 */


#include <stdio.h>
int main()
{
	int a[]={1,2,4,7,3,5,2};
	int b = 1, result = 0;
	int c = 1, d = 2, e = 3;
	
	int len = sizeof(a) / sizeof(a[0]);
	printf("a:");
	for (int i = 0; i < len; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
	for( int i = 6; i>=0; i--){
		result += b * a[i];
		b *= 10;
	}
	printf("%d\n", result);
	
	printf("test c = 1 + 2 * 3 = 7 : c += d * e --> %d\n", c += d * e );
}
