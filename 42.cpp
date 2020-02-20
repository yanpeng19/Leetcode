// 42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) 
{
	if (height.size() < 3) return 0;
	int n = 0;

	// 首先找到最高点位置

	int longest_rank = 0;

	for (int i = 0; i < height.size(); i++)
		if (height[i] > height[longest_rank]) 
			longest_rank = i ;

	// 从最高点向左和右分别找到次高点，然后计算面积
	// 面积 = 次高点高度*二者距离-（中间点的高度和）

	int left_l = longest_rank-1;
	int left_r = longest_rank;

	while (left_l >= 0)
	{
		for (int i = left_r - 1; i >= 0; i--)
			if (height[i] >= height[left_l])
				left_l = i;
		
		if (left_l == left_r - 1)
		{
			left_r = left_l;
			left_l--;
			continue;
		}
				
		int h = height[left_l];
		int temp_n = 0;
		for (int i = left_l + 1; i < left_r; i++)
			temp_n += height[i];

		n += h * (left_r-left_l-1) - temp_n;


		left_r = left_l;
		left_l = left_r - 1;
	}

	int right_l = longest_rank;
	int right_r = longest_rank + 1;

	while (right_r < height.size())
	{
		for (int i = right_l + 1; i <height.size(); i++)
			if (height[i] >= height[right_r])
				right_r = i;

		if (right_r == right_l + 1)
		{
			right_l = right_r;
			right_r++;
			continue;
		}


		int h = height[right_r];
		int temp_n = 0;
		for (int i = right_l+1; i < right_r; i++)
			temp_n += height[i];

		n += h * (right_r - right_l - 1) - temp_n;

		right_l = right_r;
		right_r++;
	}

	return n;

}

int main()
{
	vector<int> v{ 2,0,2 };
	cout << trap(v) << endl;
	system("pause");
	return 0;
}
