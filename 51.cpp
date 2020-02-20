// 51.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> solveNQueens(int n)
{
	if (n == 0) return vector<vector<string>>();
	if (n == 1) return vector<vector<string>> { {"Q"}};




	// n 皇后问题  从第0行道第n-1行如果都能找到合法位置
	// 那么就获得一个解
	// n 皇后是在上一个n-1皇后的解的基础上新增的行和列的尝试逐个尝试
	// 


	vector<vector<int>> table_back;
	vector<vector<bool>> law_back;

	// 插入第0行所有可能位置，以及位置的对应下一行合法位置
	for (int i = n-1; i >= 0; i--)
	{
		vector<int> temp_table{ i };
		table_back.push_back(temp_table);

		vector<bool> temp_law(n, 1);
		temp_law[i] = 0;
		if (i - 1 >= 0) temp_law[i - 1] = 0;
		if (i + 1 < n) temp_law[i + 1] = 0;

		law_back.push_back(temp_law);
	}

	vector<bool> law_pos;
	vector<int> table;

	vector<vector<string>> resault;
	
	// 在第0行 0~n-1的位置进行尝试
	bool flag = 0;
	
	do {
		// 取出一个状态
		law_pos = law_back.back();
		table = table_back.back();

		law_back.pop_back();
		table_back.pop_back();
		
		// 检测下一行是否有合法位置，如果有，那么就插入并且生成新的 下一行 law_pos
		vector<bool>::iterator pos = find(law_pos.begin(), law_pos.end(), 1);

		while (pos != law_pos.end())
		{
			//说明下一行有合法插入位置，都找出来，并且插入
			int rank = pos - law_pos.begin();
			auto temp_table = table;
			auto temp_law = vector<bool>(n, 1);
			temp_table.push_back(rank);

			if (temp_table.size() == n)
			{
				// 说明这次插入成功，已经满了，那么记录
				vector<string> temp;
				for (int k = 0; k < temp_table.size(); k++)
				{
					string s(n, '.');
					s[temp_table[k]] = 'Q';
					temp.push_back(s);
				}
				resault.push_back(temp);
			}
			else
			{
				// 没有满，说明给还有下一行，将下一行的 数字状态及 合法位置统统记录
				for (int i = 0; i < temp_table.size(); i++)
				{
					int offset = temp_table.size()-i;
					rank = temp_table[i];

					temp_law[rank] = 0;
					if (rank - offset >= 0) temp_law[rank - offset] = 0;
					if (rank + offset < temp_law.size()) temp_law[rank + offset] = 0;
				}
				// 将下一个表格和规则push进栈中
				table_back.push_back(temp_table);
				law_back.push_back(temp_law);
			}
			// 本行的下一个合法位置
			pos = find(pos + 1, law_pos.end(),1);
		}
		
	} while (!table_back.empty());

	return resault;
}

int main()
{
	auto a = solveNQueens(8);

	for (auto b : a)
	{
		for (auto c : b)
			cout << c << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}
