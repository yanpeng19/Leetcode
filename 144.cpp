/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		if (!root) return v;

		deque<TreeNode*> d;
		auto node = root;

		while (node)
		{
			v.push_back(node->val);
			d.push_back(node->right);
			node = node->left;
		}

		while (!d.empty())
		{
			auto node = d.back();
			d.pop_back();

			if (node)
			{
				while (node)
				{
					v.push_back(node->val);
					d.push_back(node->right);
					node = node->left;
				}
			}
		}
		return v;

	}
};