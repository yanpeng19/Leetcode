// 128.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;

int longestConsecutive(vector<int>& nums) 
{
	unordered_set<int> s(nums.begin(), nums.end());

	int max = 1;
	

	for (auto a : s)
	{
		int x = a;
		int n = 1;
		while (s.find(++x) != s.end())
			n++;
		if (n > max) max = n;
	}


	return max;
}

int main()
{
	vector<int> v{ 100, 4, 200, 1, 3, 2 };
	cout << longestConsecutive(v);
	system("pause");
}
