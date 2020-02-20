// 72.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) 
{
	vector<vector<int>> table(word1.size() + 1, vector<int>(word2.size() + 1, 0));


	for (int i = 0; i < word2.size() + 1; i++)
		table[0][i] = i;

	for (int i = 0; i < word1.size() + 1; i++)
		table[i][0] = i;

	int line = word1.size() + 1;
	int col = word2.size() + 1;

	for (int i = 1; i < line; i++)
	{
		for (int j = 1; j < col; j++)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				int min = table[i - 1][j - 1];
				int mid = table[i - 1][j] < table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
				table[i][j] = min < mid ? min : mid;
			}
			else
			{
				int min = table[i - 1][j - 1];
				int mid = table[i - 1][j] < table[i][j - 1] ? table[i - 1][j] : table[i][j - 1];
				table[i][j] = (min < mid ? min : mid)+1;
			}
		}
	}

	return table[line - 1][col - 1];
}

int main()
{
	string s1("horse");
	string s2("ros");
	cout << minDistance(s1, s2);
	system("pause");
}
