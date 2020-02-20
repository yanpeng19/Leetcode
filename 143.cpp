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
	void reorderList(ListNode* head) {
		if (!head) return;

		deque<ListNode*> d;
		auto p = head->next;

		while (p)
		{
			d.push_back(p);
			p = p->next;
		}
		p = head;

		while (!d.empty())
		{
			auto node = d.back();
			d.pop_back();
			p->next = node;
			p = node;

			if (!d.empty())
			{
				node = d.front();
				d.pop_front();
				p->next = node;
				p = node;
			}
		}
		p->next = NULL;

		return;
	}
};