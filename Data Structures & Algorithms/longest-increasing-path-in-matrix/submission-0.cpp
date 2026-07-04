class Solution {
   public:
    int rows = 0, cols = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxVal = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                maxVal = max(maxVal, dfs(i, j, -1, matrix, dp));
            }
        }
        return maxVal;
    }

    int dfs(int r, int c, int prevVal, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || matrix[r][c] <= prevVal) {
            return 0;
        }
        if (dp[r][c] > 0) {
            return dp[r][c];
        }

        int res = 1 + max(dfs(r + 1, c, matrix[r][c], matrix, dp),
                          max(dfs(r - 1, c, matrix[r][c], matrix, dp),
                              max(dfs(r, c + 1, matrix[r][c], matrix, dp),
                                  dfs(r, c - 1, matrix[r][c], matrix, dp))));
        dp[r][c] = res;
        return res;
    }
};
