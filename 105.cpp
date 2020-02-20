// 105.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* get(vector<int>& p,vector<int>& i,int p_l,int p_r,int i_l,int i_r)
{
	// 函数功能，根据 p 的rank   l和r 确定树的宽度和内容，然后生成一个二叉树
	// 1.首先通过先序确认根节点  root = p_l +1;
	// 2.然后从中序中 确认 左子树和右子树的 节点数目 n,m     n =p[p_l+1] 在i 中的 rank 
	// 3.将问题分解为 左子树 和右子树的递归

	// 递归基础  当r-l = 1的时候 生成并返回节点即可
	// 如何判断是否为空节点？ p_r-p_l = 0;
	cout << p_l << " " << p_r << endl;
	cout << i_l << " " << i_r << endl;

	if (p_l>p_r||p_l>=p.size()) return NULL;


	TreeNode* root = new TreeNode(p[p_l]); // 生成根节点

	auto pos = find(i.begin()+i_l, i.begin()+i_r, root->val); // 根节点在 中序中的位置
	int left_nums = pos - (i.begin() + i_l);                 // 左边节点数目
	int right_nums = i.begin() + i_r - pos;                  // 右树节点数目

	if (left_nums > 0)
		root->left = get(p, i, p_l + 1, p_l + left_nums, i_l, i_l + left_nums-1);
		
	if (right_nums >0)
		root->right = get(p, i, p_l + left_nums + 1, p_r, i_r - right_nums+1, i_r);

	return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	if (preorder.empty()) return NULL;

	TreeNode* r = get(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
	return r;
}

int main()
{
	vector<int> p{ 3,9,20,15,7};
	vector<int> i{ 9,3,15,20,7 };

	auto r = buildTree(p, i);
	
	deque<TreeNode*> d{ r };
	while (!d.empty())
	{
		deque<TreeNode*> line = d;
		d.clear();

		while (!line.empty())
		{
			TreeNode* node = line.front();
			line.pop_front();

			if (node)
			{
				d.push_back(node->left);
				d.push_back(node->right);
				cout << node->val << " ";
			}
		}

	}

	system("pause");
}


