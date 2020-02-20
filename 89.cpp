// 89.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> grayCode(int n) 
{
	if (!n) return vector<int>{0};
	if (n == 1) return vector<int>{0, 1};

	int m = 2;
	int sum = 1;
	int max = 1;
	vector<int> r{ 0,1 };

	for (int i = 2; i <= n; i++)
	{
		for (int j = r.size()-1; j >= 0; j--)
		{
			int temp = r[j] + m;
			if (temp > max) max = temp;
			r.push_back(temp);
		}
		
		m *= 2;
	}
	for (auto a : r)
		cout << a << " ";
	cout << endl;

	return  r;
}

int main()
{
	grayCode(4);	
}

