// 54.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	if (matrix.empty()) return vector<int>();
	if (matrix.size() == 1) return matrix[0];
	vector<int> resault;

	int max_line = matrix[0].size();
	int min_line = 0;
	int max_col = matrix.size();
	int min_col = 0;

	int n = matrix[0].size() * matrix.size();

	while (n > 0)
	{
		int i = min_line;
		int j = min_col;

		while (j < max_line)
		{
			n--;
			resault.push_back(matrix[i][j]);
			j++;
			if (n == 0) return resault;
		}
		j--;

		 
		i++;
		while (i < max_col)
		{
			n--;
			resault.push_back(matrix[i][j]);
			i++;
			if (n == 0) return resault;
		}
		i--;

		j--;
		while (j >= min_col)
		{
			n--;
			resault.push_back(matrix[i][j]);
			j--;
			if (n == 0) return resault;
		}
		j++;

		i--;
		min_line++;
		while (i >= min_line)
		{
			
			n--;
			resault.push_back(matrix[i][j]);
			if (i == (min_line)) break;
			i--;
			if (n == 0) return resault;
		}
		i++;

		max_col--;
		max_line--;
		min_col++;
	}

	return resault;
}

int main()
{
	vector<vector<int>> v{
		{4,5,6},
	{6,7,8},
	{11,12,13}
	};
	vector<int> r = spiralOrder(v);

	for (auto a : r)
		cout << a << " ";
	cout << endl;
	system("pause");
}

