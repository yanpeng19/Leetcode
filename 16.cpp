// 16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int func(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());
	int max = target - (nums[0] + nums[1] + nums[2]);
	int size = nums.size();
	int t = nums[0]+nums[1]+nums[2];

	for (auto i = nums.begin(); i < nums.end() - 2; i++)
	{
		for (auto j = nums.end() - 1; j > i + 1; j--)
		{
			int mid = target - (*i + *j);
			// mid为理想值

			// logn * 2
			auto m = lower_bound(i+1, j, mid);
			if (m == i) m = i + 1;

			auto n = m - 1;
			
			if (m == j) m = j - 1;
			if (n == i) n = i + 1;
			if (n == j) n = j - 1;

			auto temp = m;

			
			int m_num = target - *m - *i - *j;
			int n_num = target - *n - *i - *j;

			if (m_num < 0) m_num = 0 - m_num;
			if (n_num < 0) n_num = 0 - n_num;

			int resault = max;

			if (m_num < n_num)
			{
				resault = m_num;
				temp = m;
			}
			else
			{
				resault = n_num;
				temp = n;
			}

			if (resault == 0) return *i + *temp + *j;

			if (resault < max)
			{
				max = resault;
				t = *i + *j + *temp;
			}
			
				

			while (j > i + 1 && *j == *(j - 1))
				j--;
		}
		while (i < nums.end() - 2 && *i == *(i + 1))
			i++;
	}

	return t;
}

int main()
{
	vector<int> v{ 1,6,9,14,16,70};
	int r = func(v,81);
	cout << r;
	cout << endl;
}
