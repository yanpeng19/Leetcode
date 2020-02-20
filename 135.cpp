// 135.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {


	if (ratings.empty()) return 0;
	if (ratings.size() == 1) return 1;

	vector<int> table(ratings.size(), 0);

	// 按段处理
	int l = 0;
	int r = 1;

	while (l < ratings.size())
	{
		//寻找顺序段
		while (r < ratings.size() && ratings[r] >= ratings[r-1])
			r++;
		// l~r 是一个顺序段
		// t[l]<t[l-1]
		table[l] = 1;
		for (int rank = l + 1; rank < r; rank++)
		{
			if (ratings[rank] == ratings[rank - 1])
				table[rank] = 1;
			else table[rank] = table[rank - 1] + 1;
		}

		if (l == 0)
		{
			l = r;
			r++;
		}
		else
		{
			// 需要比较前后段，来调整
			if (table[l] == table[l - 1])
				table[l - 1]++;

		
			l = r;
			r++;
		}
	}

	int sum = 0;
	for (int rank = ratings.size() - 1; rank > 0; rank--)
		if (ratings[rank - 1] > ratings[rank] && table[rank - 1] <= table[rank])
			table[rank - 1] = table[rank]+1;

	for (auto a : table)
		sum += a;
	// cout << sum;
	return sum;
}

int main()
{
	vector<int> v{ 1,2,87,87,87,2,1 };
	//             1 2 3 1 1 ,2 ,1

	cout << candy(v);

	system("pause");
}

