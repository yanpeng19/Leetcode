// 35.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	int mid;
	int pos = -1;

	// 首先找到第一个位置，然后从这个位置+1和-1找左边和右边的target
	while (l <= r)
	{
		mid = l + (r - l) / 2;
		if (nums[mid] == target)
			return mid;
		if (target < nums[mid]) r = mid - 1;
		else l = mid + 1;
	}

	return l;
}


int main()
{
	vector<int> v{ 1,3,5,6 };
	cout << searchInsert(v, 2);
	system("pause");
}
