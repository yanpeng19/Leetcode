// 83.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
	if (head == NULL) return NULL;
	auto p = head->next;
	auto r = head;

	while (p != NULL)
	{
		if (p->val == r->val)
			p = p->next;
		else
		{
			r->next = p;
			r = r->next;
			p = p->next;
		}
	}
	r->next = NULL;
	return head;
}

int main()
{
    std::cout << "Hello World!\n";
}
