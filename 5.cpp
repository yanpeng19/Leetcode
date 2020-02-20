// 5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

string get(const string & s)
{
	if (s.empty()) return string();

	// 回文子串的格式    cabac  或者 bb

	string resault;
	resault += s[0]; // 针对单独无重复字符情况
	
	int max = 0;

	for (int i = 0; i < s.size(); i++) //O(n^n)
	{
		int l = i - 1;
		int r = i + 1;
		int same_len = 1;

		l = i - 1;
		r = i;
		same_len = 0;
		while (l >= 0  && s[l] == s[r]) //模式1匹配   基本可以视为 0（n/2）    aba 模式
		{
			same_len += 2;
			if (same_len > max)
			{
				max = same_len;
				resault = string(s, l, same_len);
			}
			l--;
			r++;
		}

		l = i - 1;
		r = i + 1;
		same_len = 1;
		while (l >= 0 && r < s.size() && s[l] == s[r]) //模式2匹配  基本视为 O（n/2）   abba 模式
		{
			same_len += 2;
			if (same_len > max)
			{
				max = same_len;
				resault = string(s, l, same_len);
			}

			l--;
			r++;
		}

	}

	return resault;
}

int main()
{
	string s("babad");
	cout << get(s) << endl;
	system("pause");
	return 0;
}

