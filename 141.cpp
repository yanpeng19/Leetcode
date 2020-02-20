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
	bool hasCycle(ListNode* head) {
		if (!head) return 0;

		auto p = head;

		while (p->next)
		{
			if (p->val == -235420) return 1;
			else
			{
				p->val = -235420;
				p = p->next;
			}
		}

		return 0;
	}
};