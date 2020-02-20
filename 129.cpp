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
	int sumNumbers(TreeNode* root) {

		if (!root) return 0;
		int sum = 0;
		int n = 0;
		get(root, sum, n);

		return sum;
	}

	void get(TreeNode* root, int& sum, int& n)
	{
		n *= 10;
		n += root->val;

		// Ò¶½ÚµãÁË
		if (!root->left && !root->right)
			sum += n;

		if (root->left)
			get(root->left, sum, n);
		if (root->right)
			get(root->right, sum, n);

		n -= root->val;
		n /= 10;

		return;
	}

};