// 34.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) 
{
	if (nums.empty()) return vector<int>{-1, -1};

	int l = 0;
	int r = nums.size() - 1;
	int pos = -1;

	// 首先找到第一个位置，然后从这个位置+1和-1找左边和右边的target
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == target)
		{
			pos = mid;
			break;
		}
		if (target < nums[mid]) r = mid - 1;
		else l = mid + 1;
	}

	if (pos == -1) return vector<int>{-1, -1};

	// 这里的话，就说明里面有target开始搜索
	int min_l = nums.size();
	int max_r = -1;
	int temp_pos = pos;

	l = 0;
	r = pos - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) //继续向左直到找不到
		{
			r = mid - 1;
			l = 0;
			if (min_l > mid) min_l = mid;
			continue;
		}
		if (target < nums[mid]) r = mid - 1;
		else l = mid + 1;
	}
	if (min_l == nums.size()) min_l = pos;

	l = pos + 1;
	r = nums.size() - 1;
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (nums[mid] == target) //继续向左直到找不到
		{
			l = mid + 1;
			r = nums.size()-1;
			if (max_r < mid) max_r = mid;
			continue;
		}
		if (target < nums[mid]) r = mid - 1;
		else l = mid + 1;
	}
	if (max_r==-1) max_r = pos;

	return vector<int>{min_l, max_r};

}

int main()
{
	vector<int> v{ 0,0,0,0,0,1,1,2,2,3,4,4,5,5,5,5,6,7};

	auto a = searchRange(v, 0);
	for (auto b : a) cout << b << endl;
	system("pause");
	return 0;
}

