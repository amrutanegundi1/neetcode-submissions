class Solution {
   public:
    vector<string> part;
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) {
        vector<vector<bool>> table(s.length(), vector<bool>(s.length(), false));

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j <= s.length() - 1; j++) {
                if (s[i] == s[j] && (((j - i + 1) < 3) || table[i + 1][j - 1])) {
                    table[i][j] = true;
                }
            }
        }
        dfs(s, 0, table);
        return res;
    }

    void dfs(string s, int i, vector<vector<bool>> tbl) {
        if (i >= s.length()) {
            res.push_back(part);
        }
        for (int j = i; j < s.length(); j++) {
            if (tbl[i][j]) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, tbl);
                part.pop_back();
            }
        }
    }
};
