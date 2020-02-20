// 80.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) 
{
	if (nums.empty()) return 0;
	if (nums.size()<3) return nums.size();

	int f = 0;
	int j = 0;

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] == nums[j] && f == 0)
		{
			f++;
			if (i != j + 1) swap(nums[j+1], nums[i]);
			j++;
		}
		else if (nums[i] == nums[j] && f != 0)
		{
			continue;
		}
		else
		{
			f = 0;
			if (i != j + 1) swap(nums[j + 1], nums[i]);
			j++;
		}
	}

	return j+1;
}

int main()
{
	vector<int> v{ 0,0,1,1,1,1,2,3,3 };
	int s =   removeDuplicates(v);
	for (int i = 0; i < s; i++)
		cout << v[i] << " ";
	cout << endl;
	system("pause");
}
