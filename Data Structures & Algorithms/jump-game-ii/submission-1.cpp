class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), INT_MAX);

        dp[nums.size()-1] = 0;
        for(int i = nums.size()-2; i >= 0; i--)
        {
            int j = nums[i];
            if(j != 0)
            {
                int minimum = INT_MAX;
                for(int k = i + 1, c = 0; k < nums.size() && c < j; k++,c++)
                {
                    if(dp[k] < minimum)
                    {
                        minimum = dp[k];
                    }
                }
                dp[i] = minimum + 1;
            }
        }
        return dp[0];
        
    }
};
