// 22.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> generateParenthesis(int n) 
{
	// 1 为左括号 0 为右括号
	if (n == 0) return vector<string>();
	if (n == 1) return vector<string>{"()"};

	vector<string> resault{ "()" };

	for (int i = 1; i < n; i++)
	{
		vector<string> temp = resault;
		resault = vector<string>();

		for (auto a : temp)
		{
			// a 为 每个string
			for(int rank = 0;rank < a.size();rank++)
			{
				//每个位置插入10
				string s = a;
				s.insert(rank, "()");
				resault.push_back(s);
			}
		}
		sort(resault.begin(), resault.end());
		resault.erase(unique(resault.begin(), resault.end()), resault.end());
	}

	return resault;
}

int main()
{
	vector<string> v = generateParenthesis(3);
	for (auto a : v)
	{
		cout << a << endl;
	}
}

