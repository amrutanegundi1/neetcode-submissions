class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            set<char> rowValidator, colValidator;
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] != '.') {
                    if (rowValidator.find(board[i][j]) != rowValidator.end()) return false;
                    rowValidator.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (colValidator.find(board[j][i]) != colValidator.end()) return false;
                    colValidator.insert(board[j][i]);
                }
            }
        }
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                set<char> valid;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int r = (k * 3) + i;
                        int c = (l * 3) + j;
                        if (board[r][c] != '.') {
                            if (valid.find(board[r][c]) != valid.end()) {
                                return false;
                            }
                            valid.insert(board[r][c]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
