// 57.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
	int pos = 0;
	int left = 0;
	int right = intervals.size();
	int mid = 0;

	if (!intervals.empty())
	{
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (intervals[mid][0] == newInterval[0])
				break;
					
			if (intervals[mid][0] > newInterval[0])
				right = mid - 1;
			else
				left = mid + 1;
		
		}
	}
	pos = mid;

	intervals.insert(intervals.begin() + pos, newInterval);

	int i = pos - 1;
	if (i < 0) i++;
	int flag = 0;

	while (i + 1 < intervals.size())
	{
		if (intervals[i][1]<intervals[i+1][0]&&flag == 1) break;

		flag = 1;
		int l = intervals[i][0];
		int r = intervals[i][1];

		int next_l = intervals[i + 1][0];
		int next_r = intervals[i + 1][1];

		if (next_l <= r)//需要合并
		{
			flag = 0;
			if (next_r > r) // next_r为界限
				intervals[i][1] = next_r;

			intervals.erase(intervals.begin() + i + 1);
			continue;
		}
		i++;
	}

	return intervals;
}

int main()
{
	vector<vector<int>> v{ {1,2},{3,5},{6,7},{8,10},{12,16} };
	vector<int> n{ 4,8 };

	auto a = insert(v, n);
	for (auto b : a)
		cout << b[0] << " " << b[1] << endl;


	system("pause");
}
