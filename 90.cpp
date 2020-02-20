// 90.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) 
{
	if (nums.empty()) return vector<vector<int>>{ {}};

	sort(nums.begin(), nums.end());
	vector<vector<int>> r;


	for (int i = 0; i < nums.size(); i++)
	{
		
		if (r.empty()) r.push_back(vector<int>{nums[i]});

		else
		{
	
			vector<vector<int>> temp = r;
			for (auto a : temp)
			{
				a.push_back(nums[i]);
				r.push_back(a);
			}
			r.push_back(vector<int>{nums[i]});

		}
	}
	
	sort(r.begin(), r.end());
	r.erase(unique(r.begin(), r.end()), r.end());
	r.push_back(vector<int>{});

	/*for (auto a : r)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;*/

	return r;
}

int main()
{
	vector<int> v{ 4,4,4,1,4 };
	subsetsWithDup(v);
}


