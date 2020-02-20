// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool check(int n1, int n2, int n1_l, int n1_r, int n2_l, int n2_r);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	// 极限情况1
	if (nums1.empty())
	{
		int mid = nums2.size() / 2;
		if (nums2.size() % 2==0) return ((float)nums2[mid] + (float)nums2[mid - 1]) / 2;
		return nums2[mid];
	}
	if (nums2.empty())
	{
		int mid = nums1.size() / 2;
		if (nums1.size() % 2==0) return ((float)nums1[mid] + (float)nums1[mid - 1]) / 2;
		return nums1[mid];
	}
	int k = (nums1.size() + nums2.size()) / 2;

	// 极限情况2
	if (nums1[nums1.size() - 1] < nums2[0]|| nums2[nums2.size() - 1] < nums1[0])
	{
		if (nums1.size() == nums2.size())
		{
			if (nums1[nums1.size() - 1] < nums2[0])
			{
				float f1 = nums1[nums1.size() - 1];
				float f2 = nums2[0];

				if (k % 2 == 0) return (f1 + f2) / 2;
				return f1;
			}
		}
		else if (nums2.size() > nums1.size())
		{
			float f1 = nums2[k];
			float f2 = k + 1 < nums2.size() ? nums2[k + 1] : nums1[0];

			if (k % 2==0) return (f1+f2) / 2;
			return f1;
		}
		else
		{
			float f1 = nums1[k];
			float f2 = k + 1 < nums1.size() ? nums1[k + 1] : nums2[0];
			if (!k % 2==0) return (f1+f2) / 2;
			return f1;
		}
	}


	// 一般情况3
	// 成立公式 mid1+mid2 = k; && 
	int mid_1 = nums1.size() / 2;
	int mid_2 = mid_1 - 1 >= 0 ? mid_1 - 1 : 0;

	int n2_l = (mid_2 - 1 >= 0) ? nums2[mid_2 - 1] : INT_MIN;
	int n2_r = (mid_2 + 1 < nums2.size()) ? nums2[mid_2 + 1] : INT_MAX;
	int n1_r = (mid_1 + 1 < nums1.size()) ? nums1[mid_1 + 1] : INT_MAX;
	int n1_l = (mid_1 - 1 >= 0) ? nums1[mid_1 - 1] : INT_MIN;

	while (!check(nums1[mid_1], nums2[mid_2], n1_l, n1_r, n2_l, n2_r))
	{
		
		// 调整方向  mid_1 向左，mid_2 向右
		if (nums1[mid_1] > nums2[mid_2])
		{
			if (mid_1 == 0|| mid_2 == nums2.size() - 1)
			{
				if (k % 2 == 0) return ((float)nums1[mid_1] + (float)nums1[mid_1 - 1]) / 2;
				return nums1[mid_1];
			}


			mid_1 = mid_1 / 2;
			mid_2 = mid_2 + mid_2 / 2;

			n2_l = (mid_2 - 1 >= 0) ? nums2[mid_2 - 1] : INT_MIN;
			n2_r = (mid_2 + 1 < nums2.size()) ? nums2[mid_2 + 1] : INT_MAX;
			n1_r = (mid_1 + 1 < nums1.size()) ? nums1[mid_1 + 1] : INT_MAX;
			n1_l = (mid_1 - 1 >= 0) ? nums1[mid_1 - 1] : INT_MIN;
		}
		else // 调整方向  mid_2 向左，mid_1 向右
		{
			if (mid_2 == 0|| mid_1 == nums1.size() - 1)
			{
				if (k % 2 == 0) return ((float)nums2[mid_2] + (float)nums2[mid_2 - 1]) / 2;
				return nums2[mid_2];
			}

			mid_1 = mid_1 + mid_1 / 2;
			mid_2 = mid_2 / 2;

			n2_l = (mid_2 - 1 >= 0) ? nums2[mid_2 - 1] : INT_MIN;
			n2_r = (mid_2 + 1 < nums2.size()) ? nums2[mid_2 + 1] : INT_MAX;
			n1_r = (mid_1 + 1 < nums1.size()) ? nums1[mid_1 + 1] : INT_MAX;
			n1_l = (mid_1 - 1 >= 0) ? nums1[mid_1 - 1] : INT_MIN;
		}
	}

  	if (k % 2==0) return ((float)nums1[mid_1] + (float)nums2[mid_2]) / 2;
	else return nums1[mid_1] > nums2[mid_2] ? nums2[mid_2] : nums1[mid_1];
}

bool check(int n1, int n2, int n1_l, int n1_r, int n2_l, int n2_r)
{
	if (n1 == n2) return 1;
	if (n1 > n2&& n1<n2_r && n2>n1_l) return 1;
	if (n2 > n1&& n2 < n1_r && n1 > n2_l) return 1;
	return 0;
}


int main()
{
	vector<int> nums1{1,2};
	vector<int> nums2{-1,3};

	cout << findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
}

