// 40.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int>& nums = candidates;

	if (!nums.empty());
	sort(nums.begin(), nums.end());

	vector<int> vr; // 存储下一个位置的 r 的值
	vector<vector<int>> v_temp;

	vector<int> temp;
	vector<vector<int>> resault;

	int rank = 0;
	int n = 0;

	do
	{
		if (!temp.empty())
			for (auto a : temp)
				n += a;
		else n = 0;

		while (n <= target)
		{
			while (rank + 1 < nums.size() && nums[rank + 1] == nums[rank])
			{
				auto p = find(temp.begin(), temp.end(), nums[rank]);
				if (p != temp.end()) rank++;
			}
				

			if (rank < nums.size())
			{
				if (rank + 1 < nums.size())
				{
					vr.push_back(rank + 1);   // 存下一个位置
					v_temp.push_back(temp);   // 下一个位置的 序列数状态
				}
				temp.push_back(nums[rank]);
				n += nums[rank];
				rank++;
			}
			

			if (n == target)
				resault.push_back(temp);

			if (n >= target && !vr.empty())
			{
				rank = vr.back();
				vr.pop_back();

				temp = v_temp.back();
				v_temp.pop_back();

				n = 0;

				for (auto a : temp)
					n += a;
			}
			if (n == target && vr.empty())
				break;
			if (n < target && rank >= nums.size())
			{
				if (vr.empty()) break;
				else
				{
					rank = vr.back();
					vr.pop_back();

					temp = v_temp.back();
					v_temp.pop_back();

					n = 0;

					for (auto a : temp)
						n += a;
				}
			}
		}
		
	} while (!vr.empty());

	sort(resault.begin(), resault.end());
	resault.erase(unique(resault.begin(), resault.end()), resault.end());

	return resault;

}

int main()
{

	vector<int> v{ 1,2 };

	auto r = combinationSum(v, 4);
	if (!r.empty())
		for (auto a : r)
		{
			for (auto b : a)
			{
				cout << b << " ";
			}
			cout << endl;
		}


	

	return 0;

}