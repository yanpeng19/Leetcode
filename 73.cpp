// 73.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) 
{
	int line = matrix.size();
	int col = matrix[0].size();

	for (int i = 0; i < line; i++)
		for (int j = 0; j < col; j++)
			if (matrix[i][j] == 0)
			{
				for (int m = 0; m < line; m++)
					if (matrix[m][j] != 0) matrix[m][j] = -23496106;
				for(int m = 0;m<col;m++)
					if(matrix[i][m]!=0) matrix[i][m] = -23496106;
			}


	for (auto &a : matrix)
		for (auto& b : a)
			if (b == -23496106) b = 0;
}

int main()
{
	vector<vector<int>> v = vector<vector<int>>(3, vector<int>(3, 1));
	v[1][1] = 0;
	setZeroes(v);
}

