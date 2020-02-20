// 149.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

struct node
{
	node() = default;
	node(int i, int j, int k)
	{
		down = i;
		left_d = j;
		right_d = k;
	}
	int down;
	int left_d;  // 左斜
	int right_d; // 右斜
};

int maxPoints(vector<vector<int>>& points)
{
	if (points.empty() || points[0].empty()) return 0;
	// 横竖 左斜 右斜 4个方向

	// 画出矩阵图
	int max_x = 0;
	int max_y = 0;

	int min_x = points[0][1];
	int min_y = points[0][0];
	
	for (int i = 0; i < points.size(); i++)
	{
		if (max_y < points[i][0]) max_y = points[i][0];
		if (min_y > points[i][0]) min_y = points[i][0];
		if (max_x < points[i][1]) max_x = points[i][1];
		if (min_x > points[i][1]) min_x = points[i][1];		
	}


	vector<vector<int>> table(max_x-min_x+1,vector<int>(max_y-min_y+1,0));

	if (min_x != 0&&min_y!=0)
	{
		for (auto &a : points)
		{
			a[0] -= min_y;
			a[1] -= min_x;
		}
	}
	else if (min_x != 0)
	{
		for (auto &a : points)
			a[1] -= min_x;
	}
	else if (min_y != 0)
	{
		for (auto &a : points)
			a[0] -= min_y;
	}

	for (int i = 0; i < points.size(); i++)
	{
		int x = points[i][1];
		int y = points[i][0];

		table[x][y]++;
	}

	for (int i = table.size()-1;i>=0;i--)
	{
		for (int j = 0; j < table[0].size(); j++)
			cout << table[i][j] << " ";
		cout << endl;
	}

	vector<vector<node>> t(table.size(),vector<node>(table[0].size()));

	int max = 0;
	int max_len = 0;

	for (int i = 0; i < table[0].size(); i++)
	{
		int n = table[table.size() - 1][i];
		max_len += n;
		if (max_len > max) max = max_len;
		t[t.size() - 1][i] = node(n, n, n);
	}

	for (int i = table.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < table[0].size(); j++)
			cout << table[i][j] << " ";
		cout << endl;
	}



	for (int i = table.size()-2;i>=0;i--)
	{
		max_len = 0;
		for (int j = 0; j < table[0].size(); j++)
		{
			// 横着
			max_len += table[i][j];
			if (max_len > max) max = max_len;


			//更新节点

			t[i][j] = node(table[i][j], table[i][j], table[i][j]);

			t[i][j].down = t[i + 1][j].down + table[i][j];
			if (t[i][j].down > max) max = t[i][j].down;
			

			if (j - 1 >= 0)
			{
				t[i][j].right_d = t[i + 1][j - 1].right_d + table[i][j];
				if (t[i][j].right_d > max) max = t[i][j].right_d;
			}

			if (j + 1 < table[0].size())
			{
				t[i][j].left_d = t[i + 1][j + 1].left_d + table[i][j];
				if (t[i][j].left_d > max) max = t[i][j].left_d;
			}
				
		}
	}


	cout << endl;
	for (int i = table.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < table[0].size(); j++)
			cout << "[" << t[i][j].down << " " << t[i][j].left_d << " " << t[i][j].right_d << " ]";
		cout << endl;
	}

 	return max;

}

int main()
{
	//vector<vector<int>> v{ {1,1 }, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
	vector<vector<int>> v{ {1,1},{2,3},{1,1} };
	cout << maxPoints(v);
	system("pause");
}
