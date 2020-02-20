class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 0) return vector<vector<int>>();
		if (numRows == 1) return vector<vector<int>>{ {1}};
		if (numRows == 2) return vector<vector<int>>{ {1}, { 1,1 }};

		vector<vector<int>> r{ {1},{1,1} };
		for (int i = 3; i <= numRows; i++)
		{
			vector<int> temp(i, 1);
			int k = i - 2;

			for (int j = 1; j <= temp.size() / 2; j++)
			{
				int n = r[r.size() - 1][j - 1] + r[r.size() - 1][j];
				temp[j] = n;
				if (k > j)
					temp[k] = n;
				k--;
			}
			r.push_back(temp);
		}
		return r;
	}
};