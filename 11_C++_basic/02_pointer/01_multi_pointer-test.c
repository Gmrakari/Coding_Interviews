

/*
 * Date:2021-12-28 13:07
 * filename:01_multi_pointer-test.c
 *
 */

#include <stdio.h>
#include <string.h>

int main() {
	char *c[] = {"HELLO", "NEW", "WORLD", "SAYHI"};
	char **cp[] = {c + 3, c + 2, c + 1, c};
	char ***cpp = cp;

	printf("%s,", **++cpp);
	printf("%s,", *--*++cpp + 3);
	printf("%s,", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}
