// 20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s) 
{
	
	vector<char> v;
	for (auto a : s)
	{
		if (a == '(' || a == '{' || a == '[')
			v.push_back(a);
		else
		{
			if (v.empty()) return false;
			char c = v.back();
			v.pop_back();
			if (c == '(' && a != ')') return false;
			if (c == '[' && a != ']') return false;
			if (c == '{' && a != '}') return false;
		}
	}
	if (!v.empty()) return false;
	return true;
}


int main()
{
	string s("]");
	cout << isValid(s);
}
