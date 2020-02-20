// 26.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	/*if (nums.empty()) return 0;
	if (nums.size() < 2) return 1;
	if (nums[0] == nums[nums.size() - 1]) return 1;

	int max = *(nums.end()-1);

	int rank = 0;

	while (nums[rank] < max)
	{
		if (nums[rank] == nums[rank + 1])
		{
			nums.erase(nums.begin() + rank+1);
			nums.push_back(nums[rank]);
			continue;
		}
		rank++;
	}

	return rank+1;*/
	

	if (nums.empty()) return 0;
	if (nums.size() < 2) return 1;
	if (nums[0] == nums[nums.size() - 1]) return 1;

	int rank = 1;
	int sorted = 0;

	while (rank < nums.size())
	{
		if (nums[rank] == nums[sorted])
		{
			rank++;
			continue;
		}
		sorted++;
		if (sorted != rank)
			nums[sorted] = nums[rank];
	}

	return sorted+1;
}

int main()
{
	vector<int> n{ 0,0,1,1,1,2,2,3,3,4 };
	int m = removeDuplicates(n);
	cout << m << endl;

	for (auto a : n) 
		cout << a << endl;
}

