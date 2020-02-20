// 91.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s) 
{
	if (s.empty()) return 0;
	if (s[0]=='0') return 0;

	int f = 0;

	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			f = 1;
			if (s[i - 1] == '0' || s[i - 1] > '2') return 0;
		}
	}


	if (!f && s.size() < 2) return 1;


	if (s.size() == 2)
	{
		string t("26");
		if (!f) return (s <= t) + 1;
		else return s <= t;
	}
	else 
	{
		int pos = 0;
		pos = s.size() / 2;

		if (!f)
		{
			string temp = string(s.begin(), s.begin() + pos);
			string temp2 = string(s.begin() + pos, s.end());
			string temp3;
			
			temp3 += temp[temp.size() - 1];
			temp3 += temp2[0];
			
			
			int n = 0;
			int n1 = numDecodings(temp2);
			int n2 = numDecodings(temp);

			n = n1 * n2;

			if (temp3 <= "26") n++;
			return n;
		}
		else
		{
			int pos = 0;
			pos = s.size() / 2;
			if (s[pos] == '0') pos++;

			string temp = string(s.begin(), s.begin() + pos);
			string temp2 = string(s.begin() + pos, s.end());
			string temp3;

			temp3 += temp[temp.size() - 1];
			temp3 += temp2[0];

			int n = 0;
			int n1 = numDecodings(temp2);
			int n2 = numDecodings(temp);

			if (!n2) n2 = 1;
			n = n1 * n2;

			if (temp3[0]!='0'&&temp3 <= "26"&&temp2.size()>1&&temp2[1]!='0') n++; 
			return n;
		}
	}

}


int main()
{
	//cout << numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253");
	// 3 * (3 * 3)
	cout << numDecodings("12120");
	cout << endl;
	system("pause");
}

