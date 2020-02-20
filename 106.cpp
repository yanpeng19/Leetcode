// 106.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* get(vector<int>& p, vector<int>& i, int pl, int pr, int il, int ir)
{

	cout << pl << " " << pr << endl;
	cout << il << " " << ir << endl;

	if (pl > pr || pr < 0) return NULL;

	
	TreeNode* root = new TreeNode(p[pr]); // 生成根节点

	auto pos = find(i.begin() + il, i.begin() + ir, root->val); // 根节点在 中序中的位置

	int left_nums = pos - (i.begin() + il);                     // 左边节点数目
	int right_nums = i.begin()+ir-pos;                      // 右树节点数目

	if (left_nums > 0)
		root->left = get(p, i, pl, pl + left_nums-1, il, il + left_nums-1);

	if (right_nums > 0)
		root->right = get(p, i, pl + left_nums, pr-1,il+left_nums+1,ir);

	return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (postorder.empty()) return NULL;

	TreeNode* r = get(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1);
	return r;
}

int main()
{
	vector<int> i{ 9,3,15,20,7 };
	vector<int> p{ 9,15,7,20,3 };

	auto r = buildTree(i, p);

	deque<TreeNode*> d{ r };

	while (!d.empty())
	{
		auto line = d;
		d.clear();

		while (!line.empty())
		{
			auto node = line.front();
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

