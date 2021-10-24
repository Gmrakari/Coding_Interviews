

/*
 * Date:2021-10-24 12:05
 * filename:17_6_sizeof_struct_sizeof_union.c
 *
 */

#include <stdio.h>
#include <string.h>

struct stru {
	char c;
	int a;
};

union uni {
	char c;
	int a;
};

void func(struct stru arr[2]) {
	const char *str = "hello";
	char str2[] = "he";
	struct stru st = {0};
	union uni un = {0};

	printf("sizeof(arr):%ld",sizeof(arr));
	printf("sizeof(str):%d", sizeof(str));
	printf("sizeof(str2):%d", sizeof(str2));
	printf("sizeof(\"hello\"):%ld",sizeof("hello"));
	printf("sizeof(st):%d", sizeof(st));
	printf("sizeof(un):%d", sizeof(un));
}

int main() {

}
