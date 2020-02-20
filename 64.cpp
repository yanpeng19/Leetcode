// 64.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) 
{
	if (grid.empty()) return 0;
	if (grid[0].empty()) return 0;

	int line = grid.size();
	int col = grid[0].size();

	vector<vector<int>> table(line, vector<int>(col, 0));

	if (line < 2)
	{
		int num = 0;
		for (auto a : grid[0])
			num += a;
		return num;
	}
	if (col < 2)
	{
		int num = 0;
		for (auto a : grid)
			num += a[0];
		return num;
	}
	table[line-1][col-1] = grid[line - 1][col - 1];

	
	int num = grid[line - 1][col - 1];

	for (int i = col - 2; i >= 0; i--)
	{
		num += grid[line - 1][i];
		table[line - 1][i] = num;
	}
		 
	num = grid[line - 1][col - 1];
	for (int i = line - 2; i >= 0; i--)
	{
		num += grid[i][col - 1];
		table[i][col - 1] = num;
	}
	

	for (int i = line - 2; i >= 0; i--)
		for (int j = col - 2; j >= 0; j--)
		{
			int min = table[i + 1][j] < table[i][j + 1] ? table[i + 1][j] : table[i][j + 1];
			table[i][j] = grid[i][j] + min;
		}
			

	return table[0][0];
}

int main()
{
	vector<vector<int>> v{
	{1,3,1},
	{1,5,1},
	{4,2,1}
	};

	cout << minPathSum(v);
	system("pause");
}


