// 82.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <deque>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
	deque<ListNode*> d;
	deque<ListNode*> r;
	auto p = head;
	while (p != NULL)
	{
		d.push_front(p);
		p = p->next;
	}

	for (int i = 0; i < d.size(); i++)
	{
		if (i + 1 < d.size() && d[i]->val == d[i + 1]->val)
		{
			while (i + 1 < d.size() && d[i]->val == d[i + 1]->val)
				i++;
		}
		else r.push_front(d[i]);
	}

	if (r.empty()) return NULL;
	ListNode* new_head = r.front();
	p = new_head;
	r.pop_front();
	
	for (auto a : r)
	{
		p->next = a;
		p = p->next;
	}
	p->next = NULL;

	return new_head;
}

int main()
{
    std::cout << "Hello World!\n";
}
