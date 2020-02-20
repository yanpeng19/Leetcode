// 122.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	//if (prices.empty() || prices.size() == 1) return 0;
	//vector<int> table(prices.size(), 0);
	//table[0] = 0;
	//table[1] = (prices[1] - prices[0]) > 0 ? prices[1] - prices[0] : 0;

	////          1,2,3,4,5 
 // 	//  table   0,1
	////  i           2
	////  j       {0-3}   

	//for (int i = 2; i < prices.size(); i++)
	//{
	//	int max = table[i - 1];

	//	for (int j = 0; j < i; j++)
	//	{
	//		int n = prices[i] - prices[j];
	//		if (n < 0) n = 0;
	//		int m = 0;
	//		if (j != 0) m = table[j-1];
	//		int sum = m + n;
	//		if (sum > max) max = sum;
	//	}

	//	table[i] = max;
	//}

	//int max = 0;
	//for (auto a : table)
	//	if (a > max)
	//		max = a;
	if (prices.empty() || prices.size() == 1) return 0;
	int max = 0;
	for (int i = 1; i < prices.size(); i++)
	 
		if (prices[i] - prices[i - 1] > 0) max += (prices[i] - prices[i - 1]);
	

	return max;
}

int main()
{
	vector<int> v{ 1,2};
	//             0 1,2,3,
	
	cout << maxProfit(v);
	system("pause");
}


