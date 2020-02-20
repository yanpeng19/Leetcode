// 88.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	int i = 0;
	int j = 0;
	vector<int> resault;

	while (j < nums2.size())
	{
		while (nums2[j] >= nums1[i] && i < m)
		{
			resault.push_back(nums1[i]);
			i++;
		}
		resault.push_back(nums2[j]);
		j++;
	}
	while (i < m)
		resault.push_back(nums1[i++]);
	
	nums1 = resault;
}

int main()
{
	vector<int> v1{ 1,2,3,0,0,0 };
	vector<int> v2{ 2,5,6 };

	merge(v1,3, v2,3);

	for (auto a : v1)
		cout << a << " ";
	cout << endl;
}

