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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

		if (!root) return vector<vector<int>>();
		vector<vector<int>> r;
		bool f = 0;
		deque<TreeNode*> d{ root };

		while (!d.empty())
		{
			auto line = d;
			d.clear();
			vector<int> temp;

			if (!f)
			{
				f = 1;
				while (!line.empty())
				{
					auto node = line.front();
					line.pop_front();
					if (node)
					{
						temp.push_back(node->val);
						d.push_back(node->left);
						d.push_back(node->right);
					}
				}

			}
			else
			{
				f = 0;
				while (!line.empty())
				{
					auto node = line.back();
					line.pop_back();
					if (node)
					{
						temp.push_back(node->val);
						d.push_front(node->right);
						d.push_front(node->left);
					}
				}
			}
			if (!temp.empty()) r.push_back(temp);

		}

		return r;
	}
};