// 77.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combine(int n, int k) 
{

	// 回溯法
	/*
	if (k == 0||n<k) return vector<vector<int>>(); 
	if (k == 1)
	{
		vector<vector<int>> resault;
		for (int i = 1; i <= n; i++)
			resault.push_back(vector<int>{i});
		return resault;

	}

	vector<int> nums;
	for (int i = 1; i <= n; i++)
		nums.push_back(i);
	if (n == k) return vector<vector<int>>{nums};

	vector<vector<int>> resault;
	vector<vector<int>> nums_back;
	vector<vector<int>> line_back;

	for (int i = n - k + 1; i > 0; i--)
	{
		line_back.push_back(vector<int>{i});
		auto temp = nums;
		temp.erase(temp.begin(), temp.begin() + i);
		nums_back.push_back(temp);
	}

	while (!line_back.empty())
	{
		vector<int> line = line_back.back();
		nums = nums_back.back();

		line_back.pop_back();
		nums_back.pop_back();

		if (line.size() == k)
		{
			resault.push_back(line);
			continue;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			auto temp = line;
			temp.push_back(nums[i]);
			line_back.push_back(temp);
			nums_back.push_back(vector<int>(nums.begin() + i+1, nums.end()));
		}
	}
	for (auto a : resault)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	return resault;
	*/

	// 排序法
	vector<vector<int>> nums{ {1} };

	vector<vector<int>>resault;
	
	int num = 2;
	int m = 1;

	while (num <= n)
	{
		vector<vector<int>> temp_nums = nums;
		nums.clear();

		for (int i = 0; i < temp_nums.size(); i++) 
		{
			for (int j = 0; j <= temp_nums[i].size(); j++)
			{
				auto temp = temp_nums[i];
				temp.insert(temp.begin() + j, num);
				nums.push_back(temp);
			}
		}
		m *= 2;

	

		
		for (auto a : nums)
			if (a.size() == k)
				resault.push_back(a);
		num++;
	}

	sort(resault.begin(), resault.end());

	for (auto a : resault)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	vector<vector<int>> r;
	for (auto a : resault)
	{
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i] > a[i + 1]) break;
			if (i == a.size() - 1) r.push_back(a);
		}
	}

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
	combine(4, 3);
}

