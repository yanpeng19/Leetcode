// 140.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

bool w(string s, vector<string>& wordDict);

vector<string> wordBreak(string s, vector<string>& wordDict) 
{
	if (s.empty()) return vector<string>();
	if (wordDict.empty()||!w(s,wordDict)) return vector<string>();
	
	unordered_set<string> word(wordDict.begin(), wordDict.end());

	vector<vector<string>> table(s.size());

	for (int i = 0; i < s.size(); i++)
	{
		vector<string> temp;
		for (int j = 0; j <= i; j++)
		{
			string ss(s.begin() + j, s.begin() + i + 1);
			if ((j == 0 || !table[j-1].empty()) && word.find(ss) != word.end())
			{
				if (j == 0) temp.push_back(ss);
				else
				{
					vector<string> t = table[j - 1];
					for (auto a : t)
					{
						a += " ";
						a += ss;
						temp.push_back(a);
					}
				}
				table[i] = temp;
			}
		}
	}

	/*for (auto a : table)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}*/

	return table[table.size() - 1];
}

bool w(string s, vector<string>& wordDict) {
	if (s.empty()) return 1;
	if (wordDict.empty()) return 0;

	unordered_set<string> word(wordDict.begin(), wordDict.end());

	vector<bool> table(s.size(), 0);

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			string ss(s.begin() + j, s.begin() + i + 1);
			if ((j == 0 || table[j - 1]) && word.find(ss) != word.end())
			{
				table[i] = 1;
				break;
			}
		}
	}

	return table[table.size() - 1];

}


int main()
{
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> word{ "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	auto a = wordBreak(s, word);

	system("pause");
}
