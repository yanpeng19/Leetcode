// 23.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	//if (lists.empty()) return NULL;
	//if (lists.size() < 2) return lists[0];

	//vector<int> vr; // 存储有效链表的rank
	//ListNode* resault =  new ListNode(-1);  // 虚拟头部 最后删除
	//ListNode* p = resault;

	//int rank = 0;
	//for (auto a : lists)
	//{
	//	if (a != NULL)
	//	{
	//		vr.push_back(rank);//记录合法的list rank
	//	}
	//	rank++;
	//}

	//if(rank==0) return NULL;

	//int true_list = vr.size();

	//while (true_list>0)
	//{
	//	int min = INT_MIN; //记录最小值
	//	int min_node_rank =-1;
	//	bool flag = 1;

	//	// 复杂度n 每次缩减1个单位，总共的复杂度是 n^n
	//	for (int i = 0; i < vr.size();i++)
	//	{
	//		if (vr[i] == -1) continue;

	//		if (min == INT_MIN && flag)
	//		{
	//			min = lists[vr[i]]->val;
	//			min_node_rank = i;
	//			flag = 0;
	//			continue;
	//		}

	//		if (lists[vr[i]]->val < min)
	//		{
	//			min = lists[vr[i]]->val;
	//			min_node_rank = i;
	//		}
	//		flag = 0;
	//	}

	//	p->next = lists[vr[min_node_rank]];
	//	p = p->next;

	//	auto l = lists[vr[min_node_rank]];
	//	l = l->next;
	//	lists[vr[min_node_rank]] = l;

	//	if (!l)
	//	{
	//		vr[min_node_rank]= -1; // 从有效节点记录中删除
	//		true_list--;
	//	}
	//}

	//p = resault;
	//resault = resault->next;
	//delete p;
	if (lists.empty()) return NULL;
	vector<ListNode*> v;

	for (auto a : lists)
	{
		while (a != NULL)
		{
			v.push_back(a);
			a = a->next;
		}
	}
	if (v.empty()) return NULL;

	sort(v.begin(), v.end(), [](ListNode* l1, ListNode* l2) {return l1->val < l2->val; });
	ListNode* resault = *v.begin();
	ListNode* p = resault;
	for (int i = 0; i < v.size(); i++)
	{
		p->next = v[i];
		p = p->next;
	}
	p->next = NULL;

	return resault;
}


int main()
{
	vector<ListNode*> v;
	ListNode* temp;

	ListNode* l1 = new ListNode(-1);
	temp = l1;
	temp->next = new ListNode(5);
	temp = temp->next;
	temp->next = new ListNode(11);
	temp = temp->next;

	ListNode* l2 = new ListNode(1);
	temp = l2;
	temp->next = new ListNode(3);
	temp = temp->next;
	temp->next = new ListNode(4);
	temp = temp->next;

	ListNode* l3 = new ListNode(6);
	l3->next = new ListNode(10);
	
	/*v.push_back(NULL);
	v.push_back(new ListNode(1));*/
	/*v.push_back(l1);
	v.push_back(l2);
	v.push_back(l3);*/
	v.push_back(NULL);
	v.push_back(l1);
	v.push_back(NULL);
	v.push_back(l3);

	temp = mergeKLists(v);

	while (temp != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}

}


