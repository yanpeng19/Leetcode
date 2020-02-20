// 15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> func(vector<int> & nums)
{
	if (nums.size() < 3) return vector<vector<int>>();

	vector<vector<int>> resault;
	sort(nums.begin(), nums.end());
	
	int size = nums.size();

	for (auto i = nums.begin(); i < nums.end() - 2; i++)
	{
		if (*i > 0) break;

		for (auto j = nums.end() - 1; j > i + 1; j--)
		{
			if (*j < 0) break;

			int mid = 0 - (*j + *i);

			if (mid<*i || mid >* (nums.end() - 1))
			{
				while (j > i + 1 && *j == *(j - 1))
					j--;
				if (*j < 0) break;
				continue;
			}
				

			auto pos = binary_search(i + 1, j, mid);

			if (pos)
				resault.push_back({ *i,mid,*j });

			while (j > i + 1 && *j == *(j - 1))
				j--;
		}
		while (i < nums.end() - 2 && *i == *(i + 1))
			i++;
	}

	return resault;
}

int main()
 {
	vector<int> v{ 0,0,0,0};
	vector<vector<int>> r = func(v);

	for (auto a : r)
		for (auto b : a)
			cout << b << " ";
	cout << endl;
}
