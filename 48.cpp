// 48.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {

	auto& v = matrix;

	//[0,0] -> [0,n]; [0,n]->[n,n],[n,n]->[n,0] , [n,0]->[0,0]
	int r = v[0].size() - 1;
	for (int i = 0; i <= r / 2; i++)
	{
		for (int j = i; j < r-i; j++)
		{
			int temp = v[i][j];  // v[0][0]


			v[i][j] = v[r - j][i];
			v[r - j][i] = v[r - i][r - j];

			v[r - i][r - j] = v[j][r - i];

			v[j][r - i] = temp;
			for (auto a : v)
			{
				for (auto b : a)
					cout << b << " ";
				cout << endl;
			}

			
			cout << endl;
		}
		
	}
}

int main()
{
	vector<vector<int>> v{
	{5,1,9,11},
	{2,4,8,10},
	{13,3,6,7},
	{15,14,12,16}
	};

	rotate(v);
	for (auto a : v)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}
