// 87.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isScramble(string s1, string s2) 
{
	if (s1 == s2) return 1;
	if (s1.size() != s2.size()) return false;
	if (s1.empty() && s2.empty()) return true;
	if (s1.empty()) return false;
	if (s2.empty()) return 0;

	string s3 = s1;
	string s4 = s2;

	sort(s3.begin(), s3.end());
	sort(s4.begin(), s4.end());

	if (s3 != s4) return 0;

	if (s1.size() == 2)
	{
		string temp;
		temp += s1[1];
		temp += s1[0];

		return temp == s2;
	}

	for (int i = 1; i < s1.size(); i++)
	{
		string t1(s1.begin(), s1.begin() + i);
		string t2(s2.begin(), s2.begin() + i);

		string t3(s1.begin() + i, s1.end());
		string t4(s2.begin() + i, s2.end());

		if (isScramble(t1, t2) && isScramble(t3, t4))
			return 1;


		t2 = string(s2.end()-i, s2.end());
		t4 = string(s2.begin(), s2.begin() + s2.size()-t2.size());
		if (isScramble(t1, t2) && isScramble(t3, t4))
			return 1;
		
	}

	return 0;
}

int main()
{
	string s1("abc");
	string s2("cab");

	cout << isScramble(s1, s2);
	system("pause");
}

