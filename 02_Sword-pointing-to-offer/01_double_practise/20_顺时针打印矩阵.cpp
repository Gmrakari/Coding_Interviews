

/*
 * Date:2021-07-22 11:19
 * filename:20_顺时针打印矩阵.cpp
 *
 */

/*
#题意

题目描述

题目描述

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字.

例如， 如果输入如下矩阵：

1 	2 	3 	4
5 	6 	7 	8
9  10  11  12
13 14  15  16

则依次打印出数字

1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10

*/

#include <iostream>
using namespace std;


//思路
//把矩阵想象成若干个圈
//用一个循环来打印矩阵，每一次打印矩阵的圈
//矩阵行-rows,列-colums
//循环终止条件,columns > startX * 2 && rows > startY * 2
void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
	void PrintMatrixInCircle(int** numbers, int columns, int rows, int start);
	if (numbers == NULL || columns <= 0 || rows <= 0) 
		return ;

	int start = 0;

	while (columns > start * 2 && rows > start * 2) {
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
	}
}

//打印一圈分为4步
//第一步 从左到右打印一行
//第二步 从上到下打印一列
//第三步 从右到左打印一行
//第四步 从下到上打印一行或者一列

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
	void printNumber(int number);
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	//从左到右打印一行
	for (int i = start; i <= endX; ++i) {
		int number = numbers[start][i];
		printNumber(number);
	}

	//从上到下打印一列
	if (start < endY) {
		for (int i = start + 1; i <= endY; ++i) {
			int number = numbers[i][endX];
			printNumber(number);
		}
	}

	//从右到左打印一行
	if (start < endX && start < endY) {
		for (int i = endX - 1; i >= start; --i) {
			int number = numbers[endY][i];
			printNumber(number);
		}
	}

	//从下到上打印一列
	if (start < endX && start < endY - 1) {
		for (int i = endY - 1; i >= start + 1; --i) {
			int number = numbers[i][start];
			printNumber(number);
		}
	}
}

void printNumber(int number)
{
	printf("%d ", number);
}

void test(int columns, int rows) {
	printf("test begin:%d columns,%d rows.\n", columns, rows);

	if (columns < 1 || rows < 1) return ;

	int **numbers = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		numbers[i] = new int [columns];
		for (int j = 0; j < columns; ++j) {
			numbers[i][j] = i * columns + j + 1;
		}
	}

	PrintMatrixClockwisely(numbers, columns, rows);
	printf("\n");

	for (int i = 0; i < rows;++i) {
		delete[] (int*)numbers[i];
	}
	delete[] numbers;
}

int main() {
	test(4, 4);
}
