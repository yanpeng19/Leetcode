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
    bool isSymmetric(TreeNode* root) {
       // if(!root) return 1;
        // if(!root->left&&!root->right) return 1;

        // // 左节点使用左->中->右次序遍历
        // // 右节点使用右->中->左次序遍历 

        // deque<TreeNode*> l{root->left};
        // deque<TreeNode*> r{root->right};

        // while(!l.empty()&&!r.empty())
        // {
        //     if(l.size()!=r.size()) return 0;

        //     auto line_l = l;
        //     auto line_r = r;

        //     l.clear();
        //     r.clear();

        //     //生成左右两边的 当前行vector
        //     vector<int> v1;
        //     vector<int> v2;

        //     while(!line_l.empty())
        //     {
        //         auto node = line_l.front();
        //         line_l.pop_front();

        //         if(node)
        //         {
        //             v1.push_back(node->val);
        //             l.push_back(node->left);
        //             l.push_back(node->right);
        //         }
        //         else v1.push_back(-5000);
        //     }

        //     while(!line_r.empty())
        //     {
        //         auto node = line_r.back();
        //         line_r.pop_back();

        //         if(node)
        //         {
        //             v2.push_back(node->val);
        //             r.push_front(node->right);
        //             r.push_front(node->left);
        //         }
        //         else v2.push_back(-5000);
        //     }
        //     // for(auto a:v1)
        //     // cout << a << " ";
        //     // cout <<endl;

        //     // for(auto a:v2)
        //     // cout << a << " ";
        //     // cout <<endl;

        //     if(v1!=v2) return 0;
        // }

        // return 1;
        if(!root) return 1;
        if(!root->left&&!root->right) return 1;
        if(!root->left||!root->right) return 0;
        auto l = root->left;
        auto r = root->right;
        if(l->val!=r->val) return 0;

        return same(l->left,r->right)&&same(l->right,r->left);
    }

    bool same(TreeNode* l,TreeNode* r)
    {
        if(!l&&!r) return 1;
        if(!l||!r) return 0;

        if(l->val!=r->val) return 0;

        return same(l->left,r->right)&&same(l->right,r->left);

    }

};