// 98.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

bool isValidBST(TreeNode* root)
{
	if (!root) return 1;

	vector<TreeNode*> l;
	vector<TreeNode*> r;

	while (root)
	{
		l.push_back(root);
		root = root->left;
	}

	int min = 0;
	bool f = 0;

	while (!l.empty())
	{
		auto node = l.back();
		l.pop_back();

		if (!f)
		{
			f = 1;
			min = node->val;
		}
		else
		{
			if (node->val <= min) return 0;
			else
			{
				min = node->val;
				cout << node->val << " ";
			}
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

	return 1;
}



int main()
{
	TreeNode* root = new TreeNode(5);
	auto p = root;
	p->left = new TreeNode(1);
	p->right = new TreeNode(4);
	p = p->right;
	p->left = new TreeNode(3);
	p->right = new TreeNode(6);

	cout << isValidBST(root);
	system("pause");
}

