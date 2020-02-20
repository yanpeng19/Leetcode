// 130.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void fun(vector<vector<char>>& board, vector<vector<char>>& table, int x, int y)
{
	// 上下左右4个方向处理
	table[x][y] = 'O';
	if (x - 1 >= 0 && table[x - 1][y] != 'O')
		fun(board, table, x - 1, y);
	if (x + 1 < table.size() && table[x + 1][y] != 'O')
		fun(board, table, x + 1, y);

	if (y - 1 >= 0 && table[x][y - 1] != 'O')
		fun(board, table, x, y - 1);
	if (y + 1 < table[0].size() && table[x][y + 1] != 'O')
		fun(board, table, x, y + 1);
}

void solve(vector<vector<char>>& board) 
{
	/*if (board.empty() || board[0].empty()) return;

	vector<vector<char>> table(board.size(), vector<char>(board[0].size(), 'X'));

	for (int i = 0; i < board[0].size(); i++)
	{
		if (board[0][i] == 'O')
		{
			table[0][i] = 'O';
			int j = 1;
			while (j < board.size() && board[j][i] == 'O')
				table[j++][i] = 'O';
		}

		if (board[board.size() - 1][i] == 'O')
		{
			table[board.size() - 1][i] = 'O';
			int j = board.size() - 2;
			while (j >= 0 && board[j][i] == 'O' && table[j][i] != 'O')
				table[j--][i] = 'O';
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][0] == 'O' && table[i][0] != 'O')
			table[i][0] = 'O';
		if (board[i][board.size() - 1] == 'O' && table[i][board.size() - 1] != 'O')
			table[i][board.size() - 1] = 'O';
	}*/

	if (board.empty() || board[0].empty()) return;

	vector<vector<char>> table(board.size(), vector<char>(board[0].size(), 'X'));

	for (int i = 0; i < board[0].size(); i++)
	{
		if (board[0][i] == 'O')
			fun(board, table, 0, i);

		if (board[board.size() - 1][i] == 'O')
			fun(board, table, board.size() - 1, i);
	}

	for (int i = 0; i < board.size(); i++)
	{
		if (board[i][0] == 'O' && table[i][0] != 'O')
			fun(board, table, i, 0);

		if (board[i][board[0].size() - 1] == 'O' && table[i][board[0].size() - 1] != 'O')
			fun(board, table, i, board[0].size() - 1);

	}

	board = table;
	return;
}

int main()
{
	vector<vector<char>> v{ {'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},{'O','X','O','O','O'},{'X','X','O','X','O'} };
	solve(v);
	system("pause");
}

