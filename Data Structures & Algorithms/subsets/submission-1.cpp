class Solution {
    vector<vector<int>> res;
    vector<int> curr;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);    
        return res;
    }

    void dfs(vector<int>& nums, int i)
    {
        if(i >= nums.size())
        {
         res.push_back(curr);
         return;   
        }
        curr.push_back(nums[i]);
        dfs(nums, i+1);
        curr.pop_back();
        dfs(nums, i+1);
    }
};
