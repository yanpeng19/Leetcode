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
    void flatten(TreeNode* root) {
        
        if(!root) return;

        auto p = root;
        vector<TreeNode*> l;
        vector<TreeNode*> r;
        deque<TreeNode*> tree;

        while(p)
        {
            tree.push_back(p);
            l.push_back(p);
            p = p->left;
        }

        while(!l.empty())
        {
            auto node = l.back();
            l.pop_back();

            if(node->right)
            {
                node = node->right;
                tree.push_back(node);
                l.push_back(node);
                while(node->left)
                {
                    node = node->left;
                    tree.push_back(node);
                    l.push_back(node);
                }
            }
        }

        tree.pop_front();
        p = root;
        
        for(int i = 0;i<tree.size();i++)
        {
            p->left = NULL;
            p->right = tree[i];
            p = p->right;
        }
        p->left = NULL;
        p->right = NULL;

        return;
    }
};