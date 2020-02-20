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
	ListNode* detectCycle(ListNode* head) {
		if (!head) return NULL;

		set<ListNode*> s;

		auto p = head;

		while (p)
		{
			auto pos = s.find(p);
			if (pos != s.end())
				return *pos;
			s.insert(p);
			p = p->next;
		}

		return NULL;
	}
};