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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> vr;
        vector<TreeNode*> vl;

        vector<int> r;
        // 左根右
        if(!root) return r;
       
       auto p = root;
       while(p)
       {
           vl.push_back(p);
           vr.push_back(p->right);
           p = p->left;
       }

       while(!vl.empty())
       {
           auto p =vl.back();
           vl.pop_back();
           r.push_back(p->val);

           if(!vr.empty())
           {
               p = vr.back();
               vr.pop_back();
               
                while(p)
                 {
                    vl.push_back(p);
                    vr.push_back(p->right);
                    p = p->left;
                }
           }
       }


       return r;
    }
};