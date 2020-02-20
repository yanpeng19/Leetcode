// 56.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	/*
	if (intervals.empty() || intervals[0].empty()) return vector<vector<int>>();

	int max, min;
	max = min = intervals[0][0];
	vector<vector<int>> resault;
	vector<int> special_table;


	for (auto a : intervals)
	{
		if (a[0] == a[1])
			special_table.push_back(a[0]);

		if (a[0] > max) max = a[0];
		if (a[1] > max) max = a[1];
		if (a[0] < min) min = a[0];
		if (a[1] < min) min = a[1];
		
	}

	vector<bool> table(max+2, 0);

	for (auto a : intervals)
	{
		int m = a[0];
		int n = a[1];
		if (a[0] == a[1]) continue;

		if(!special_table.empty())
			for (auto& num : special_table)
			{
				if (m <= num && n >= num)
					num = -1;
		    }
			
		for (int i = m; i <n; i++)
			table[i] = 1;
	}

	auto pos = table.begin();

 	while (pos != table.end())
	{
		// 找1的区间，找到1后找0

		if (pos == table.begin())
			pos = find(pos, table.end(), 1);
		else
			pos = find(pos+1, table.end(), 1);

		int l = pos - table.begin();
		if (pos == table.end()) break;

		pos = find(pos + 1, table.end(), 0);
		int r = pos - table.begin();
		resault.push_back({ l,r });

		if (!special_table.empty())
			for (auto &a : special_table)
				if (l <= a && r >= a) 
					a = -1;
	}

	sort(special_table.begin(), special_table.end());
	special_table.erase(unique(special_table.begin(), special_table.end()), special_table.end());

	if (!special_table.empty())
		for (auto a : special_table)
			if (a != -1) resault.push_back({ a,a });

	return resault;*/
	sort(intervals.begin(), intervals.end());
	intervals.erase(unique(intervals.begin(), intervals.end()), intervals.end());

	if (intervals.empty() || intervals[0].empty()) return vector<vector<int>>();
	
	vector<vector<int>> resault;
	
	int i = 0;

	while (i+1 < intervals.size())
	{
		int l = intervals[i][0];
		int r = intervals[i][1];

		int next_l = intervals[i + 1][0];
		int next_r = intervals[i + 1][1];

		if (next_l <= r)//需要合并
		{
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
	vector<vector<int>> v{ {1,4},{5,6},{5,5}};

	auto a = merge(v);

	for (auto b : a)
	{
		cout << b[0] << "," << b[1] << endl;
	}
	system("pause");
}

