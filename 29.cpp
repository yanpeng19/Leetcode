// 29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <stdio.h>
#include <Bits.h>

using namespace std;

int divide(int dividend, int divisor) 
{
	if (dividend == 0) return 0;

	if (divisor == 1) return dividend;
	if (divisor == -1 && dividend == -2147483647) return 2147483647;
	if (divisor == -1) return ~dividend + 1;

	int a = dividend;
	int b = divisor;
	int f = 0;
	int r = 1;

	if (a > 0)
	{
		a = ~(a - 1);
		f++;
	}

	if (b > 0)
	{
		b = ~(b - 1);
		f++;
	}

	if (a > b) return 0;
	if (a == b) return 1;

	

	while (a < b)
	{
		if ((a-b)>b) break;
		b = b + b;
		r = r + r;

		if (b == a) return f == 1 ? -r : r;
	}

	if (a == b&&f==0) return r;

	int m = 0; //差值
	
	// m = 除数 - r*b;
	// m = (r+r)*b - 除数

	int size = divisor < 0 ? (~divisor) + 1 : divisor;

	m = dividend > 0 ?  ~dividend + 1 - b : dividend - b;
	if (m > 0) m = ~(m - 1);

	if (m < -10 && m < -size)
	{
		int t = divide(m, -size);
		r = r + t;
	}
	else
	{
		while (m < -size)
		{
			m = m + size;
			r++;
		}
	}

	if (f == 1) return ~(r-1);
	return r;
};

int main()
{
	cout << divide(2147483647,3);
	return 0;
}
