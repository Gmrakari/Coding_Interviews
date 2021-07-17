

/*
 * Date:2021-07-17 11:31
 * filename:09_斐波那契数列.cpp
 *
 */

/*

#题目 写一个函数，输入n，求斐波那契(Fibonacci)而数列的第n项。
斐波那契数列的定义如下

        	/        0       	n = 0
f(n) =     -         1			n = 1
        	\  f(n-1)+f(n+1)    n > 2

*/

long long Fibonacci_1(unsigned int n) {
	if (n <= 0) 
		return 0;

	if (n == 1)
		return 1;

	return Fibonacci_1(n - 1) + Fibonacci_1(n - 2);
}

long long Fibonacci(unsigned int n) {
	int result[2] = {0 , 1};
	if (n < 2) 
		return result[n];
	long long fibNMinusOne = 1;
	long long fibNMinusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; ++i) {
		fibN = fibNMinusOne + fibNMinusTwo;
		fibNMinusTwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}
	return fibN;
}

