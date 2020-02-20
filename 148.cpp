// 148.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge_sort(ListNode* head,int size)
{
	if (!head) return NULL;
	if (size == 1) return head;
	int mid = size / 2;

	int n = 0;
	ListNode* atf = head;
	ListNode* p = NULL;

	while (n!=mid)
	{
		if (!p) p = atf;
		else p = p->next;

		atf = atf->next;
		n++;
	}
		
	p->next = NULL;
	
	
	// 分
	head = merge_sort(head,n);
	atf = merge_sort(atf, size - n);

	// 合
	ListNode* new_head = new ListNode(0);
	p = new_head;

	while (head && atf)
	{
		if (head->val < atf->val)
		{
			p->next = head;
			p = p->next;
			head = head->next;
		}
		else
		{
			p->next = atf;
			p = p->next;
			atf = atf->next;
		}
	}

	while (head)
	{
		p->next = head;
		p = head;
		head = head->next;
	}

	while (atf)
	{
		p->next = atf;
		p = atf;
		atf = atf->next;
	}
	p = new_head->next;
	delete new_head;

	return p;
}

ListNode* sortList(ListNode* head) 
{
	
	if (!head) return NULL;
	auto p = head;
	int n = 0;
	while (p)
	{
		n++;
		p = p->next;
	}

	return merge_sort(head,n);

}

int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);

	head = sortList(head);

	auto p = head;
	while (p)
	{
		cout << p->val << endl;
		p = p->next;
	}

	system("pause");
}

