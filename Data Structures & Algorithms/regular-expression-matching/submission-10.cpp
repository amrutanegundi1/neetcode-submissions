class Solution {
   public:
    map<pair<int, int>, int> mp;
    bool isMatch(string s, string p) { return dfs(s, p, 0, 0); }

    bool dfs(string s, string p, int i, int j) {
        if (i >= s.length() && j >= p.length()) {
            return true;
        }
        if (j >= p.length()) {
            return false;
        }

        if (mp.find(pair<int, int>(i, j)) != mp.end()) {
            return mp[pair<int, int>(i, j)];
        }

        bool res = false;

        if (((p[j] >= 'a' && p[j] <= 'z') || p[j] == '.') && j + 1 < p.length() &&
            p[j + 1] == '*') {
            if (i < s.length()) {
                if (s[i] == p[j] || p[j] == '.') {
                    res = dfs(s, p, i + 1, j) || dfs(s, p, i, j + 2);
                } else {
                    res = dfs(s, p, i, j + 2);
                }
            } else {
                res = dfs(s, p, i, j + 2);
            }
        } else {
            if (i < s.length()) {
                if (s[i] == p[j] || p[j] == '.') {
                    res = dfs(s, p, i + 1, j+1);
                }
            }
        }
        mp[pair<int, int>(i, j)] = res;
        return res;

    }
};
