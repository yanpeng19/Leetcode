// 93.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;



vector<string> restoreIpAddresses(string s) 
{
	if (s.size() < 4 || s.size() > 12) return vector<string>();

	string s1, s2, s3, s4;
	vector<string> r;

	for (int i = 1; i <= 3; i++)
	{
		s1 = string(s, 0, i);
		if (s1.size() > 1 && s1[0] == '0') continue;

		if ((s.size()-i)<=9&&(s1.size()<3||s1<="255"))
		{
			for (int j = 1; j <= 3; j++)
			{
				s2 = string(s, i , j);
				if (s2.size() > 1 && s2[0] == '0') continue;
				if ((s.size() - i-j) <= 6 && (s2.size() < 3 || s2 <= "255"))
				{
					for (int k = 1; k <= 3; k++)
					{
						s3 = string(s, i  + j , k);
						if (s3.size() > 1 && s3[0] == '0') continue;

						if ((s.size()-i-j-k)<=3 && (s3.size() < 3 || s3 <= "255"))
						{
							s4 = string(s.begin() + i + j + k , s.end());
							if (s4.size() > 1 && s4[0] == '0') continue;
							if (!s4.empty() && (s4.size() < 3 || s4 <= "255"))
							{
								string temp;
								temp = temp + s1 + '.' + s2 + '.' + s3 + '.' + s4;
								r.push_back(temp);
							}
								
						}
					}
				}
			}
		}
	}

	for (auto a : r)
		cout << a << " ";
	cout << endl;

	return r;

}

int main()
{
	string s("010010");
	auto a = restoreIpAddresses(s);
}

