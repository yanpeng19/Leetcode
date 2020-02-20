// 60.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string getPermutation(int n, int k)
{
	vector<int> nums;
	vector<int> table{ 1 };
	

	int temp = 1;
	for (int i=1; i <= n; i++)
	{
		nums.push_back(i);
		temp *= i;
		table.push_back(temp);
	}
	reverse(table.begin(), table.end());

	int index = 0;
	if (k == 0||k==table[0])
	{
		if (k == table[0])
			reverse(nums.begin(), nums.end());

		stringstream ss;
		
		for (auto a : nums)
			ss << a;
		return ss.str();
	}

	table.erase(table.begin());
	vector<int> r;  // 存储结果

	// 靠近
	int sum = 0;
	while (!nums.empty())
	{
		// 1次确认一个数字
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums.size() == 1)
			{
				r.push_back(nums[0]);
				nums.pop_back();
				break;
			}

			//每次增加量为 table.beging();
			sum += *table.begin();
			if (sum >= k)
			{
				sum -= *table.begin();
				r.push_back(nums[i]);
				nums.erase(nums.begin() + i);
				break;
			}

		}
		if(!table.empty())
		table.erase(table.begin());
	}

	for (auto a : nums)
		r.push_back(a);
	stringstream ss;

	for (auto a : r)
		ss << a;
	return ss.str();
}

int main()
{
	auto s = getPermutation(4, 9);
	cout << s << endl;
	system("pause");
}
