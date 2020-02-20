class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		if (s.empty()) return 1;
		if (wordDict.empty()) return 0;

		unordered_set<string> word(wordDict.begin(), wordDict.end());

		vector<bool> table(s.size(), 0);

		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j <= i; j++)
			{
				string ss(s.begin() + j, s.begin() + i + 1);
				if ((j == 0 || table[j - 1]) && word.find(ss) != word.end())
				{
					table[i] = 1;
					break;
				}
			}
		}

		return table[table.size() - 1];

	}
}