class Solution {
public:
    unordered_set<int> col, pdiag, ndiag;
    int res = 0;
    int totalNQueens(int n) {
        dfs(0,n);
        return res;
    }
    void dfs(int r, int n)
    {
        if(r == n)
        {
            res++;
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(col.find(i) == col.end() && pdiag.find(r+i) == pdiag.end() && ndiag.find(r-i) == ndiag.end())
            {
                col.insert(i);
                pdiag.insert(r+i);
                ndiag.insert(r-i);
                dfs(r+1,n);
                col.erase(i);
                pdiag.erase(r+i);
                ndiag.erase(r-i);
            }
        }
    }
};