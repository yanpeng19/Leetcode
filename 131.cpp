// 131.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is(string& s);

vector<vector<string>> partition(string s) 
{
	if (s.empty()) return vector<vector<string>>();

	vector<vector<string>> r{ {string{s[0]} }};
	string before{ s[0] };

	for (int i = 1; i < s.size(); i++)
	{
		
		auto r_back = r;

		//独立串必定为回文，每次都插到最后
		vector<string> back = r.back();
		back.push_back(string{ s[i] });

		for (int j = 0; j < r_back.size(); j++)
		{
			// 成立的情况，后面加入单独的 字符一定是成立的
			r[j].push_back(string{ s[i] });

			// 已经成立的，尾部串加入此入新字母，是否为回文
			string temp = r_back[j].back();

			temp += s[i];
			if (is(temp))
			{
				r_back[j][r_back[j].size() - 1] = temp;
				r.push_back(r_back[j]);
			}
		}

		// 从后往前更新
		for (int j = i - 2; j >= 0; j--)
		{
			string temp(s.begin() + j, s.begin() + i);
			string t_n = temp + s[i];
			if (!is(temp) && is(t_n))
			{
				vector<vector<string>> v = partition(string(s.begin(), s.begin() + j));
				for (auto a : v)
				{
					a.push_back(t_n);
					r.push_back(a);
				}
				if (v.empty()) r.push_back(vector<string>{t_n});
			}

		}

		before += s[i];
	}

	return r;
}

bool is(string& s)
{
	if (s.empty()) return 0;
	if (s.size() == 1) return 1;

	int l = 0;
	int r = s.size() - 1;
	
	if (s.size() % 2)
	{
		while (s[l] == s[r] && l != r)
		{
			l++;
			r--;
		}

		if (l == r) return 1;
		else return 0;

	}
	else
	{
		while (s[l] == s[r] && l < r)
		{
			l++;
			r--;
		}
		if (l > r) return 1;
		else return 0;
	}
}

int main()
{
	string s("efe");

	auto a = partition(s);

	for (auto b : a)
	{
		for (auto c : b)
			cout << c << " ";
		cout << endl;
	}
	system("pause");
}

