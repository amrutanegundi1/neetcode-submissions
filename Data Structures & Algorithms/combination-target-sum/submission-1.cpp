class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(0, nums, curr, target);
        return result;
    }

    void dfs(int index, vector<int> &nums, vector<int> &curr, int target)
    {
        if(index >= nums.size() || target < 0)
        {
            return;
        }

        if(target == 0)
        {
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        dfs(index, nums, curr, target - nums[index]);
        curr.pop_back();
        dfs(index + 1, nums, curr, target);
    }
};
