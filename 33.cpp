// 33.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {

	int mid = nums.size() / 2;
	int l = 0;
	int r = nums.size() - 1;
	if (l == r && nums[0] == target) return l;

	while (l <= r)
	{
		mid = l+(r - l) / 2;
		if (nums[mid] == target) return mid;

		if (nums[l] > nums[mid]) //左边无序
		{
			//先在右边用二分查找
			int temp_l = mid+1;
			int temp_r = r;
			
			while (temp_l <= temp_r)
			{
				int temp_mid = (temp_l + (temp_r - temp_l) / 2);
				if (nums[temp_mid] == target) return temp_mid;

				if (target > nums[temp_mid]) temp_l = temp_mid + 1;
				else temp_r = temp_mid - 1;
	
			}
			
			// 运行到此处 说明右边有序部分已经查不到。在左边无序中继续找
			r = mid-1;
			mid = (r - l) / 2;
		}
		else //右边无序
		{
			int temp_l = l;
			int temp_r = mid-1;
			
			while (temp_l <= temp_r)
			{
				int temp_mid = (temp_l + (temp_r - temp_l) / 2);
				if (nums[temp_mid] == target) return temp_mid;

				if (target > nums[temp_mid]) temp_l = temp_mid + 1;
				else temp_r = temp_mid - 1;
			}

			// 运行到此处说明，左边有序已经查不到。继续在右边工作
			l = mid + 1;
		}
	}
	return -1;
}

int main()
{
	vector<int> v{ 5,1,3 };
	int t = 4;
	cout << search(v, t);

	system("pause");
}
