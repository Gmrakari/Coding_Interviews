

/*
 * Date:2022-03-02 18:46
 * filename:03_permutation_排列.c
 *
 */


#include <stdio.h>


void m_swap(char *p1, char *p2) {
	char temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void permutation(char *pStr, char *pBegin) {
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
	}
	else {
		for (char *pch = pBegin; *pch != '\0'; ++pch) {
			m_swap(pch, pBegin);
			permutation(pStr, pBegin + 1);
			m_swap(pch, pBegin);
		}
	}
}

void fun(char *ptr) {
	if (ptr == NULL)
		return ;
	permutation(ptr, ptr);
}

int main() {
	char str[] = "abc";
	fun(str);

}
