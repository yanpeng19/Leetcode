// 9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool get_num(int x)
{
	if (x < 0) return false;
	if (x < 10) return true;

	stringstream ss;

	ss << x;

	string s = ss.str();

	string::iterator begin = s.begin();
	auto end = s.end()-1;

	while (*begin == *end)
	{
		if (begin == end || begin == (end - 1)) return true;
		begin++;
		end--;
	}
	return false;

}

int main()
{
	cout << get_num(11);

	system("pause");
	return 0;
}
