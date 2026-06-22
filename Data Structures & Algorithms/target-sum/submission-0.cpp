class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        return dfs(0, 0, target, nums);
        
    }
    int dfs(int i, int curr, int target, vector<int>& nums)
    {
        if(i >= nums.size() && curr == target)
        {
            return 1;
        }
        if(i >= nums.size())
        {
            return 0;
        }

        return (dfs(i+1, curr + nums[i], target, nums) + dfs(i+1, curr - nums[i], target, nums));
    }

};
