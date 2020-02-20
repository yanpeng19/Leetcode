// 45.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) 
{
	// 每次寻找的rank -> 可以跳的步骤内 能其值最远的

	int rank = 0;
	int n = 0;
	int next = 1;
	while (rank+next < nums.size()-1)
	{
		n++;
		int count = nums[rank] ? nums[rank]:1; // 这次可以行动的值

		int max = 0;
		int max_rank = 0;
		for (int i = rank + 1; i <= rank + count&&i<nums.size(); i++)
			if (i == (nums.size() - 1))
			{
				max_rank = i;
				break;
			}
			else if (nums[i]+i >= max)
			{
				max = nums[i]+i;
				max_rank = i;
				
			}
		
		rank = max_rank;
		next = nums[rank] ? nums[rank] : 1;
	}
	if(rank!=nums.size()-1)
		n++;

	return n;
}

int main()
{
	vector<int> v{ 9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5 };
	cout << jump(v) << endl;
	system("pause");
}
