// 116.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
	if (!root) return root;

	deque<Node*> d{ root };

	while (!d.empty())
	{
		auto line = d;
		d.clear();

		Node* n = NULL;
		for (int i = 0; i < line.size(); i++)
		{
			if (n == NULL) n = line[i];
			else
			{
				n->next = line[i];
				n = n->next;
			}
		}

		while (!line.empty())
		{
			auto node = line.front();
			line.pop_front();
			if (node)
			{
				cout << node->val << " ";
				d.push_back(node->left);
				d.push_back(node->right);
			}
			cout << endl;
		}

	}

	return root;
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);

	auto l = root->left;
	auto r = root->right;

	l->left = new Node(4);
	l->right = new Node(5);
	r->left = new Node(6);
	r->right = new Node(7);

	auto a = connect(root);

	system("pause");
}

