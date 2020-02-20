// 8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int get_num(string str)
{

	string s = str;

	//去除空格
	while (!s.empty() && s[0] == ' ')
		s.erase(s.begin());

	if (s.empty()) return 0;

	char c = '+';
	if (s[0] == '-')
	{
		c = '-';
		s.erase(s.begin());
	}
	else if (s[0] == '+')
		s.erase(s.begin());

	//s[0] 不合法就 return 0;
	string num("0123456789");
	if (num.find_first_of(s[0]) == -1)
		return 0;

	

	// 去除之后的非发数字；
	int p = s.find_first_not_of(num);
	while (p != -1)
	{
		s.erase(s.begin() + p, s.end());
		p = s.find_first_not_of(num);

	}

	int x = 0;
	if (s.find_first_of(num) != 0 && s.find_first_of(num)!=1) return 0;

	x = s.find_first_not_of(num);
	while (x != -1)
	{
		s.erase(s.begin() + x);
		x = s.find_first_not_of(num);
	}

	stringstream ss;
	ss << s;
	

	double re = 0;
	double  n = 1;
	long min = -2147483648;

	for (int i = s.size()-1; i >= 0; i--)
	{
		re += (s[i] - 48) * n;
		n = n * 10;
	}

	if (c == '-')
	{ 
		 re = 0 - re;
	}
		
	if (re > 2147483647) 
		return 2147483647;
	if ( re < min) 
		return min;

	return re;
}

int main()
{
	cout << get_num("-+1");
	system("pause");
	return 0;
}
