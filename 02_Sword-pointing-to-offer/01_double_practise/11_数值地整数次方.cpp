

/*
 * Date:2021-07-17 11:41
 * filename:11_数值地整数次方.cpp
 *
 */

/*

#题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

*/

double Power_1(double base, int exponent) {
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i) {
		result *= base;
	}
	return result;
}

bool g_InvalidInput = false;
double Power(double base, int exponent) {
	bool equal(double num1, double num2);
	double PowerWithUnsignedExponent(double base, unsigned int exponent);
	g_InvalidInput = false;
	if (equal(base, 0.0) && exponent < 0) {
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
	double result = 1.0;
	for (int i = 1; i <= (int)exponent; ++i) {
		result *= base;
	}
	return result;
}

bool equal(double num1, double num2) {
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}

/*
 * 在上述代码中我们采用全局变量来标识是否出错。
 * 如果出错了，则返回的值是0.但为了区分是出错的时候返回的0,还是底数为0的时候正常运行返回的0
 * 我们还定义了一个全局变量g_InvalidInput。当出错时，这个变量被设为true,否则为false。
 * 这样的好处是，我们可以吧返回值直接传递给其他变量，比如写double result = Power(2, 3),也可以把函数的
 * 返回值直接传递给其他需要double型参数的函数.但缺点是这个函数的调用者有可能会忘记去检查g_InvalidInput
 * 以判断是否出错，留下了安全隐患。
 *
 * 注意:在判断底数base是否不是等于0时，不能直接写base ==0,这是因为在计算机内表示小数时(包括float和double型小数)
 * 都有误差。
 * 判断两个小数是否相等，只能判断它们之差的绝对值是不是在一个很小的范围内。
 * 如果两个数相差很小，就可以认为他们相等，这就是equal函数存在的原因
 *
 */

/* 递归 全面高效解法 */
double PowerWithUnsignedExponent_2(double base, unsigned int exponent) {
	if (exponent == 0) 
		return 1;
	if (exponent == 1) 
		return base;

	double result = PowerWithUnsignedExponent_2(base, exponent >> 1);
	result *= result;
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}
