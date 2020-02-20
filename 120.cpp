class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0) return 0;
		if (triangle[0].empty()) return 0;
		if (triangle.size() == 1) return triangle[0][0];

		vector<vector<int>>& table = triangle;

		//ÃÓ±Ì√ø≤„
		int min = -1;
		for (int i = 1; i < triangle.size(); i++)
		{

			table[i][0] = table[i - 1][0] + table[i][0];
			table[i][table[i].size() - 1] = table[i - 1][table[i - 1].size() - 1] + table[i][table[i].size() - 1];

			min = table[i][0] < table[i][table[i].size() - 1] ? table[i][0] : table[i][table[i].size() - 1];

			for (int j = 1; j < table[i].size() - 1; j++)
			{
				table[i][j] = table[i][j] + (table[i - 1][j] < table[i - 1][j - 1] ? table[i - 1][j] : table[i - 1][j - 1]);

				if (min > table[i][j])
					min = table[i][j];
			}
		}
		// for(auto a : table)
		// {
		//     for(auto b : a)
		//     cout << b << " ";
		//     cout <<endl;
		// }

		return min;
	}
};