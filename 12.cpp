// 12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string fuc(int num)
{
	map<int, string> m = {
		{ 1,"I" }, { 2,"II" }, { 3,"III" }, { 4,"IV" }, { 5,"V" }, { 6,"VI" }, { 7,"VII" }, { 8,"VIII" }, { 9,"IX" },{ 10,"X" },
	{20,"XX"},{30,"XXX"},{40,"XL"},{50,"L"},{60,"LX"},{70,"LXX"},{80,"LXXX"},{90,"XC"},{100,"C"},
	{200,"CC"},{300,"CCC"},{400,"CD"},{500,"D"},{600,"DC"},{700,"DCC"},{800,"DCCC"},{900,"CM"},
	{1000,"M"},{2000,"MM"},{3000,"MMM"}	};

	int n = 0;
	int t = 1;
	string resault;
	while (num != 0)
	{
		n = num % 10;
		num = num / 10;

		if (n != 0)
		{
			auto temp = m.find(n * t);
			string s = temp->second;
			resault = s + resault;
		}
		t = t * 10;
	} 
	return resault;
}

int main()
{
	cout << fuc(1994) << endl;
	system("pause");
	return 0;
}
