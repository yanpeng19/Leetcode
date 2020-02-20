// 21.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	if (l1 == NULL && l2 == NULL) return l1;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode* new_head;

	if (l1->val < l2->val)
	{
		new_head = l1;
		l1 = l1->next;
	}
	else
	{
		new_head = l2;
		l2 = l2->next;
	}

	auto p = new_head;
	

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			p->next = l1;
			p = l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			p = l2;
			l2 = l2->next;
		}
	}

	while (l1)
	{
		p->next = l1;
		p = p->next;
		l1 = l1->next;
	}

	while (l2)
	{
		p->next = l2;
		p = p->next;
		l2 = l2->next;
	}

	return new_head;
}


int main()
{
	ListNode* l1 = new ListNode(-9);
	l1->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(7);

	auto r = mergeTwoLists(l1, l2);
	while (r)
	{
		cout << r->val << endl;
		r = r->next;
	}
		

    std::cout << "Hello World!\n";
}

