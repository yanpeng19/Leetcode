// 134.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{

	//for (int i = 0; i < gas.size(); i++)
	//{
	//	// 从i出发
	//	int sum = gas[i];
	//	bool f = 1;

	//	for (int j = i; j < gas.size(); j++)
	//	{
	//		if (sum < cost[j])
	//		{
	//			f = 0;
	//			break;
	//		}
	//		int next = j + 1;
	//		if (next == gas.size()) next = 0;

	//		sum += (gas[next] - cost[j]);
	//	}
	//	if (!f) continue;

	//	for (int j = 0; j < i; j++)
	//	{
	//		if (sum < cost[j])
	//		{
	//			f = 0;
	//			break;
	//		}
	//		int next = j + 1;
	//		if (next == gas.size()) next = 0;
	//		sum += (gas[next] - cost[j]);
	//	}
	//	if (!f) continue;
	//	return i;
	//}

	//return -1;


	int i = 0;
	int j = 0;
	int n = 0;

	while (j < gas.size())
	{

		if (gas[j] > cost[j])
		{
			n = gas[j] + cost[j];
			j++;
		}
		else
		{
			i = j + 1;
			j++;
			n = 0;
		}
	}
	if (i == gas.size()) return -1;
	else return i;

}

int main()
{
	vector<int> v{1,2,3,4,5};
	vector<int> c{3,4,5,1,2};
	cout << canCompleteCircuit(v, c);
	system("pause");
}
