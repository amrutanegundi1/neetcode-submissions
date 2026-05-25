class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()  == 0)
            return 0;
        sort(nums.begin(), nums.end());

        int longest = 0, streak = 1;

        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            else if(nums[i] == nums[i-1] + 1)
            {
                streak++;
            }
            else
            {
                longest = max(longest, streak);
                streak = 1;
            }
        }
        longest = max(longest, streak);
        return longest;
    }
};
