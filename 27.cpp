class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;

        int rank =0;
        int sorted = 0;

        while(rank<nums.size())
        {
            if(nums[rank]==val)
            {
                rank++;
                continue;
            }
            
            if(sorted!=rank)
                nums[sorted]=nums[rank];
            
            sorted++;
            rank++;
        }

        return sorted;
    }
};