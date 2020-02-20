// 85.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size(), 0)); // x 节点下方有 ‘0’吗, 0表示有 ， 1表示没
	vector<vector<int>> right(matrix.size(), vector<int>(matrix[0].size(), 0));  // x 节点右边有 ‘0’吗


	for (int i = matrix.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (i == matrix.size() - 1)
			{
				down[i][j] = matrix[i][j] - 48;
				continue;
			}

			if (matrix[i][j] == '1')
			{
				down[i][j] = down[i + 1][j] + 1;
			}
			else down[i][j] = 0;
		}
	}

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = matrix[0].size() - 1; j >= 0; j--)
		{
			if (j == matrix[0].size() - 1)
			{
				right[i][j] = matrix[i][j] - 48;
				continue;
			}

			if (matrix[i][j] == '1')
			{
				right[i][j] = right[i][j+1] + 1;
			}
			else right[i][j] = 0;
				
		}
	}

	for (auto a : down)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;

	for (auto a : right)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;

	int max = 0;

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (down[i][j])
			{
				int area = down[i][j];
				int temp = area;

				int col = j + 1;
				while (col<matrix[0].size()&&down[i][col]>=down[i][j])
				{
					area += temp;
					col++;
				}
				if (area > max) max = area;

				col = j - 1;
				while (col >=0 && down[i][col] >= down[i][j])
				{
					area += temp;
					col--;
				}
				if (area > max) max = area;
			}
		}
	}


	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			// 横着的模式

			if (right[i][j])
			{
				int area = right[i][j];
				int temp = area;

				int line = i + 1;
				while (line < matrix.size() && right[line][j]>=right[i][j])
				{
					area += temp;
					line++;
				}
				if (area > max) max = area;

				line = i - 1;
				while (line >=0 && right[line][j] >= right[i][j])
				{
					area += temp;
					line--;
				}
				if (area > max) max = area;
			}
		}
	}

	return max;
}

int main()
{
	vector<vector<char>> v{ 
	{'1','0','1','1','0','1'},
	{'1','1','1','1','1','1'},
	{'0','1','1','0','1','1'},
	{'1','1','1','0','1','0'},
	{'0','1','1','1','1','1'},
	{'1','1','0','1','1','1'} };

	cout << maximalRectangle(v);
	system("pause");
}

