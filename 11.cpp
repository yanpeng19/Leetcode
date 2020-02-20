class Solution {
public:
	int maxArea(vector<int>& height) {

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
				int new_index = i - 1;
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
};