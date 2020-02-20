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
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        if(high(root)!=-1) return 1;
        else return 0;
    }

    int high(TreeNode* root)
    {
        if(!root) return 0;
        int l = high(root->left);
        int r = high(root->right);
        if(l==-1||r==-1) return -1;

        int high =0;

        if(l>r)
        {
            if(l-r>1) return -1;
            else return l+1;
        }
        else
        {
            if(r-l>1) return -1;
            else return r+1;
        }

    }
};