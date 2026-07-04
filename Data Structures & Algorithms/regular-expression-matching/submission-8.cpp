class Solution {
   public:
    map<pair<int, int>, bool> dp;
    bool isMatch(string s, string p) { return parser(s, p, 0, 0); }

    bool parser(string s, string p, int i, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }
        if (j >= p.length()) {
            return false;
        }
        pair<int, int> pr = pair<int, int>(i, j);
        if (dp.find(pr) != dp.end()) {
            return dp[pr];
        }
        bool res = false;

        if ((p[j] >= 'a' && p[j] <= 'z' || p[j] == '.') && j < p.length() - 1 && p[j + 1] == '*') {
            if (i < s.length()) {
                if (p[j] == s[i] || p[j] == '.') {
                    res = parser(s, p, i + 1, j) || parser(s, p, i + 1, j + 2) ||
                          parser(s, p, i, j + 2);
                } else {
                    res = parser(s, p, i, j + 2);
                }
            } else {
                res = parser(s, p, i, j + 2);
            }
        } else if (i < s.length()) {
            if (p[j] == '.') {
                res = parser(s, p, i + 1, j + 1);
            } else if (s[i] == p[j]) {
                res = parser(s, p, i + 1, j + 1);
            }
        }
        dp[pr] = res;
        return res;
    }
};
