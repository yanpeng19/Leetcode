// 39.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<int> &nums = candidates;

	if (!nums.empty());
	sort(nums.begin(), nums.end());
	

	vector<int> vr; // 存储下一个位置的 r 的值
	vector<int> vn;
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
			if (rank < nums.size())
			{
				if (rank + 1 < nums.size())
				{
					vr.push_back(rank + 1);   // 存下一个位置
					v_temp.push_back(temp);   // 下一个位置的 序列数状态
					temp.push_back(nums[rank]);
					vn.push_back(n);
				}
				n += nums[rank];
			}

			if (n == target)
				resault.push_back(temp);

			if (n >= target && !vr.empty())
			{
				rank = vr.back();
				vr.pop_back();

				temp = v_temp.back();
				v_temp.pop_back();

				n = vn.back();
				vn.pop_back();
			}
		}
	} while (!vr.empty());
		
	return resault;

}

int main()
{

	vector<int> v{10,1,2,7,6,1,5};

	auto r = combinationSum(v, 8);
	if(!r.empty())
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
