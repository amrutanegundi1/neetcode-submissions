class Solution {
public:
    set<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
       dfs(nums, 0, curr); 

       return vector<vector<int>>(result.begin(), result.end());
    }

    void dfs(vector<int>& nums, int i, vector<int> curr)
    {
        if(i == nums.size())
        {
            sort(curr.begin(), curr.end());
            result.insert(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, i+1, curr);
        curr.pop_back();
        dfs(nums, i+1, curr);
    }
};
