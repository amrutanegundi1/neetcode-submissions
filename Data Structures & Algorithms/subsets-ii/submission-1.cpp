class Solution {
public:
    set<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void dfs(vector<int>& nums, int i)
    {
        if( i >= nums.size())
        {
            res.insert(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, i+1);
        while(i < nums.size()-1 && nums[i] == nums[i+1])
        {
            i = i + 1;
        }
        curr.pop_back();
        dfs(nums, i+1);
    }
};
