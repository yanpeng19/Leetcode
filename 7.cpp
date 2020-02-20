// 7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int get_num(const int i)
{
	stringstream ss;

	ss << i;

	string s(ss.str());
	ss.str("");

	if (i < 0)
	{
		ss << '-';
		for (int i = s.size() - 1; i > 0; i--)
			ss << s[i];
	}
	else
	{
		for (int i = s.size() - 1; i >= 0; i--)
			ss << s[i];
	}

 	s = ss.str();
	while (s[0] == '0') s.erase(0,1);
	while (s[0] == '-' && s[1] == '0') s.erase(1,1);

	double re = 0;
	double n = 1;
	

	if (i < 0)
	{
		for (int i = s.size() - 1; i > 0; i--)
		{
			re += (s[i] - 48) * n;
			n = n * 10;
		}
		re = 0 - re;
		if (re > 0) return 0;
	}
	else
	{
		for (int i = s.size() - 1; i >= 0; i--)
		{
			re += (s[i] - 48) * n;
			n = n * 10;
		}
		if (re < 0) return 0;
	}


	if (re > 2147483647 || re < -2147483648) return 0;

	return re;
}

int main()
{

	cout << get_num(-2147483412);

 	system("pause");
	return 0;
}
