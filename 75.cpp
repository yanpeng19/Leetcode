// 75.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) 
{
	if (nums.empty()) return;
	int n = 0; 
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			nums.insert(nums.begin(), 0);
			nums.erase(nums.begin() + i+1);
		}
		else if (nums[i] == 2)
		{
			i--;
			n++;
			nums.erase(nums.begin() + i);
		}
	
	}
	while (n > 0)
	{
		nums.push_back(2);
		n--;
	}

	return;
 }

int main()
{
	vector<int> v{ 1,2,0 };
	sortColors(v);
}

