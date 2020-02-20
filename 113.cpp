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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (!root) return vector<vector<int>>{};
		if (!root->left && !root->right && root->val == sum) return vector<vector<int>>{ {root->val}};

		vector<vector<int>> r;
		vector<int> temp{ root->val };
		if (root->left) get(root->left, sum - root->val, temp, r);
		if (root->right) get(root->right, sum - root->val, temp, r);

		return r;
	}

	void get(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& r)
	{
		if (!root->left && !root->right && root->val == sum)
		{
			temp.push_back(root->val);
			r.push_back(temp);
			temp.pop_back();
			return;
		}
		temp.push_back(root->val);
		if (root->left)  get(root->left, sum - root->val, temp, r);
		if (root->right) get(root->right, sum - root->val, temp, r);

		temp.pop_back();
		return;
	}
};