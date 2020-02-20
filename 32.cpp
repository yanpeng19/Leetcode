// 32.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestValidParentheses(string s) 
{
	if (s.empty()) return 0;
	int max=0;
	int l = 0;
	int r = 0;
	int n = 0;
	
	
	vector<char> vl;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] == ')')
		{
			vector<char> vr{ ')' };

			for (int j = i - 1; j >= 0; j--)
			{
				if (vr.empty()) break;

				if (s[j] == ')') vr.push_back(')');
				else if (!vr.empty())
					vr.pop_back();

			}
			if (!vr.empty())//找不到对应的左括号，非法又括号。
			{
				n = 0;
				vl = vector<char>();
				continue;
			}
			else vl.push_back(')');
		}
		else if (s[i] == '(' && !vl.empty())
		{
			vector<char> vr{ '(' };

			for (int j = i + 1; j < s.size(); j++)
			{
				if (vr.empty()) break;

				if (s[j] == '(') vr.push_back('(');
				else if (!vr.empty())
					vr.pop_back();
			}
			if (!vr.empty())
			{
				n = 0;
				vl = vector<char>();
				continue;
			}
			else
			{
				vl.pop_back();
				n += 2;
				if (max < n) max = n;
			}
		}
		else n = 0;
	}

	return max;
}

int main()
{

	string s("()(()");
	string s1("(()");
	cout << longestValidParentheses(s);
	return 0;
}

