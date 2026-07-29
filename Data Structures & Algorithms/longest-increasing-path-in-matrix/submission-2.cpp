class Solution {
   public:
    vector<vector<int>> dp;
    int longest = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                dp.resize(matrix.size(), vector<int>(matrix[0].size(), INT_MIN));
                longest = max(longest, dfs(matrix, i, j, INT_MIN));
            }
        }
        return longest;
    }

    int dfs(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prev >= matrix[i][j]) {
            return 0;
        }
        if (dp[i][j] != INT_MIN) {
            return dp[i][j];
        }

        dp[i][j] =
            1 + max(max(dfs(matrix, i, j + 1, matrix[i][j]), dfs(matrix, i, j - 1, matrix[i][j])),
                    max(dfs(matrix, i + 1, j, matrix[i][j]), dfs(matrix, i - 1, j, matrix[i][j])));
        
        return dp[i][j];
    }
};
