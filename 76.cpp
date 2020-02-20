// 76.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string minWindow(string s, string t) 
{
	
	// 暴力破解法
	/*
	vector<vector<int>> table(t.size(),vector<int>());

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < t.size(); j++)
			if (s[i] == t[j])
				table[j].push_back(i);
	}

	if (table[0].empty()) return string("");
	if (table.size() == 1) return t;

	sort(table.begin(), table.end());

	for (int i = 0; i < table.size(); i++)
	{
		int n = 0;
		if (i+1<table.size()&&table[i + 1] == table[i])
		{
			int j = i + 1;
			while (j+1 < table.size() && table[j+1] == table[i])
				j++;

			n = j - i;//多少个相同的
			vector<int> temp = table[i];

			for (int k = i; k <= i + n; k++)
				table[k].clear();
			
			int rank = i;
			for (int z = 0; z < temp.size(); z++,rank++)
			{
				if (rank > i + n) rank = i;
				table[rank].push_back(temp[z]);
			}
		
		}
	}

	int l = s.size();
	int r = 0;

	for (auto a : table)
	{
		if (a.empty())
			return string("");
		if (a[0] < l) l = a[0];
		if (a[0] > r) r = a[0];
	}

	int num = r - l;
	if (num == t.size()-1&&l!=r) 
		return string(s, l, (r - l +1));

	int resault_l = l;
	int resault_r = r;
		
	vector<int> rank(table.size(), 0);

	while (rank[0] < table[0].size())
	{
		int j = 0;
		l = s.size();
		r = 0;

		for (int i = 0; i < table.size(); i++,j++)
		{
			if (table[i][rank[j]] > r) 
				r = table[i][rank[j]];
			if (table[i][rank[j]] < l) 
				l = table[i][rank[j]];
		}

		if (r - l < num&&l!=r)
		{
			num = r - l;
			if(num==t.size()-1&&l!=r) return string(s, l, (r - l+1));
			resault_l = l;
			resault_r = r;
		}
		//cout << l << " : " << r << endl;
		//cout << endl;
		int t = rank.size() - 1;
		rank[t]++;
		while (rank[t] == table[t].size())
		{
			if (t == 0) break;
			rank[t] = 0;
			rank[t - 1]++;
			t--;
		}	
	}

	return string(s, resault_l, (resault_r - resault_l)+1);
	*/

	// 滑动窗口
	if (s.size() < t.size()) return string();

	vector<int> table (256,0);

	// 字符个数已经记录。 出现过的字符 >0 ,不存在子串中的 字符的 数目为 0
	for (int i = 0; i < t.size(); i++)
		table[t[i]]++;

	int min = s.size()+1;
	int len = 0;
	string resault;
	
	for (int l = 0, r = 0; r < s.size(); r++)
	{
		table[s[r]]--;
		// 说明这次是有效字符，所以有效长度+1
		if (table[s[r]] >= 0) len++;
		
		// 这时候就已经表示长度够了，开始移动l
		while(len == t.size())
		{
			table[s[l]]++;
			// 只有 t 的字符可能 大于0 如果大于0 
			if (table[s[l]] > 0) len--;
			if (len == t.size() - 1 && (r - l)+1 < min)
			{
				resault = string(s, l, (r - l) + 1);
				min = resault.size();
			}
				
			l++;
		}
		// l-1 是上次的合法长度
	}
	return resault;
}

int main()
{
	string s("a");
	string t("b");

	cout << minWindow(s, t);
 	system("pause");
}

