// 59.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) 
{
	if(n == 0) return vector<vector<int>>();

	int l = 0;
	int r = n-1;
	int count = 1;

	vector<vector<int>> resault(n, vector<int>(n, 0));

	while (l<=r)
	{
		int i = l;
		int j = l;

		while (j <= r)
		{
			resault[i][j] = count++;
			j++;
		}
		j--;

		i++;
		while (i <= r)
		{
			resault[i][j] = count++;
			i++;
		}
		i--;

		j--;
		while (j >= l)
		{
			resault[i][j] = count++;
			j--;
		}
		j++;

		i--;
		while (i > l)
		{
			resault[i][j] = count++;
			i--;
		}

		l++;
		r--;
	}

	return resault;
}

int main()
{
	auto v = generateMatrix(4);

	for (auto a : v)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}

	system("pause");
}

