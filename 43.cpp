// 43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

string multiply(string num1, string num2) 
{
	if (num1 == "0" || num2 == "0") return string("0");

	deque<int> n1;
	deque<int> n2;
	deque<int> resault;

	for (auto a : num1)
		n1.push_front(a - 48);
	for (auto b : num2)
		n2.push_front(b - 48);

	// 低位在前，高为灾后
	// num1 : 3 , 2 , 1  = 123
	// num2 : 6 , 5 , 4  = 456

	int m = 0;

	for (int i = 0; i < n1.size(); i++)
	{
		deque<int> temp_d;
		int flag = 0;

		// i * n2,存在temp中
		for (int j = 0; j < n2.size(); j++)
		{
			int num = (n2[j] * n1[i]) + flag;
			flag = num / 10;
			num = num % 10;
			temp_d.push_back(num);
		}
		if (flag != 0) temp_d.push_back(flag);

		for (int i = 0; i < m; i++)
			temp_d.push_front(0);

		// resault : 1 * 456 = 6 , 5 , 4
		int rank = 0;
		flag = 0;
		// resault 永远比 temp_t 多一位
		while (resault.size() <= temp_d.size())
			resault.push_back(0);

		while (rank < temp_d.size())
		{
			int num = resault[rank] + temp_d[rank] + flag;
			flag = num / 10;
			num = num % 10;
			resault[rank] = num;
			rank++;
		}

		while (flag != 0)
		{
			while (resault.size() <= rank) resault.push_back(0);
			int num = resault[rank] + 1;
			flag = num / 10;
			num = num % 10;
			resault[rank] = num;
			rank++;
		}
		m++;
	}

	string num3;
	while (resault[resault.size() - 1] == 0) resault.erase(resault.end() - 1);
	
	for ( int rank = resault.size()-1; rank >= 0; rank--)
		num3 += char(resault[rank] + 48);
	
	return num3;
}

int main()
{
	string s1("0");
	string s2("0");

	cout << multiply(s1, s2);

    std::cout << "Hello World!\n";
}

