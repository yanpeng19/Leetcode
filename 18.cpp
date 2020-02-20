// 18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> func(vector<int>& nums, int target)
{
	if (nums.size() < 4) return vector<vector<int>>();

	vector<vector<int>> resault;
	sort(nums.begin(), nums.end());

	//int size = nums.size();

	for (auto k = nums.begin(); k < nums.end() - 3; k++)
	{
		for (auto i = k+1; i < nums.end() - 2; i++)
		{
			for (auto j = nums.end() - 1; j > i + 1; j--)
			{
				int mid = target - (*j + *i + *k);

				if (mid<*i || mid >* (nums.end() - 1))
				{
					while (j > i + 1 && *j == *(j - 1))
						j--;
					continue;
				}

				auto pos = binary_search(i + 1, j, mid);

				if (pos)
					resault.push_back({ *k,*i,mid,*j });

				while (j > i + 1 && *j == *(j - 1))
					j--;
			}
			while (i < nums.end() - 2 && *i == *(i + 1))
				i++;
		}
		while (k < nums.end() - 3 && *k == *(k + 1))
			k++;
	}


	return resault;
}

int main()
{
	vector<int> v{ 0,2,-10,-4,1,-7,-4,9,1,-3,-4,-6,-7,-6,-2,7,-5,2 };
	vector<vector<int>> r = func(v,-29);

	for (auto a : r)
		for (auto b : a)
			cout << b << " ";
	cout << endl;
}
