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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto temp = head;
	int rank = -1;

	vector<ListNode*> v;

	while (head != NULL)
	{
		v.push_back(head);
		head = head->next;
		rank++;
	}

	int pos = (rank + 1 - n);
	if (pos == 0)
	{
		temp = temp->next;
		delete head;
		return temp;
	}

	auto l = v[pos - 1];

	if (n==1)
	{
		auto a = v[rank];
		delete a;
		l->next = NULL;
		return temp;
	}
	
	auto r = v[pos + 1];
	auto a = v[pos];
	delete a;

	l->next = r;
	return temp;
    }
};