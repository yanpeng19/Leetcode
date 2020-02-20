// 96.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int numTrees(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;

	vector<int> v{ 0,1 };
	vector<int> c;


	
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += numTrees(i) * numTrees(n - 1 - i);
	
	//cout << sum << endl;
	return sum;
}

int main()

{
	cout << numTrees(3);
    std::cout << "Hello World!\n";
}
