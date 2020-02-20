// 24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

//两两交换节点
ListNode* swapPairs(ListNode* head) {
	if (head == NULL) return NULL;

	ListNode* p = head;

	deque<ListNode*> d;
	vector<ListNode*> temp;

	while (p != NULL)
	{
		temp.push_back(p);
		p = p->next;

		if (temp.size() >= 2)
			while (!temp.empty())
			{
				d.push_back(temp.back());
				temp.pop_back();
			}
	}

	while (!temp.empty())
	{
		d.push_back(temp.back());
		temp.pop_back();
	}

	ListNode* resault = d[0];
	d.pop_front();
	p = resault;

	while (!d.empty())
	{
		auto t = d.front();
		d.pop_front();

		p->next = t;
		p = p->next;
	}
	p->next = NULL;

	return resault;
}


int main()
{
    std::cout << "Hello World!\n";
}

