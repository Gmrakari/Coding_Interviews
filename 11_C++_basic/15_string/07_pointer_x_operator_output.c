

/*
 * Date:2022-01-04 16:56
 * filename:07_pointer_x_operator_output.c
 *
 */

#include <stdio.h>
#include <string.h>
int main(void) {
	int n;
	char y[10] = "ntse";
	char *x = y;
	n = strlen(x);
	*x = x[n];
	x++;
	printf("x = %s,", x);
	printf("y = %s\n", y);
	return 0;
}
