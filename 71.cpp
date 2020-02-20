// 71.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string simplifyPath(string path) 
{
	if (path == "/") return "/";
	path += '/';

	vector<string> line;
	
	auto pos = path.find_first_not_of('/');
	// 存所有非'/' 内容
	while (pos != string::npos)
	{
		auto next = path.find_first_of("/",pos);
		line.push_back(string(path,pos,(next-pos)));
		pos = path.find_first_not_of( "/", next + 1);
	}

	vector<string> resault{ "/" };

	for (auto a : line)
	{
		if (a == ".") continue;
		if (a == ".." && resault.size() > 1)
			resault.pop_back();
		if (a != ".." && a != ".")
			resault.push_back(a);
	}

	if (resault.size() == 1) return string("/");
	else
	{
		stringstream ss;
		for (int i = 0; i < resault.size(); i++)
		{
			ss << resault[i];
			if (i != 0 && i != resault.size() - 1)
				ss << "/";
		}
		return ss.str();
	}
}

int main()
{
	cout << simplifyPath("/a/../../b/../c//.//");
	
	system("pause");
}
