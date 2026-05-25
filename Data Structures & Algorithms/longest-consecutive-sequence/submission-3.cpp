class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()  == 0)
            return 0;
        unordered_set<int> sets(nums.begin(), nums.end());

        int longest = 0;

        for(int i = 0; i< nums.size(); i++)
        {
            if(sets.find(nums[i] - 1) == sets.end())
            {
                int length = 1;
                while(sets.find(nums[i] + length) != sets.end())
                {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        
        return longest;
    }
};
