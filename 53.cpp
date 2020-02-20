// 53.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
	if (nums.empty()) return 0;
	if (nums.size() < 2) return nums[0];

	int max = nums[0];
	int temp = nums[0];
	int m = nums[0]; //记录最大元素
	if (nums[0] < 0) max = temp = 0;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] > m) m = nums[i];
		
		temp += nums[i];
		if (temp > max) max = temp;
		if (temp < 0)
			temp = 0;
	}
	if (max == 0) return m;
	else return max;
}

int main()
{
	vector<int> v{ -1,1,2,1 };

	cout << maxSubArray(v);
	system("pause");
}

