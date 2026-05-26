class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int curr =nums[0];
        int maxLength = 1;
        int streak = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;
            if(curr+1 == nums[i])
            {
                streak++;
                curr++;
                maxLength = max(maxLength, streak);
            }
            else
            {
                curr = nums[i];
                streak = 1;
            }
        }
        
        return maxLength;
    }
};
