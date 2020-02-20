// 46.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
#include<algorithm>
#include <set>

using namespace std;

vector<vector<int>> permute(vector<int>& nums)
{
	if (nums.empty()) return vector<vector<int>>();
	vector<vector<int>> resault{ {nums[0]} };

	// 得到一个新的数，就把原数组拷贝n份，并且在分别在 1~n的位置插入
	int n = 1;
	set<vector<int>> s;

	for (int i = 1; i < nums.size(); i++)
	{
		n++;

		vector<vector<int>> temp = resault;
		resault = vector<vector<int>>();
		
		for (auto a : temp)  // 把每个数从 0~n 插入新的数
		{
			vector<int> t;

			for (int j = 0; j < n; j++)
			{
				auto b = a;
				b.insert(b.begin() + j, nums[i]);
				if (s.find(b) == s.end())
				{
					s.insert(b);
					resault.push_back(b);
				}
			}	
		}
	}


	return resault;
}

int main()
{
	vector<int> m{ 1,2,2};
	auto v = permute(m);
	for (auto a : v)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}

