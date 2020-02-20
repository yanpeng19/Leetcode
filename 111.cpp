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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return get_min(root);
    }

    int get_min(TreeNode* root)
    {
        if(!root->left&&!root->right) return 1;
        if(!root->left) return get_min(root->right)+1;
        if(!root->right) return get_min(root->left)+1;

        return min(get_min(root->left),get_min(root->right))+1;
    }
};