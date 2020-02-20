// 108.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* get(vector<int>& nums, int l, int r)
{

	int rank = l+(r - l) / 2;
	TreeNode* root = new TreeNode(nums[rank]);

	if ( rank - 1 >= l)
 		root->left = get(nums, l, rank - 1);
	if ( rank + 1 <= r)
		root->right = get(nums, rank + 1, r);

	return root;
}


TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.empty()) return NULL;
	return get(nums, 0, nums.size() - 1);
}

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	auto a = sortedArrayToBST(v);
	system("pause");
}
