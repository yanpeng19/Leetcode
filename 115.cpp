// 115.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


long numDistinct(string s, string t) 
{
	if (s.size() < t.size()) return 0;
	if (t.empty() || s.empty()) return 0;
	vector<vector<long>> table(t.size(), vector<long>(s.size(), 0));

	if (s[0] == t[0]) table[0][0] = 1;

	for (long i = 1; i < s.size(); i++)
	{
		if (s[i] == t[0])
			table[0][i] = table[0][i - 1] + 1;
		else table[0][i] = table[0][i - 1];
	}

	/*for (auto a : table)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;*/

	for (long i = 1; i < t.size(); i++)
	{
		if (t[i] == s[i])
			table[i][i] = table[i-1][i-1];
		
		for (long j = i + 1; j < s.size(); j++)
		{
			if (s[j] == t[i])
			{
				long l = table[i-1][j - 1];
				long h = table[i][j-1];
				
				table[i][j] = l + h;
			}			
			else
			{
				long l = table[i][j - 1];
				table[i][j] = l;
			}
		}
		/*for (auto a : table)
		{
			for (auto b : a)
				cout << b << " ";
			cout << endl;
		}
		cout << endl;*/
	}
	

 	return table[t.size() - 1][s.size() - 1];
}


long main()
{
	string s("babgbag");
	string t("bag");
	cout << numDistinct(s, t) << endl;

	system("pause");
}

