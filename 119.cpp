class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) return vector<int>{1};
		if (rowIndex == 1) return vector<int>{1, 1};

		vector<int> r{ 1,1 };
		for (int i = 2; i <= rowIndex; i++)
		{
			vector<int>temp = r;
			int mid = i / 2;
			r.insert(r.begin() + mid, 1);

			int k = r.size() - 2;

			for (int j = 1; j <= mid; j++)
			{
				int n = temp[j - 1] + temp[j];
				r[j] = n;
				if (k > j) r[k] = n;
				k--;
			}

		}
		return r;
	}

};