class Solution {
   public:
    map<pair<int, int>, int> mp;
    int findTargetSumWays(vector<int>& nums, int target) { return dfs(0, 0, target, nums); }
    int dfs(int i, int curr, int target, vector<int>& nums) {
        pair<int, int> pr = pair<int, int>(i, curr);
        if(mp.find(pr) != mp.end())
        {
            return mp[pr];
        }
        if(i >= nums.size() && curr == target)
        {
            return 1;
        }
        if(i >= nums.size())
        {
            return 0;
        }

        mp[pr] = (dfs(i+1, curr + nums[i], target, nums) + dfs(i+1, curr - nums[i], target, nums));
        return mp[pr];
    }
};
