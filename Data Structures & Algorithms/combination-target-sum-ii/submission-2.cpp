class Solution {
public:
    set<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target,0);
        return vector<vector<int>>(res.begin(), res.end());
        
    }

    void dfs(vector<int>& cd, int tgt, int i)
    {
        if(0 == tgt)
        {
            res.insert(curr);

            return;
        }
        if(i >= cd.size() || tgt < 0)
            return;
        curr.push_back(cd[i]);
        dfs(cd, tgt- cd[i], i+1);
        int num = curr[curr.size()-1];
        curr.pop_back();
        int ind = i + 1;
        while(ind < cd.size() && cd[ind] == num)
            ind += 1;
        dfs(cd, tgt, ind);
    }
};
