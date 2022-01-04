

/*
 * Date:2022-01-04 20:44
 * filename:28_define_variable.c
 *
 */

#include <stdio.h>

int main() {
	double a = 1.0, b = 1.0;
	int w = 1;
	long c = 1;

	//printf("%d\n", a = a + b = b++); //a + b error:lvalue required as left operand of assignment
	printf("w %% (int)(a + b) = %d\n", w % (int)(a + b));
	printf("(c + w) %% (int)a : %ld\n", (c + w) % (int)a);//
	printf("w = a == b:%d\n", w = a == b);
}
