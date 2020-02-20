// 99.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode* root) 
{
	if (!root) return;
	
	vector<TreeNode*> v;

	vector<TreeNode*> l;
	vector<TreeNode*> r;


	while (root)
	{
		if (root->left && root->left->val > root->val)
		{
			v.push_back(root);
			v.push_back(root->left);
			swap(root->val, root->left->val);
		}

		l.push_back(root);
		root = root->left;
	}


	while (!l.empty())
	{
		auto node = l.back();
		l.pop_back();

		if (node&&node->left&&node->left->val>node->val)
		{
			p.push_back(node);
			v.push_back(node->left);
		}
		else if (node && node->right && node->right->val < node->val)
		{
			p.push_back(node);
			v.push_back(node->right);
		}
		

		if (node->right)
			r.push_back(node->right);

		if (!r.empty())
		{
			node = r.back();
			r.pop_back();

			l.push_back(node);
			node = node->left;
			while (node)
			{
				l.push_back(node);
				node = node->left;
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (v.size() == 1)
		swap(v.back()->val, p.back()->val);
	else
		swap(v.back()->val, p[0]->val);
	return;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->left->right = new TreeNode(2);
	recoverTree(root);
}
