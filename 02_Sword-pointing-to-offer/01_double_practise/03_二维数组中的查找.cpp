
/*
 * Date:2021-07-16 10:29
 * filename:03_二维数组中的查找.cpp
 *
 */

/*
	题目描述
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
	每一列都按照从上到下递增的顺序排序。
	请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/*
 * 首先选取数组中右上角的数字。
 * 如果该数字等于要查找的数字，查找过程结束;
 * 如果该数字大于要查找的数字，剔除这个数字所在的列;
 * 如果该数字小于要查找的数字，提出这个数字所在的行。
 *
 * 也就是说，如果要查找的数字不在数组的右上角，则每一次都在数组的查找范围中剔除一行或者一列
 * 这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空
 */

bool Find(int *matrix, int rows, int columns, int number) {
	bool found = false;
	if (matrix != NULL && rows > 0 && columns > 0) {
		int row = 0;
		int column = columns - 1;
		while (row < rows && columns >= 0) {
			if (matrix[row * columns + column] == number) {
				found = true;
				break;
			}
			else if (matrix[row * columns + column] > number) {
				--column;
			}
			else
				++row;
		}
	}
	return found;
}
