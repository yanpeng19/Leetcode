// 150.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int evalRPN(vector<string>& tokens)
{
	if (tokens.empty()) return 0;

	vector<int> v;

	for (auto a : tokens)
	{
		if (a.find_first_of("0123456789") != string::npos)
			v.push_back(stoi(a));
		else
		{
			int n2 = v.back();
			v.pop_back();
			int n1 = v.back();
			v.pop_back();

			if (a == "+") v.push_back(n1 + n2);
			if (a == "-") v.push_back(n1 - n2);
			if (a == "*") v.push_back(n1 * n2);
			if (a == "/") v.push_back(n1 / n2);
		}
	}
	return v[0];
}
	


int main()
{
	vector<string> v{ "3","-4","+" };
	cout << evalRPN(v);
	system("pause");
	return 0;

}











