// 69.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int mySqrt(int x) 
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (x < 9) return 2;

	int r= 46340;
	int l = 0;

	while (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (x == mid* mid)
			return mid;
		if (x < mid * mid)
			r = mid - 1;
		if (x > mid* mid)
			l = mid + 1;
	}
	return r;
}

int main()
{
	cout << mySqrt(8);
	system("Pause");
}


