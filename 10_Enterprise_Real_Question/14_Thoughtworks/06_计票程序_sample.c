

/*
 * Date:2021-11-11 10:21
 * filename:06_计票程序_sample.c
 *
 */
#include <stdio.h>
#include <string.h>

struct person {
	char name[20];
	int count;
}leader[3] = {{"Li", 0}, {"Zhang", 0}, {"Fun", 0}};

//input 第一行有一个整数n,表示以下有n张选票信息将会输入
//以后的n行，每一行包含一个人名，为选票的得票人，保证每个人都是Li,Zhang,Fun中的一个
//
//output
//有三行
//Li得票人数
//Zhang得票人数
//Fun得票人数

void getcount() {
	int n;
	scanf("%d", &n);
	char str[20];
	int othercnt = 0;
	while (n--) {
		fgets(str,20,stdin);
		for (int i = 0; i < 3;i++) {
			if (strcmp(str,leader[i].name) == 0) {
				leader[i].count++;
			}
			else {
				++othercnt;
			}
		}
	}
	for (int i = 0;i < 3;i++) {
		printf("%s:%d\n",leader[i].name,leader[i].count);
	}
	printf("other:%d",othercnt);
}

void getcount_1() {
	int n;
	scanf("%d",&n);
	char str[20];
	int othercnt = 0;
	int total = n;
	int varicnt = 0;
	while (n--) {
		//fgets(str, 20, stdin);
		scanf("%s",str);
		for (int i = 0;i < 3;i++) {
			if (strcmp(str, leader[i].name) == 0) {
				leader[i].count++;
				varicnt++;
			}
		}
	}
	for (int i = 0;i < 3;i++) {
		printf("%s:%d\n",leader[i].name,leader[i].count);
	}
	othercnt = total - varicnt;
	printf("other:%d",othercnt);

}

void test() {
	char str[20];
	scanf("%s",str);
	//fgets(str, 20, stdin);
	puts(str);
	char cmpstr[] = "Li";
	if (strcmp(str, cmpstr) == 0) {
		printf("yes\n");
	}
	else {
		printf("No\n");
	}
}

int main() {
	getcount_1();
	//test();
	return 0;
}
