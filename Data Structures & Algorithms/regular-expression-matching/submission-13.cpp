class Solution {
   public:
   vector<vector<int>> dp;
    bool isMatch(string s, string p) { 
        dp.resize(s.length()+1, vector<int>(p.length()+1,-1));
        return dfs(s, p, 0, 0); 
        }

    bool dfs(string s, string p, int i, int j) {
        if (j == p.length() && i != s.length()) {
            return false;
        }
        if (j == p.length() && i == s.length()) {
            return true;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (j + 1 < p.length() && p[j + 1] == '*') {
            if (i < s.length()) {
                if (p[j] == '.' || s[i] == p[j]) {
                    dp[i][j] = dfs(s, p, i + 1, j) || dfs(s, p, i, j + 2);
                    return dp[i][j];
                } else {
                    dp[i][j] = dfs(s, p, i, j + 2);
                    return dp[i][j];
                }
            }
            else
            {
                dp[i][j] = dfs(s, p, i, j + 2);
                return dp[i][j];
            }
        } else {
            if (i < s.length()) {
                if (p[j] == '.' || s[i] == p[j]) {
                    dp[i][j] = dfs(s, p, i + 1, j + 1);
                    return dp[i][j];
                }
            }
        }
        return false;
    }
};
