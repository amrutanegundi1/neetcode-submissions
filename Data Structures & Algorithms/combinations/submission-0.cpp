class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
    void dfs(int i, int n, int k)
    {
        if(k == 0)
        {
            res.push_back(curr);
            return;
        }
        if(i == n + 1)
            return;
        curr.push_back(i);
        dfs(i + 1, n, k-1);
        curr.pop_back();
        dfs(i+1,n,k);
    }

};