// 61.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) 
{
	if (head == NULL) return NULL;
	if (k == 0) return head;

	vector<ListNode*> v;

	auto p = head;

	while (p != NULL)
	{
		v.push_back(p);
		p = p->next;
	}
	
	k = k % v.size();
	if (k == 0) return head;

	int count = v.size();
	auto new_head = head;
	while (count-v.size() != k)
	{
		new_head = v.back();
		v.pop_back();
	}

	p = new_head;
	while (p->next != NULL)
		p = p->next;

	p->next = head;
	auto new_end = v.back();
	new_end->next = NULL;

	return new_head;
	
}

int main()
{
	ListNode* head = new ListNode(1);
	auto p = head;
	p->next = new ListNode(2);
	p = p->next;


	head = rotateRight(head, 2);
	p = head;

	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}

	system("pause");
}
