/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;

        deque<ListNode*> d;
        auto p = head;

        while(p)
        {
            bool f= 0;
            for(int i =0;i<d.size();i++)
            {
                if(p->val<=d[i]->val)
                {
                    d.insert(d.begin()+i,p);
                    f = 1;
                    break;
                }
            }
            if(f==0) d.push_back(p);
            p=p->next;
        }

        // for(auto a : d)
        // cout << a->val<< " ";

        p = d[0];
        head = d[0];
        for(int i = 1;i<d.size();i++)
        {
            p->next = d[i];
            p = d[i];
        }
        p->next = NULL;
        
        return head;
    }
};