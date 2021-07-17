

/*
 * Date:2021-07-17 10:31
 * filename:08_旋转数组的最小数字.cpp
 *
 */

/*
#题目描述

#把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减序列的一个旋转，输出旋转数组的最小元素。

#例如

#数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，

#该数组的最小值为1。
*/

int Min(int* numbers, int length) {
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while(numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1]) 
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int Min_2(int* numbers, int length) {
	int MinInOrder(int* numbers, int index1, int index2);
	if (numbers == NULL || length <= 0) 
		throw new std::exception("Invalid parameters");

	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;

	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 = index2) / 2;

		//如果下标为index1,index2和indexMid指向的三个数字相等
		//则只能顺序查找
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
			return MinInOrder(numbers, index1, index2);

		if (numbers[indexMid] >= numbers[index1]) 
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2]) 
			index2 = indexMid;
	}
	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2) {
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i) {
		if (result > numbers[i]) 
			result = numbers[i];
	}
	return result;
}
