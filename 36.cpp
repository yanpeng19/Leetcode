// 36.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) 
{
	int line = 0;
	int col = 0;
	for (int i = 0; i < 9; i++)
	{
		set<char> c;
		int f = 0;

		for (int j = line; j < line+3; j++)
		{
			for (int k = col; k < col + 3; k++)
			{
				if (board[j][k] != '.') c.insert(board[j][k]);
				else f++;
			}
		}
		if ((f + c.size()) != 9) return false;
		c = set<char>();
		f = 0;

		line += 3;
		if (line > 6)
		{
			line = 0;
			col += 3;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		set<char> line;
		int line_f = 0;

		set<char> lie;
		int lie_f = 0;

		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
				line.insert(board[i][j]);
			else line_f++;

			if (board[j][i] != '.')
				lie.insert(board[j][i]);
			else lie_f++;
		}
		if ((line.size() + line_f) != 9 || (lie.size() + lie_f) != 9) return false;

	}

	return true;
}

int main()
{
	vector<vector<char>> v{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.','.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.','3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	cout << isValidSudoku(v);


    
	system("pause");
}
