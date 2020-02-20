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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n||!head) return head;

        vector<ListNode*> v;
        int i = 0;
        
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        auto p = new_head;
        auto l = new_head;

        while(p)
        {
            p=p->next;
            i++;

            if(i<m)
            {
                l->next=p;
                l = l->next;
            }
                
            else if(i>=m&&i<=n)
                v.push_back(p);
            else
            {
                while(!v.empty())
                {
                    auto temp = v.back();
                    v.pop_back();
                    l->next = temp;
                    l = l->next;
                }
                l->next = p;
                l = l->next;
            }
        }

        p = new_head->next;
        delete(new_head);
        return p;
    }
};