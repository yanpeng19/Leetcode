// 126.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> get(string b, string e, vector<string>& list, vector<bool> &table, int& n, int& m);

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
{
	string& b = beginWord;
	string& e = endWord;
	vector<string>& list = wordList;

	if (b.size() != e.size() || b==e) return vector<vector<string>>();

	vector<bool> table(list.size(),0);

	// table 第几个数已经用过了，不能再次使用
	// n 表示还有多少个字母不同
	// m 表示还有多少个数可以使用

	int m = list.size();
	int n = b.size();
	bool y = 0;
	bool z = 0;

	for (int i = 0; i < b.size(); i++)
	{
		if (b[i] == e[i]) n--;
		//table[i] = 1;
	}

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == e)
			y = 1;
		if (list[i] == b)
			z = 1;
	}


	if (y && z&&n==1) return vector<vector<string>>{ {b, e}};

	if (m < n||n==0||y==0) return vector<vector<string>>();
	vector<vector<string>> resault;

	for (int i = 0; i < list.size(); i++)
	{

		// 寻找所有合法变换
		string s = list[i];
		if (s == e) continue;
		else
		{
			int f = 0;

			for (int j = 0; j < s.size(); j++)
				if (b[j] == s[j]) f++;

			// 合法的
			if (f == s.size() - 1)
			{
				// table[i] 被占用，之后无法使用了
				// 问题缩减为 s->e  table.size()--;
				table[i] = 1;
				n--;
				m--;
				auto r = get(s, e, list, table, n, m);
				if (!r.empty())
				{
					for (int k = 0; k < r.size(); k++)
					{
						r[k].insert(r[k].begin(), b);
						resault.push_back(r[k]);
					}
					
				}
				n++;
				m++;
				table[i] = 0;
			}
		}

	}
	if (!resault.empty())
	{
		sort(resault.begin(), resault.end(),
			[](vector<string> a, vector<string> b) {return a.size() < b.size(); });
		size_t t =  resault[0].size();
		while (resault[resault.size() - 1].size() > t)
			resault.erase(resault.end() - 1);
	}
	
	
	return resault;
}

vector<vector<string>> get(string b, string e, vector<string>& list, vector<bool> &table,int &n,int &m)
{
	// 可用数字比差异数小，那么不可能了
	if (b == e)
		return  vector<vector<string>>{ {e}};
	if (m < n) return vector<vector<string>>();

	vector<vector<string>> resault;

	for (int i = 0; i < list.size(); i++)
	{
		if (table[i] == 1) continue;
		// 继续寻找合法变换
		string s = list[i];

		//

		// 相同字母的个数
		int f = 0;

		for (int j = 0; j < s.size(); j++)
			if (b[j] == s[j]) f++;

		// 合法转换
		if (f == s.size() - 1)
		{
			table[i] = 1;
			n--;
			m--;
			auto r = get(s, e, list, table, n, m);
			if (!r.empty())
			{
				for (int k = 0; k < r.size(); k++)
				{
					r[k].insert(r[k].begin(), b);
					resault.push_back(r[k]);
				}
			}
			n++;
			m++;
			table[i] = 0;
		}
	}
	

	return resault;
}

int main()
{
	string s1("qa");
	string s2("sq");
	vector<string> v{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	
	auto a = findLadders(s1, s2, v);
	if (!a.empty())
	{
		for (auto b : a)
		{
			for (auto c : b)
				cout << c << " ";
			cout << endl;
		}
	}

	system("pause");
}