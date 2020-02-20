// 123.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{

	//if (prices.empty()||prices.size()==1) return 0;

	//int k = 1;
	//for (; k < prices.size(); k++)
	//	if (prices[k] > prices[k - 1]) break;
	//if (k == prices.size()) return 0;

	//int max = 0;
	//int r = 0;

	//for (int i = 1; i < prices.size(); i++)
	//{
	//	int before = 0;
	//	int after = 0;
	//	int max = prices[i];


	//	// max (0~j)
	//	for (int j = i-1; j >= 0; j--)
	//	{
	//		if (prices[j] < max)
	//		{
	//			if(before < max - prices[j])
	//				before = max - prices[j];
	//		}
	//		else max = prices[j];
	//	}
	//	/*cout << "rank is : " << i << endl;
	//	cout << "before is" << before << endl;*/

	//	max = prices[prices.size() - 1];
	//	for (int j = prices.size()-2; j>i; j--)
	//	{
	//		if (prices[j] < max)
	//		{
	//			if(after < max - prices[j])
	//				after = max - prices[j];
	//		}
	//		else max = prices[j];
	//	}

	//	if ((before + after) > r) r = before + after;
	//	/*cout << "after is" << after << endl;
	//	cout << endl;*/
	//}
	if (prices.empty() || prices.size() == 1) return 0;

	int k = 1;
	for (; k < prices.size(); k++)
		if (prices[k] > prices[k - 1]) break;
	if (k == prices.size()) return 0;

	vector<int> before(prices.size(), 0);
	vector<int> after(prices.size(), 0);

	int max = 0;
	int min_rank = 0;

	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] > prices[min_rank])
		{
			if (prices[i] - prices[min_rank] > max)
				max = prices[i] - prices[min_rank];
		}
		else min_rank = i;

		before[i] = max;
	}

	max = 0;
	int max_rank = prices.size() - 1;

	for (int i = prices.size() - 2; i >= 0; i--)
	{
		if (prices[i] > prices[max_rank])
		{
			max_rank = i;
		}
		else
		{
			if (max < prices[max_rank] - prices[i])
				max = prices[max_rank] - prices[i];
		}
		after[i] = max;
	}


	for (auto a : before)
		cout << a << " ";
	cout << endl;
	for (auto a : after)
		cout << a << " ";
	cout << endl;

	max = 0;

	for (int i = 0; i < prices.size() - 1; i++)
	{
		if (before[i] + after[i + 1] > max)
			max = before[i] + after[i];
	}
	if (max < before[before.size() - 1]) max = before[before.size() - 1];

	return max;
}

int main()
{
	vector<int> v{1,2};
	cout << maxProfit(v);
	system("pause");
}
