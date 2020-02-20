// 17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> letterCombinations(string digits)
{
	if (digits.empty()) return vector<string>();

	vector<vector<char>> nums;

	nums.push_back({ ' ' });
	nums.push_back({ ' ' });
	nums.push_back({ 'a', 'b', 'c' });
	nums.push_back({ 'd','e','f' });
	nums.push_back({ 'g','h','i' });
	nums.push_back({ 'j', 'k', 'l' });
	nums.push_back({'m', 'n', 'o'});
	nums.push_back({ 'p','q','r','s' });
	nums.push_back({ 't','u','v' });
	nums.push_back({ 'w','x','y','z' });

	vector<string> resault;

	for (auto i = digits.begin(); i < digits.end(); i++)
	{
		if (*i == '1') continue;
		int number = *i - 48;

		vector<char> temp = nums[number];

		if (!resault.empty())
		{
			vector<string> copy = resault;
			int j = 0;

			// 已存在内容扩展
			for (auto k = resault.begin();k<resault.end();k++)
			{
				*k += temp[j];
			}
			j++;

			//扩大 size倍
			for (int i = 0; i < temp.size() - 1; i++)
			{
				auto back = copy;

				for (auto a : back)
				{
					a += temp[j];
					resault.push_back(a);
				}
				j++;
			}
		}
		else
		{
			for (auto a : temp)
			{
				stringstream ss;
				ss << a;
				resault.push_back(ss.str());
			}
		}
		
	}
	return resault;
}

int main()
{
	vector<string> vs = letterCombinations("23");
	for (auto a : vs)
		cout << a << endl;
    
}

