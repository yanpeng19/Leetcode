class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    int rank = digits.size() - 1;

	digits[rank]++;
	while(digits[rank] > 9)
	{
		digits[rank] = 0;
		
		if (rank - 1 >= 0)
		{
			rank--;
			digits[rank]++;
		}
		else
		{
			digits.insert(digits.begin(), 1);
			break;
		}
	}

	return digits;
    }
};