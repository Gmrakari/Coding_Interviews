

/*
 * Date:2021-10-24 14:19
 * filename:22_11_enum_的应用.c
 *
 */

#include <stdio.h>

enum bg_color {
	BG_RED,
	BG_BLACK,
	BG_BLUE
};

enum fg_color {
	FG_RED = 2,
	FG_BLACK,
	FG_YELLOW,
	FG_GREEN
};

int get(int type) {
	static int bc;
	static int fc = FG_BLACK;
	if (type == 0) 
		return ++bc;
	else
		return ++fc;
}

int main() {
	printf("get(0):%d\n",get(0));
	printf("get(1):%d\n",get(1));
	printf("get(0):%d\n",get(0));
}
