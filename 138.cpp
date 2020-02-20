/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {

		if (!head) return NULL;

		auto p = head;

		while (p)
		{
			auto node = new Node(p->val, p->next, NULL);
			p->next = node;
			p = node->next;
		}



		p = head;

		while (p)
		{
			auto n = p->next;
			if (p->random)
				n->random = p->random->next;
			p = p->next->next;
		}


		auto new_head = head->next;
		auto bef = new_head;
		auto old = head;

		p = new_head->next;

		while (p)
		{
			old->next = p;
			old = p;
			p = p->next;
			bef->next = p;
			bef = bef->next;

			p = p->next;
		}
		old->next = NULL;

		// t = new_head;

		 // while(t)
		 // {
		 //     cout << t << ":";
		 //     //cout << t->val<< " ";
		 //     t= t->next;
		 // }


		return new_head;
	}
};