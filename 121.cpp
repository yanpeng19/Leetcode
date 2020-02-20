class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty() || prices.size() == 1) return 0;

		//vector<int> table(prices.size(),0);

		int max = prices[prices.size() - 1];
		int r = 0;

		for (int j = prices.size() - 1; j >= 0; j--)
		{
			if (prices[j] < max)
			{
				//table[j]=max-prices[j];
				if (max - prices[j] > r) r = max - prices[j];
			}
			else max = prices[j];
		}


		return r;
	}
};