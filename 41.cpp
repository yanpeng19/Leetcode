// 41.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] <= 0) nums[i] = -1;
		else if (nums[i] > (nums.size()+1)) nums[i] = -1;
	}

	nums.push_back(-1);
	nums.push_back(-1);

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0&&nums[i]!=nums[nums[i]])
		{
			swap(nums[i], nums[nums[i]]);
			i--;
		}
	}

	for (int i = 1; i < nums.size(); i++)
		if (nums[i] != i) return i;
	
	return nums.size();
}

int main()
{
	vector<int> v{ 2 };

	cout << firstMissingPositive(v);

	cout << endl;
}

