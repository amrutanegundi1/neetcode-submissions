class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;

        while (b >= t && r >= l) {
            // fetch the top row
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
            }

            // fetch the right column
            for (int i = t + 1; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if (t != b && l != r) {
                // fetch the bottom row
                for (int i = r - 1; i >= l; i--) {
                    res.push_back(matrix[b][i]);
                }

                // fetch the left column
                for (int i = b - 1; i >= t + 1; i--) {
                    res.push_back(matrix[i][l]);
                }
            }
            l++;
            r--;
            b--;
            t++;
        }
        return res;
    }
};
