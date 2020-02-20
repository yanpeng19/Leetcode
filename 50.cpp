// 50.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>

using namespace std;

double myPow(double x, int n) 
{
	if (n == 0) return 1;
	if (n == 1) return x;
	if (n == -1) return 1 / x;

	if (x == 1) return 1;
	if (x == -1)
	{
		if (n % 2) return -1;
		else return 1;
	}
	if (x == 0) return 0;

	// x^9 = x^4 * x^4  * x
	// x^-9 = x^-4 * x^4 * 1/x
	double r = 0;

	if (n > 0)
	{
		double temp = myPow(x, n / 2);
		if (n % 2) r = temp * temp * x;
		else r = temp * temp;
	}

	if (n < 0)
	{
		double temp = myPow(x, n / 2);
		if (n % 2)
			r = temp * temp * 1 / x;
		else r = temp * temp;
	}

	return r;
}
int main()
{
	cout << myPow(2, 13);
	system("pause");
	return 0;
}

