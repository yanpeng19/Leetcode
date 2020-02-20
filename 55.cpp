// 55.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) 
{
	if (nums.empty()) return 0;
	if (nums.size() == 1) return 1;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) return 0;

		int dis = nums[i];
		int max = 0;
		int next_rank = -1;

		for (int j = 1; j <= dis; j++)
		{
			if (i + j >= nums.size() - 1) return 1;
			if (nums[i + j] != 0 &&  (nums[i + j]+j) >= max)
			{
				max = nums[i + j]+j;
				next_rank = i + j;
			}
		}
			
		if (max == 0) return 0;
		i = next_rank - 1;
	}
}

int main()
{
	vector<int> v{ 5,9,3,2,1,0,2,3,3,1,0,0 };
	cout << canJump(v);
	system("pause");
}
