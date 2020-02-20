// 13.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fuc(string s)
{
	vector<int> nums(256, 0);
	nums['I'] = 1;
	nums['V'] = 5;
	nums['X'] = 10;
	nums['L'] = 50;
	nums['C'] = 100;
	nums['D'] = 500;
	nums['M'] = 1000;

	int n = 0;
	for (int i = s.size()- 1; i >= 0; i--)
	{
		int temp = nums[s[i]];

		if (i > 0)
		{
			if (s[i] == 'V' && s[i - 1] == 'I')
			{
				temp = 4;
				i--;
			}
			else if (s[i] == 'X' && s[i - 1] == 'I')
			{
				temp = 9;
				i--;
			}
			else if (s[i] == 'L' && s[i - 1] == 'X')
			{
				temp = 40;
				i--;
			}
			else if (s[i] == 'C' && s[i - 1] == 'X')
			{
				temp = 90;
				i--;
			}
			else if (s[i] == 'D' && s[i - 1] == 'C')
			{
				temp = 400;
				i--;
			}
			else if (s[i] == 'M' && s[i - 1] == 'C')
			{
				temp = 900;
				i--;
			}
		}
		n += temp;
	}
	return n;
}


int main()
{
	cout << fuc("LVIII");
}

