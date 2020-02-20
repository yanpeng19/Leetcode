// 78.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>	

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) 
{
	sort(nums.begin(), nums.end());
	if (nums.empty()) return vector<vector<int>>();

	vector<vector<int>> r;
	for (auto a : nums)
		r.push_back(vector<int>{a});

		
	if (nums.size() == 1)
	{
		r.push_back(vector<int>{});
		return r;
	}
		
	nums.erase(nums.begin());

	while (!nums.empty())
	{
		auto temp = r;
		for (int i = 0; i < temp.size(); i++)
		{
			if (*(temp[i].end() - 1) < nums[0])
			{
				auto t = temp[i];
				t.push_back(nums[0]);
				r.push_back(t);
			}
		}
		nums.erase(nums.begin());
	}

	sort(r.begin(), r.end());

	for (auto a : r)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	return r;
}

int main()
{
	vector<int> v{ 0};
	subsets(v);
	system("pause");
}
