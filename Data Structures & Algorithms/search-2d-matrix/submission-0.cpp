class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, row = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] == target || matrix[mid][matrix[0].size() - 1] == target) {
                return true;
            }
            if (matrix[mid][0] < target && matrix[mid][matrix[0].size() - 1] > target) {
                row = mid;
                break;
            } else if (target < matrix[mid][0]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (row != -1) {
            l = 0;
            r = matrix[0].size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                }
                if (matrix[row][mid] < target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
