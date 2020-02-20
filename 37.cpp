// 37.cpp : 此文件包含 'main' 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board)
{
	int line = 0;
	int col = 0;
	for (int i = 0; i < 9; i++)
	{
		set<char> c;
		int f = 0;

		for (int j = line; j < line + 3; j++)
		{
			for (int k = col; k < col + 3; k++)
			{
				if (board[j][k] != '.') c.insert(board[j][k]);
				else f++;
			}
		}
		if ((f + c.size()) != 9) 
			return false;
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
		if ((line.size() + line_f) != 9 || (lie.size() + lie_f) != 9) 
			return false;

	}

	return true;
}


void solveSudoku(vector<vector<char>>& board)
{
	vector<vector<char>> table;
	set<char> s{ '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	
	vector<vector<vector<char>>> table_back;
	table_back.push_back(board);

	while (!table_back.empty())
	{
		table = table_back.back();
		table_back.pop_back();

		vector<vector<set<char>>> law_nums(9, vector<set<char>>(9, s));

		for (auto a : law_nums)
		{
			for (auto b : a)
				cout << b.size() << ' ';
			cout << endl;
		}
		cout << endl;
		for (auto a : table)
		{
			for (auto b : a)
				cout << b << ' ';
			cout << endl;
		}
		cout << endl;

		int line = 0;
		int col = 0;
		// 9个 3*3，每次处理一个,生成九宫格内的有效数字集

		for (int i = 0; i < 9; i++)
		{
			vector<char> v;//存储这次九宫出现过的数字

			// 寻找出现过的数字,并将有数字的位置 可能数字 为0
			for (int j = line; j < line + 3; j++)
				for (int k = col; k < col + 3; k++)
					if (table[j][k] != '.')
					{
						char c = table[j][k];
						law_nums[j][k].clear();
						v.push_back(c);
					}

			//遍历这次九宫格的所有 nums 去掉合法数字
			for (int j = line; j < line + 3; j++)
				for (int k = col; k < col + 3; k++)
					for (auto a : v)
						law_nums[j][k].erase(a);

			line += 3;
			if (line > 6)
			{
				line = 0;
				col += 3;
			}
		}

		for (auto a : law_nums)
		{
			for (auto b : a)
				cout << b.size() << ' ';
			cout << endl;
		}
		cout << endl;
		for (auto a : table)
		{
			for (auto b : a)
				cout << b << ' ';
			cout << endl;
		}
		cout << endl;

		// 删除每个位置行和列的合法数字
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (table[i][j] != '.')
				{
					char c = table[i][j];
					for (int k = 0; k < 9; k++)
					{
						// 从 i[0]~i[8] 所有数字中，删除掉 board[i][j];
						// 从 [0][j]~[8][j] 删除到所有
						law_nums[i][k].erase(c);
						law_nums[k][j].erase(c);
					}
				}

		// 成功理想模式
		int f = 1;
		for (auto a : table)
			if (find(a.begin(), a.end(), '.') != a.end())
				f = 0;

		if (f)
		{
			board = table;
			return;
		}

		// 否则 寻找 可确定的数字，并且填充,并修改合法表格
		int flag = 1;
		while (flag)
		{
			flag = 0;
			for (int x = 0; x < 9; x++)
			{
				for (int y = 0; y < 9; y++)
				{
					if (law_nums[x][y].size() == 1)
					{
						char c = *law_nums[x][y].begin();
						law_nums[x][y].erase(c);
						flag = 1;//继续尝试
						table[x][y] = c;

						//更改合法数字
						int line = x / 3;
						int col = y / 3;

						// 更改单元的九宫格内的可能数字修改
						for (int i = line * 3; i < line *3+3; i++)
							for (int j = col * 3; j < col *3+3; j++)
								law_nums[i][j].erase(c);

						// 更改列
						for (int i = 0; i < 9; i++)
						{
							// x=1;y=2
							law_nums[x][i].erase(c);
							law_nums[i][y].erase(c);
						}
						
						for (auto a : law_nums)
						{
							for (auto b : a)
								cout << b.size() << ' ';
							cout << endl;
						}
						cout << endl;
						for (auto a : table)
						{
							for (auto b : a)
								cout << b << ' ';
							cout << endl;
						}
						cout << endl;

						x = -1;
						break;
					}
				}
			}
		}
	
		//到此处说明已经无从填写
		int min_low = 0;
		int min_col = 0;

		int min = 9;

		// 寻找表格中 可填数最少的一个
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (law_nums[i][j].size()&&law_nums[i][j].size() < min)
				{
					min = law_nums[i][j].size();
					min_low = i;
					min_col = j;
				}
		// 说明都填写完成
		f = 1;
		for (auto a : table)
			if (find(a.begin(), a.end(), '.') != a.end())
				f = 0;

		if (f)
		{
			board = table;
			return;
		}

		// 否则遍历状态并且都push进栈
		for (auto c : law_nums[min_low][min_col])
		{
			auto new_table = table;
			auto new_law = law_nums;

			new_table[min_low][min_col] = c;
			table_back.push_back(new_table);
		}
	}
	return;
}
int main()
{
	vector<vector<char>> v{
	{'.','2','6','5','.','.','.','9','.'},
	{'5','.','.','.','7','9','.','.','4'},
	{'3','.','.','.','1','.','.','.','.'},
	{'6','.','.','.','.','.','8','.','7'},
	{'.','7','5','.','2','.','.','1','.'},
	{'.','1','.','.','.','.','4','.','.'},
	{'.','.','.','3','.','8','9','.','2'},
	{'7','.','.','.','6','.','.','4','.'},
	{'.','3','.','2','.','.','1','.','.'} };

	solveSudoku(v);

	for (auto a : v)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << isValidSudoku(v) << endl;
	system("pause");
}

