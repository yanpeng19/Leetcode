// 81.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
	if (nums.empty()) return 0;
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	int l = 0;
	int r = nums.size() - 1;
 	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) return 1;

		if (nums[mid] < nums[l])
		{
			// 左边是是逆序的 , 右边二分查找
			int t_l = mid + 1;
			int t_r = r;

			while (t_l <= t_r)
			{
				int t_mid = t_l + (t_r-t_l) / 2;
				if (nums[t_mid] == target) return 1;
				if (target < nums[t_mid]) t_r = t_mid - 1;
				else t_l = t_mid + 1;
			}
			// 右边没有找到
			r = mid - 1;
		}
		else
		{
			// 左边是顺序，右边逆序
			int t_l = l;
			int t_r = r-1;

			while (t_l <= t_r)
			{
				int t_mid = t_l + (t_r - t_l) / 2;
				if (nums[t_mid] == target) return 1;
				if (target < nums[t_mid]) t_r = t_mid - 1;
				else t_l = t_mid + 1;
			}
			//左边没有找到
			l = mid + 1;
		}
	}

	return 0;
}

int main()
{
	vector<int> v{ 4,5,6,7,0,1,2};
	cout << search(v,3);
}
