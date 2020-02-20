// 10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

int get_max(vector<int>& height)
{
		int max = 0;
		int index = 0;

		for (int i = 1; i < height.size(); i++)
		{
			int h = height[i] > height[index] ? height[index] : height[i];
			int temp = h * (i - index);
			if (temp > max) max = temp;

			if (index != i - 1)
			{
				int new_index = index + 1;
				int temp_h = height[new_index] > height[i] ? height[i] : height[new_index];
				int temp_t = temp_h * (i - new_index);
				

				if (temp_t > temp)
				{
					temp = temp_t;
					index++;
					if (temp > max) max = temp;
				}
			}

			if (i != index + 1)
			{
				int new_index = i-1;
				int temp_h = height[new_index] > height[i] ? height[i] : height[new_index];
				int temp_t = temp_h * (i - new_index);

				if (temp_t > temp)
				{
					temp = temp_t;
					index = i - 1;
					if (temp > max) max = temp;
				}
			}

		
		}

		return max;
}

int main()
{
	vector<int> v{ 5,2,12,1,5,3,4,11,9,4};
	cout << get_max(v);
	system("pause");
	return 0;
}

