// 31.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
#include <time.h>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) 
{
	if (nums.empty()||nums.size()<2) return;

	int max_j = -1;
	int target_i = -1;
	// 第一个非零值，然后mid 为 min 左侧任何数值
	for (int i = nums.size()-1; i > 0; i--)
	{
		if (nums[i] == 0)
			continue;

		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j] < nums[i])
			{
				if (max_j < j)
				{
					max_j = j;
					target_i = i;
				}
					
			}

		}
	}

	if (max_j != -1)
	{
		int t = nums[target_i];
		nums.erase(nums.begin() + target_i);
		nums.insert(nums.begin() + max_j, t);
		sort(nums.begin() + max_j + 1, nums.end());
		return;
	}


	reverse(nums.begin(), nums.end());
	while (!nums.empty() && nums[0] == 0)
		nums.erase(nums.begin());

};

int main()
{
	vector<int> v{ 4,2,0,2,3,2,0};

	nextPermutation(v);

	for (auto a : v) cout << a << endl;
	system("pause");
}

