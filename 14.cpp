// 14.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string func(vector<string> strs)
{
	if (strs.empty()) return string();

	int max_size = strs[0].size();
	int right_index = 0;

	

	for (auto a : strs)
	{
		if (max_size > a.size()) max_size = a.size();
	}

	right_index = max_size;

	for (int i = max_size - 1; i >= 0; i--)
	{
		int flag = 1;
		char c = strs[0][i];
		
		if(strs.size()>1)
		for (int j = 1;j< strs.size();j++)
		{
			if (strs[j][i] == c) continue;
			else
			{
				flag = 0;
				right_index = i;
				break;
			}
		}
	}

	if (right_index != -1)
		return string(strs[0], 0, right_index);
		
	else return string();
}


int main()
{
	vector<string> v{ "aa","a" };
	cout << func(v);
	system("pause");
}


