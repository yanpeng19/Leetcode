// 25.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//k个节点交换
ListNode* reverseKGroup(ListNode* head, int k)
{
	if (!head) return NULL;
	ListNode* resault=NULL; // 结果节点
	ListNode* inserter = NULL; // 插入用的节点
	ListNode* p = head;    // 遍历指针
	
	deque<ListNode*> temp;

	while (p)
	{
		temp.push_back(p);
		p = p->next;

		if (temp.size() >= k)
		{
			while (!temp.empty())
			{
				auto t = temp.back();
				temp.pop_back();

				if (!resault)
				{
					resault = t;
					inserter = resault;
					continue;
				}

				inserter->next = t;
				inserter = inserter->next;
			}
		}
	}

	while (!temp.empty())
	{
		auto t = temp.front();
		temp.pop_front();

		if (!resault)
		{
			resault = t;
			inserter = resault;
			continue;
		}
		
		inserter->next = t;
		inserter = inserter->next;
	}

	inserter->next = NULL;

	return resault;
}

int main()
{
	ListNode* l = new ListNode(1);
	l->next = new ListNode(2);

	auto a = reverseKGroup(l, 2);
	while (a)
	{
		cout << a->val << endl;
		a = a->next;
	}
}
