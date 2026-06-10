class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {

        dfs(nums, 0, nums.size()-1);
        return res;
        
    }

    void dfs(vector<int> nums, int l, int r)
    {
        if(l == r)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i = l; i <= r; i++)
        {
            swap(nums[i], nums[l]);
            dfs(nums, l + 1, r);
            swap(nums[i], nums[l]);
        }
    }
};
