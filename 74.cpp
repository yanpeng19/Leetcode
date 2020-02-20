// 74.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	if (matrix.empty() || matrix[0].empty()) return 0;

	int l = 0;
	int r = matrix.size() * matrix[0].size();

	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		int rank = mid - 1;
		if (rank < 0) rank = 0;
		int line = rank / matrix[0].size();
		int col = rank % matrix[0].size();

		int value = matrix[line][col];

		if (value == target) return 1;
		if (target > value) l = mid + 1;
		else r = mid - 1;
	}
	return 0;
}

int main()
{
	vector<vector<int>> v{ {1} };
	cout << searchMatrix(v, 0);
	system("pause");
}

