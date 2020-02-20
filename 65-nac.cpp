// 65.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {

	int rank = digits.size() - 1;

	digits[rank]++;
	while(digits[rank] > 9)
	{
		digits[rank] = 0;
		
		if (rank - 1 >= 0)
		{
			rank--;
			digits[rank]++;
		}
		else
		{
			digits.insert(digits.begin(), 1);
			break;
		}
	}

	return digits;
	
}

int main()
{
	vector<int> v{ 9,9,9,9,9 };
	plusOne(v);
	for (auto a : v)
		cout << a << " ";
	system("pause");
}
