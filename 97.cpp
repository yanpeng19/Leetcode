// 97.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//vector<size_t> back{ 0,0,0 };

//while (!back.empty())
//{
//	// s3[k]  s2[j] s1[i]
//	size_t i = back.back();
//	back.pop_back();

//	size_t j = back.back();
//	back.pop_back();

//	size_t k = back.back();
//	back.pop_back();

//	if (k == s3.size()) return 1;

//	if (s1[i] == s3[k])
//	{
//		back.push_back(k + 1);
//		back.push_back(j);
//		back.push_back(i + 1);
//	}
//	if (s2[j] == s3[k])
//	{
//		back.push_back(k + 1);
//		back.push_back(j+1);
//		back.push_back(i);
//	}
//}

bool isInterleave(string s1, string s2, string s3) 
{
	if (s1.empty() && s2.empty() && s3.empty()) return 1;
	if ((s1.size() + s2.size()) != s3.size()) return 0;
	if (s1.empty()) return s2 == s3;
	if (s2.empty()) return s1 == s3;



	vector<vector<bool>> table(s2.size()+1, vector<bool>(s1.size()+1, 0));


	int rank = 0;
	for (int i = 1; i <= s1.size(); i++)
	{
		if (s1[i-1] == s3[rank])
		{
			table[0][i] = 1;
			rank++;
		}
		else break;
	}


	rank = 0;
	for (int i = 1; i <= s2.size(); i++)
	{
		if (s2[i-1] == s3[rank])
		{
			table[i][0] = 1;
			rank++;
		}
		else break;
	}

	for (int i = 1; i <= s2.size(); i++)
	{
		for (int j = 1; j <= s1.size(); j++)
		{
			int rank = i + j - 1;

			//cout << "s3[rank]: " << s3[rank] << endl;
			if (s3[rank] == s2[i-1] && table[i - 1][j])
				table[i][j] = 1;
			if (s3[rank] == s1[j-1] && table[i][j - 1])
				table[i][j] = 1;
		}
	}

	

	
	if (table[s2.size()][s1.size()] == 1) return 1;
	return 0;
}

int main()
{
	string s1("aa");
	string s2("ab");
	string s3("abaa");

	cout << isInterleave(s1, s2, s3);

	system("pause");
}
