

/*
 * Date:2021-07-16 10:45
 * filename:04_替换空格.cpp
 *
 */

/*
 * 题目描述

	请实现一个函数，将一个字符串中的空格替换成“%20”。
	例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

	We Are Happy

	We%20Are%20Happy
	
 */

/* length 为字符数组string的总容量 */
void ReplaceBlank(char string[], int length) {
	if (string == NULL || length <= 0)
		return ;

	/* originalLength  为字符串string的实际长度 */
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0') {
		++ originalLength;
		if (string[i] == ' ') 
			++numberOfBlank;

		++i;
	}

	/*newLength 为把空格替换成'%20'之后的长度 */
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return ;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (string[indexOfOriginal] == ' ') {
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else {
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}


