// 67.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) 
{
	int f = 0;
	string r;

	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 && j >= 0)
	{
		int n = a[i] + b[j] -96+f;
		f = 0;
		if (n == 0) r = '0' + r;
		else if (n == 1) r = '1' + r;
		else if (n == 2)
		{
			r = '0' + r;
			f = 1;
		}
		else
		{
			r = '1' + r;
			f = 1;
		}
		i--;
		j--;
	}

	while (i >= 0)
	{
		int n = a[i] - 48 + f;
		f = 0;
		if (n == 0) r = '0' + r;
		else if (n == 1) r = '1' + r;
		else if (n == 2)
		{
			r = '0' + r;
			f = 1;
		}
		else
		{
			r = '1' + r;
			f = 1;
		}
		i--;
	}

	while (j >= 0)
	{
		int n = b[j] - 48 + f;
		f = 0;
		if (n == 0) r = '0' + r;
		else if (n == 1) r = '1' + r;
		else if (n == 2)
		{
			r = '0' + r;
			f = 1;
		}
		else
		{
			r = '1' + r;
			f = 1;
		}
		j--;
	}
	if (f)
		r = '1' + r;
	return r;
}

int main()
{
	string s1("1011");
	string s2("1010");
	//     10101
	cout << addBinary(s1, s2) << endl;
	system("pause");
}
