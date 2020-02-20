class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		if (haystack.empty()) return -1;

		int rank = 0;

		while ((haystack.size() - rank) >= needle.size())
		{
			int temp = rank;
			int n_temp = 0;
			while (haystack[temp] == needle[n_temp])
			{
				temp++;
				n_temp++;
				if (n_temp == needle.size()) return rank;
			}
			rank++;
		}

		return -1;
	}
};