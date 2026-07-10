class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;
    unordered_set<int> col, pdiag, ndiag;
    vector<vector<string>> solveNQueens(int n) {
        
        string s = "";
        for(int i = 0; i < n; i++)
            s += ".";
        curr.resize(n, s);
        backtrack(0, n);
        return res;    
    }
    void backtrack(int r, int n)
    {
        if(r == n)
        {
            res.push_back(curr);
            return;
        }

        for(int c = 0; c < n; c++)
        {
            if(col.find(c) != col.end() || pdiag.find(r + c) != pdiag.end() || ndiag.find(r-c) != ndiag.end())
                continue;
            col.insert(c);
            pdiag.insert(r+c);
            ndiag.insert(r-c);
            curr[r][c] = 'Q';

            backtrack(r + 1, n);

            col.erase(c);
            pdiag.erase(r+c);
            ndiag.erase(r-c);
            curr[r][c] = '.';
        }

    }
};
