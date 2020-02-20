// 79.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;
int z = 0;

//bool dfs(int x, int y, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited);
//int dir[4][4] = { {-1,0},{1,0},{0,-1},{0,1} };
//
//bool exist(vector<vector<char>>& board, string word) {
//	int m = board.size();//几行
//	int n = board[0].size();//几列
//	vector<vector<bool>> visited(m, vector<bool>(n));//是否被访问过              
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			if (dfs(i, j, 0, board, word, visited))
//			{
//				cout << "run times:" << z << endl;
//				return true;
//			}
//				
//		}
//	}
//	cout << "run times:" << z << endl;
//	return false;
//}
//
//bool dfs(int x, int y, int index, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
//	z++;
//	if (index == word.size() - 1) {
//		return word[index] == board[x][y];
//	}
//
//	if (word[index] == board[x][y]) {
//		visited[x][y] = true;
//		for (int i = 0; i < 4; i++) {
//			int new_x = x + dir[i][0];
//			int new_y = y + dir[i][1];
//
//			if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size() && !visited[new_x][new_y])
//				if (dfs(new_x, new_y, index + 1, board, word, visited))
//					return true;
//		}
//		visited[x][y] = false;
//
//	}
//	return false;
//}



bool test(vector<vector<char>>& board, vector<vector<bool>>&table, int &rank, int x,int y, string& word);

bool exist(vector<vector<char>>& board, string word) 
{
	if (board.empty() || board[0].empty()|| word.empty()) return 0;

	vector<vector<bool>> table(board.size(), vector<bool>(board[0].size(), 1));
	int rank = 0;
	int i = 0;
	int j = 0;

	for ( ; i<board.size(); i++)
		for (; j<board[0].size(); j++)		
			if(test(board,table,rank,i,j,word))
			{
				return 1;
			}
	cout << z << endl;
	return 0;
}

bool test(vector<vector<char>>& board, vector<vector<bool>>& table, int& index, int x, int y, string& word)
{
	/*for (auto a : table)
	{
		for (auto b : a)
			cout << b <<" ";
		cout << endl;
	}
	cout << endl;*/
	z++;
	if (x < 0 || x >= board.size() || y < 0 || y >= board.size())
		return 0;

	if (index == word.size())
		return 1;

	if (board[x][y] == word[index])
	{
		index++;
		table[x][y] = 0;

		if (index == word.size())
			return 1;

		if (x - 1 >= 0 && table[x - 1][y])
		{
			if (test(board, table, index, x - 1, y, word))
				return 1;
		}

		if (x + 1 < board.size() && table[x + 1][y])
		{
			if (test(board, table, index, x + 1, y, word))
				return 1;
		}

		if (y - 1 >= 0 && table[x][y-1])
		{
			if (test(board, table, index, x, y-1, word))
				return 1;
		}

		if (y + 1 < board[0].size() && table[x][y+1])
		{
			if (test(board, table, index, x, y+1, word))
				return 1;
		}
		table[x][y] = 1;
		index--;
	}
	
	return 0;
}


//bool exist(vector<vector<char>>& board, string word)
//{
//	if (board.empty() || board[0].empty() || word.empty()) return 0;
//
//	vector<vector<bool>> table(board.size(), vector<bool>(board[0].size(), 1));
//	vector<vector<vector<bool>>> table_back;
//	vector<int> rank;
//	vector<int> position;
//
//	for (int i = 0; i < board.size(); i++)
//		for (int j = 0; j < board[0].size(); j++)
//			if (board[i][j] == word[0])
//			{
//				auto temp_table = table;
//				temp_table[i][j] = 0;
//
//
//
//				table_back.push_back(temp_table);
//				position.push_back(i);
//				position.push_back(j);
//				rank.push_back(1);
//			}
//
//	while (!table_back.empty())
//	{
//		z++;
//		int col = position.back();
//		position.pop_back();
//		int line = position.back();
//		position.pop_back();
//
//		int r = rank.back();
//		table = table_back.back();
//
//		rank.pop_back();
//		table_back.pop_back();
//
//		if (r == word.size())
//		{
//			cout << "run: " << z << "times";
//			return 1;
//		}
//			
//
//		// 所有可能方位存入栈中
//		if (line - 1 >= 0 && table[line - 1][col] && board[line - 1][col] == word[r])
//		{
//			auto temp_table = table;
//			temp_table[line - 1][col] = 0;
//			table_back.push_back(temp_table);
//			rank.push_back(r + 1);
//			position.push_back(line - 1);
//			position.push_back(col);
//		}
//
//		if (line + 1 < board.size() && table[line + 1][col] && board[line + 1][col] == word[r])
//		{
//			auto temp_table = table;
//			temp_table[line + 1][col] = 0;
//			table_back.push_back(temp_table);
//			rank.push_back(r + 1);
//			position.push_back(line + 1);
//			position.push_back(col);
//		}
//
//		if (col - 1 >= 0 && table[line][col - 1] && board[line][col - 1] == word[r])
//		{
//			auto temp_table = table;
//			temp_table[line][col - 1] = 0;
//			table_back.push_back(temp_table);
//			rank.push_back(r + 1);
//			position.push_back(line);
//			position.push_back(col - 1);
//		}
//
//		if (col + 1 < table[0].size() && table[line][col + 1] && board[line][col + 1] == word[r])
//		{
//			auto temp_table = table;
//			temp_table[line][col + 1] = 0;
//			table_back.push_back(temp_table);
//			rank.push_back(r + 1);
//			position.push_back(line);
//			position.push_back(col + 1);
//		}
//
//	}
//	cout << " run : " << z << "times" << endl;
//	return 0;
//}


int main()
{
	vector<vector<char>> v{ {'a'},{'a'} };
	cout << exist(v, "aa");

	/*clock_t start, finish;
	double totaltime;
	start = clock();

	int i = 100;
	while (i > 0)
	{
		exist(v, "ABCCED");
		i--;
	}
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;*/
	system("pause");
	return 0;
}

