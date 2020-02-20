// 6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_string(const string& s, int n)
{
	if (n == 1) return s;

	int row = n; // 行
	int col;// 列

	int num_n; // 每组多少个数；
	int num_c; // 每组多少行；

	if (n == 2)
	{
		string resault;

		int size = s.size()/2;
		for (int index = 0; index < s.size(); index+=2)
		{
			resault += s[index];
		}

		for (int index = 1; index < s.size(); index += 2)
		{
			resault += s[index];
		}

		return resault;
	}


	vector<vector<char>> mar(n);
	string resault;

	int x = 0;
	int flag = 0;
	int num = 0;
	for (int i = 0; i < s.size(); i++) //O(n)
	{

		if (flag==0&&num<n)
		{
			if (x == -1) x = 0;
			mar[x].push_back(s[i]);
			x++;
			num++;
		}
		else
		{
			flag = 1;
			if (x == n)
			{
				x = n - 2;
			}

			mar[x].push_back(s[i]);
			x--;
			num++;
			if (num == n + n - 2)
			{
				num = 0;
				flag = 0;
			}
		}
	}

	for (auto a : mar)
	{
		for (auto b : a)
			resault += b;
	}
	return resault;
}

int main()
{
	string s("PAYPALISHIRING");
	string r = get_string(s, 3);

	if (r == "LCIRETOESIIGEDHN") cout << "yes";

	system("pause");
	return 0;
}


