// 84.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) 
{
	if (heights.empty()) return 0;
	vector<int> left;
	vector<int> right(heights.size(),0);

	for (int i = 0; i < heights.size(); i++)
	{
		if (i == 0)
		{
			left.push_back(i);
			continue;
		}

		if (heights[i] == heights[i - 1])
			left.push_back(left[i - 1]);

		else if (heights[i] > heights[i - 1])
			left.push_back(i);

		else if(heights[i]<heights[i-1])
		{
			int rank = left[i - 1];
			while (rank - 1 >= 0 && heights[rank-1] >= heights[i])
			{
				rank = left[rank - 1];
			}
			left.push_back(rank);
		}
	}

	// 4  2  0  3  2  4  3  4
	// 0  0  0  3  3  5  5  7
	// 
	for (int i = heights.size() - 1; i >= 0; i--)
	{
		if (i == heights.size() - 1)
		{
			right[i] = i;
			continue;
		}

		if (heights[i] == heights[i + 1])
			right[i] = right[i + 1];
		else if (heights[i] > heights[i+1])
			right[i] = i;
		else if(heights[i] < heights[i+1])
		{
			int rank = right[i + 1];

			while (rank + 1 < heights.size() && heights[rank+1] >= heights[i])
				rank = right[rank + 1];
			right[i]=rank;
		}

	}

	
	int max = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		int area = (right[i] - left[i] + 1) * heights[i];
		if (area > max) max = area;
	}

	return max;
}

int main()
{
	vector<int> v{ 4,2,0,3,2,4,3,4 };
	cout << largestRectangleArea(v);
	system("pause");
}

