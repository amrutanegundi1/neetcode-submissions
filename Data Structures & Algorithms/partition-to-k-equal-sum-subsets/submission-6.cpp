class Solution {
   public:
    vector<int> sum;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        for (auto itr : nums) {
            total += itr;
        }
        if (total % k != 0) {
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        sum.resize(k, 0);
        return dfs(0, nums, k, total / k);
    }
    bool dfs(int i, vector<int>& nums, int k, int len) {
        if (i == nums.size()) {
            for (int j = 0; j < k - 1; j++) {
                if (sum[j] != sum[j + 1]) {
                    return false;
                }
            }
            return true;
        }
        for (int j = 0; j < k; j++) {
            if (sum[j] + nums[i] <= len) {
                sum[j] += nums[i];
                if (dfs(i + 1, nums, k, len)) {
                    return true;
                }
                sum[j] -= nums[i];
            }
        }
        return false;
    }
};