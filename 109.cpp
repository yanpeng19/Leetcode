// 109.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedListToBST(ListNode* head)
{
	if (!head) return NULL;

	ListNode* pre = head;
	ListNode* slow = head;
	ListNode* fast = head;

	while(fast->next)
	{
		if (fast->next)
			fast = fast->next;
		if (fast->next)
			fast = fast->next;
		slow = slow->next;
		if (slow != head->next)
			pre = pre->next;
	}
	pre->next = NULL;

	TreeNode* root = new TreeNode(slow->val);
	if (slow != head) root->left = sortedListToBST(head);
	if (slow->next) root->right = sortedListToBST(slow->next);
	return root;
}

int main()
{
	ListNode* head = new ListNode(-10);
	auto p = head;
	p->next = new ListNode(-3);
	p = p->next;
	p->next = new ListNode(0);
	p = p->next;
	p->next = new ListNode(5);
	p = p->next;
	p->next = new ListNode(9);
	p = p->next;

	auto a = sortedListToBST(head);
	system("pause");
}

