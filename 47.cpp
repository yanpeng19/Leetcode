class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
   
   if (nums.empty()) return vector<vector<int>>();
	vector<vector<int>> resault{ {nums[0]} };

	// 得到一个新的数，就把原数组拷贝n份，并且在分别在 1~n的位置插入
	int n = 1;
	set<vector<int>> s;

	for (int i = 1; i < nums.size(); i++)
	{
		n++;

		vector<vector<int>> temp = resault;
		resault = vector<vector<int>>();
		
		for (auto a : temp)  // 把每个数从 0~n 插入新的数
		{
			vector<int> t;

			for (int j = 0; j < n; j++)
			{
				auto b = a;
				b.insert(b.begin() + j, nums[i]);
				if (s.find(b) == s.end())
				{
					s.insert(b);
					resault.push_back(b);
				}
			}	
		}
	}


	return resault;
    }
};