// 132.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is(string& s, int l, int r);


int minCut(string s) 
{
	if (s.empty() || s.size() == 1||is(s,0,s.size()-1)) return 0;

	//先找到最大的
	vector<int> table(s.size(), 0);
	table[0] = 0;

	for (int i = 1; i < s.size(); i++)
	{
		//最大分割次数
		table[i] = i;

		for (int j = 0; j < i; j++)
		{
			// 如果 字串 j-1~i-1 为回文
			// 模式1：ccaac a 
			// 模式2：c | caaca
			//        cc | caaca
			//  
			if (is(s, j, i))
			{
				int n = 0;
				if (j == 0||j==i) n = table[j];
				else  n = table[j-1] + 1;

				if (n < table[i])
					table[i] = n;
			}
		}

	}

	return table[table.size()-1];
}



bool is(string& s,int l,int r)
{
	if (s.empty()) return 0;
	if (s.size() == 1) return 1;


	while (s[l] == s[r] && l < r)
	{
		l++;
		r--;
	}

	if (l >= r) return 1;
	else return 0;
}

int main()
{
	cout << minCut("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj");
	system("pause");

}
