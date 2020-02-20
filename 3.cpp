// max_string_.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_next(const string& s)
{
	//abcabca
	vector<int> next(s.size(), -1);

	for (int i = 1; i < s.size(); i++)
	{
		for (int j = i-1; j >=0; j--)
		{
			if (s[j] == s[i])
			{
				next[i] = j;
				break;
			}
		}
	}
	return next;

}

int get_max(const string& s, vector<int> next)
{
	int max_num=0;

	int begin = 0;
	int max = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (next[i] == -1) max++;
		else
		{
			if (begin < next[i])
			{
				begin = next[i];
			}
			
			max = i - begin;
		}

		if (max > max_num) max_num = max;
	}

	return max_num;
}

int main()
{
	//O(n^n)
	string s("bbbbb");

	vector<int> r = get_next(s);
	for (auto a : r)
		cout << a << " ";
	cout << endl;

	cout << get_max(s, r);

	//                 -1    -1   -1    1    0        2           -1 

	//max               1     2    3    2    3        3            4
	// max = index - bgein
	// if(next[i]>=begin)
	// begin = next[i]

	//begin             0     0    0    2    2        3            3

	//index-next[i]   
 

	system("pause");
}

