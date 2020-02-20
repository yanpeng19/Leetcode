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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>();

        vector<vector<int>> r;
        deque<TreeNode*> d{root};

        while(!d.empty())
        {
            auto line = d;
            d.clear();
            vector<int> temp;
            while(!line.empty())
            {
                auto node = line.front();
                line.pop_front();
                if(node)
                {
                    temp.push_back(node->val);
                    d.push_back(node->left);
                    d.push_back(node->right);
                }
            }
            if(!temp.empty()) r.push_back(temp);
        }
        reverse(r.begin(),r.end());
        return r;
    }
};