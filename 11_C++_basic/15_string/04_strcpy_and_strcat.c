

/*
 * Date:2021-12-28 09:31
 * filename:04_strcpy_and_strcat.c
 *
 */

#include <stdio.h>
#include <string.h>

int main() {
	char p1[10] = "abcd", *p2, str[10] = "xyz";
	p2 = "ABCD";

	//strcat(p1 + 2, p2 + 1) 将p2 + 1 连接到 p1 + 2,即是cdBCD
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));

	//strcpy(str + 2, change_str) 将change_str拷贝字符串到str + 2上
	printf("%s\n", str);
}
