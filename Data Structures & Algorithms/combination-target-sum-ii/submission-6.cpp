class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& nums,int target, int i)
    {
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
        if(i >= nums.size() || target < 0)
        {
            return;
        }
        
        //we choose the element
        curr.push_back(nums[i]);
        dfs(nums, target - nums[i], i+1);
        int poped = curr[curr.size()-1];
        curr.pop_back();
        while(i+1 < nums.size())
        {
            if(poped == nums[i+1])
            {
                i = i+1;
            }
            else
            {
                break;
            }
        }

        //we decide to not choose the element
        dfs(nums, target, i+1);

    }
};
