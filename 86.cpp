// 86.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* partition(ListNode* head, int x) 
{
	if (head == NULL) return NULL;

	auto new_head = new ListNode(0);
	auto r = new_head;
	auto  p = head;
	ListNode* back = NULL;
	auto back_p = back;


	while (p)
	{
		if (p->val < x)
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}
		else
		{
			// back中
			if (!back)
			{
				back = back_p = p;
			}
			else
			{
				back_p->next = p;
				back_p = back_p->next;
			}
			p = p->next;
		}
	}

	if (!back)
	{
		p = new_head->next;
		delete(new_head);
		return p;
	}

	back_p->next = NULL;
	back_p = back;


	while(back_p)
	{
		r->next = back_p;
		r = r->next;
		back_p = back_p->next;
	}

	r->next = NULL;
	p = new_head->next;
	delete(new_head);
	
	return p;
}

int main()
{
	ListNode* h = new ListNode(1);
	auto p = h;

	p->next = new ListNode(4);
	p = p->next;

	p->next = new ListNode(3);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(2);
	p = p->next;

	auto a = partition(h,3);
	while (a)
	{
		cout << a->val << " ";
		a = a->next;
	}
	cout << endl;
}

