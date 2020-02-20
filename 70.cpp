// 70.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int climbStairs(int n) 
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;

	int i = 2;
	int num = 2;
	int temp = 1;
	while (i < n)
	{
		int t = num;
		num += temp;
		temp = t;
		i++;
	}
	return num;
}
int main()
{
	cout << climbStairs(7);
	system("pause");
}
