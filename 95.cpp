// 95.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int n) 
{
	if (n == 0) return vector<TreeNode*>();
	if (n == 1) return vector<TreeNode*>{new TreeNode(1)};

	// 生成全排列，并且判定是否合法
	// 作为完全二叉堆看待， root= 0; root->left = 0*2  root->right = 0*2+1
	// 节点 y 的的 rank = r;  y 的左子 y*2 右子 y * 2+1

	vector<vector<int>> v{ { 1} };

	for (int i = 2; i <= n; i++)
	{
		vector<vector<int>> t(v);
		v.clear();
		
		for (auto a : t)
		{
			for (int j = 0; j <= a.size(); j++)
			{
				auto temp = a;
				temp.insert(temp.begin() + j, i);
				if (a.size() >= 2&&j>0&&j<a.size())
				{
					// 中间位置和 末尾位置判断合法性
					int p = 0;
					int s = 0;
		
					p = a[j - 1];
					s = a[j];
					
					if (i>p&&s<p) continue;

					if ((i<p && s>p) || (i > p&& s < p)) 
						j++;
				}
				v.push_back(temp);
			}
		}
	}

	sort(v.begin(), v.end());
	for (auto a : v)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	
	//根据序列生成完全二叉堆
	vector<vector<int>> tree_stack;
	for (int i = 0; i < v.size(); i++)
	{
		vector<int> temp{ v[i][0] };
		for (int j = 1; j < v[i].size(); j++)
		{
			int n = v[i][j];

			int rank = 0;
			if (n < temp[0])
				rank = 1;
			else rank = 2;

			if(temp.size() <= rank)
			{
				while (temp.size() <= rank)
					temp.push_back(0);

				temp[rank] = n;
			}
			else
			{
				while (temp[rank] != 0)
				{
					if (n < temp[rank]) rank = rank * 2 + 1;
					else rank = rank * 2 + 2;

					while (temp.size() <= rank)
						temp.push_back(0);
				}
				temp[rank] = n;
			}
		}

		tree_stack.push_back(temp);
	}
	sort(tree_stack.begin(), tree_stack.end());
	tree_stack.erase(unique(tree_stack.begin(), tree_stack.end()), tree_stack.end());

	// 使用完全二叉堆 构建 树
	vector<TreeNode*> r;

	for (int i = 0; i < tree_stack.size(); i++)
	{
		TreeNode* root = new TreeNode(tree_stack[i][0]);
		for (int j = 1; j < tree_stack[i].size(); j++)
		{
			if (tree_stack[i][j] != 0)
			{
				int num = tree_stack[i][j];
				int rank = 0;

				TreeNode* node = new TreeNode(tree_stack[i][j]);
				auto p = root;

				while(j != rank*2 + 1 && j != rank*2 + 2)
				{
					if (num < p->val)
					{
						p = p->left;
						rank = rank * 2 + 1;
					}
					else
					{
						p = p->right;
						rank = rank * 2 + 2;
					}
				}
				if (j == rank*2 + 1) p->left = node;
				else p->right = node;
			}
		}
		r.push_back(root);
	}
	

	return r;
}

int main()
{
	auto v = generateTrees(5);
	//for (auto a : v)
	//{
	//	deque<TreeNode*> d;
	//	d.push_back(a);


	//	while (!d.empty())
	//	{
	//		auto line = d;
	//		d.clear();

	//		while (!line.empty())
	//		{
	//			auto node = line.back();
	//			line.pop_back();
	//			if (node)
	//			{
	//				cout << node->val << " ";
	//				d.push_back(node->left);
	//				d.push_back(node->right);
	//			}
	//			else cout << " ";
	//		}
	//		cout << endl;
	//	}
	//}

	vector<vector<int>> v1{ {5,4,0,3,0,2,0,1},{4,3,5,2,0,0,0,1},{5,3,0,2,4,1},{3,2,5,1,0,4},{3,2,4,1,0,0,5},{5,4,0,2,0,1,3},{4,2,5,1,3},{5,2,0,1,4,0,0,3},{2,1,5,0,0,4,0,3},{2,1,4,0,0,3,5},{5,2,0,1,3,0,0,0,4},{2,1,5,0,0,3,0,0,4},{2,1,3,0,0,0,5,4},{2,1,3,0,0,0,4,0,5},{5,4,0,3,0,1,0,0,2},{4,3,5,1,0,0,0,0,2},{5,3,0,1,4,0,2},{3,1,5,0,2,4},{3,1,4,0,2,0,5},{5,3,0,1,4,0,2},{3,1,5,0,2,4},{3,1,4,0,2,0,5},{5,4,0,1,0,0,3,2},{4,1,5,0,3,0,0,2},{5,1,0,0,4,3,0,2},{1,0,5,4,0,3,0,2},{1,0,4,3,5,2},{5,1,0,0,3,2,4},{1,0,5,3,0,2,4},{1,0,3,2,5,0,0,4},{1,0,3,2,4,0,0,0,5},{5,4,0,1,0,0,2,0,3},{4,1,5,0,2,0,0,0,3},{5,1,0,0,4,2,0,0,3},{1,0,5,4,0,2,0,0,3},{1,0,4,2,5,0,3},{5,1,0,0,2,0,4,3},{1,0,5,2,0,0,4,3},{1,0,2,0,5,4,0,3},{1,0,2,0,4,3,5},{5,1,0,0,2,0,3,0,4},{1,0,5,2,0,0,3,0,4},{1,0,2,0,5,3,0,0,4},{1,0,2,0,3,0,5,4},{1,0,2,0,3,0,4,0,5} };
	vector<vector<int>> v2{ {1,0,2,0,3,0,4,0,5},{1,0,2,0,3,0,5,4},{1,0,2,0,4,3,5},{1,0,2,0,5,3,0,0,4},{1,0,2,0,5,4,0,3},{1,0,3,2,4,0,0,0,5},{1,0,3,2,5,0,0,4},{1,0,4,2,5,0,3},{1,0,4,3,5,2},{1,0,5,2,0,0,3,0,4},{1,0,5,2,0,0,4,3},{1,0,5,3,0,2,4},{1,0,5,4,0,2,0,0,3},{1,0,5,4,0,3,0,2},{2,1,3,0,0,0,4,0,5},{2,1,3,0,0,0,5,4},{2,1,4,0,0,3,5},{2,1,5,0,0,3,0,0,4},{2,1,5,0,0,4,0,3},{3,1,4,0,2,0,5},{3,1,5,0,2,4},{3,2,4,1,0,0,5},{3,2,5,1,0,4},{4,1,5,0,2,0,0,0,3},{4,1,5,0,3,0,0,2},{4,2,5,1,3},{4,3,5,1,0,0,0,0,2},{4,3,5,2,0,0,0,1},{5,1,0,0,2,0,3,0,4},{5,1,0,0,2,0,4,3},{5,1,0,0,3,2,4},{5,1,0,0,4,2,0,0,3},{5,1,0,0,4,3,0,2},{5,2,0,1,3,0,0,0,4},{5,2,0,1,4,0,0,3},{5,3,0,1,4,0,2},{5,3,0,2,4,1},{5,4,0,1,0,0,2,0,3},{5,4,0,1,0,0,3,2},{5,4,0,2,0,1,3},{5,4,0,3,0,1,0,0,2},{5,4,0,3,0,2,0,1} };

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v2.size(); i++)
	{
		cout << "v1: ";
		for (auto a : v1[i])
		{
			cout << a << " ";
		}
		cout << endl;

		cout << "v2: ";
		for (auto a : v2[i])
		{
			cout << a << " ";
		}
		cout << endl;
		cout << endl;

		if (v1[i] != v2[i])
			cout << endl;
	}


	cout << endl;
}
