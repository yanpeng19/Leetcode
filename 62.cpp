// 62.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) 
{
	if (n < m) swap(n, m);

	if (m == 1) return 1;
	if (m == 2) return n;

	vector<vector<int>> table(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		table[m - 1][i] = 1;
	
	for (int i = 0; i < m; i++)
		table[i][n - 1] = 1;

	for (int i = m - 2; i >= 0; i--)
		for (int j = n - 2; j >= 0; j--)
			table[i][j] = table[i + 1][j] + table[i][j + 1];
		
	return table[0][0];
}

int main()
{
	cout << uniquePaths(3, 7);
 	system("pause");
}

