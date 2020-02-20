// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p=NULL;
		ListNode* resault=NULL;

		int flag = 0;

		ListNode* l = l1;
		ListNode* r = l2;

		while (l != NULL && r != NULL)
		{
			int temp = l->val + r->val + flag;

			l = l->next;
			r = r->next;

			if (temp > 9) flag = 1;
			else flag = 0;

			ListNode* list_temp = new ListNode(temp % 10);
			if (p == NULL)
			{
				p = list_temp;
				resault = p;
			}
			else
			{
				p->next = list_temp;
				p = list_temp;
			}
		}

		while (l != NULL)
		{
			int temp = l->val + flag;
			l = l->next;

			if (temp > 9) flag = 1;
			else flag = 0;

			ListNode* list_temp = new ListNode(temp%10);
			p->next = list_temp;
			p = list_temp;
		}

		while (r != NULL)
		{
			int temp = r->val + flag;
			r = r->next;

			if (temp > 9) flag = 1;
			else flag = 0;

			ListNode* list_temp = new ListNode(temp % 10);
			p->next = list_temp;
			p = list_temp;
		}

		if (flag != 0)
		{
			ListNode* list_temp = new ListNode(1);
			p->next = list_temp;
			p = list_temp;
		}

		return resault;
	}
};

vector<int> twoSum(vector<int>& nums, int target)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; i < nums.size(); j++)
		{
			if ((nums[i] + nums[j]) == target)
				return vector<int>{i, j};
		}
	}
	return vector<int>(0, 0);
}

int main()
{
	ListNode *l1 = new ListNode(0);

	ListNode* l2 = new ListNode(1);
	l2->next = new ListNode(8);

	Solution s;
	
	ListNode* l3 = s.addTwoNumbers(l1, l2);

	system("pause");
	return 0;
}
