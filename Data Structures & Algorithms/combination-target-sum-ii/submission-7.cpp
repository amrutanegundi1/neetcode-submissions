class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int i)
    {
        if(target == 0)
        {
            res.push_back(curr);
            return;
        }
        if(i >= candidates.size() || target < 0)
        {
            return;
        }
        curr.push_back(candidates[i]);
        dfs(candidates, target - candidates[i], i+1);
        curr.pop_back();
        while(i+1 < candidates.size())
        {
            if(candidates[i] == candidates[i+1])
            {
                i = i+1;
            }
            else
            {
                break;
            }
        }
        dfs(candidates, target, i+1);
    }
};
