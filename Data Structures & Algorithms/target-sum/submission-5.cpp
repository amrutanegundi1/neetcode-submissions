class Solution {
   public:
    map<pair<int, int>, int> mp;
    int findTargetSumWays(vector<int>& nums, int target) { 
        return dfs(0, target, nums); 
        }
    int dfs(int i, int target, vector<int>& nums) {
        pair<int, int> pr = pair<int, int>(i, target);
        if (mp.find(pr) != mp.end()) {
            return mp[pr];
        }
        if (0 == target && i == nums.size()) {
            return 1;
        }
        if (i >= nums.size()) {
            return 0;
        }

        mp[pr] =
            (dfs(i + 1, target + nums[i], nums) + dfs(i + 1, target-nums[i], nums));
        return mp[pr];
    }
};
