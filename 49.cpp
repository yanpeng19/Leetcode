// 49.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	map<string, vector<string>> m;
	for (auto s : strs)
	{
		auto s_back = s;
		sort(s.begin(), s.end());

		m[s].push_back(s_back);
	}
	vector<vector<string>> resault;

	for (auto a : m)
		resault.push_back(a.second);

	return resault;
}


int main()
{
	vector<string> vs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	auto r = groupAnagrams(vs);
	for (auto a : r)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}

