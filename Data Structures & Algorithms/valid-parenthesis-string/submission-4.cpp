class Solution {
   public:
    map<pair<int, int>, bool> mp;
    bool checkValidString(string s) {
        if (dfs(s, 0, 0)) return true;
        return false;
    }
    bool dfs(string s, int i, int curr) {
        pair<int, int> pr = pair<int, int>(i, curr);
        if (mp.find(pr) != mp.end()) {
            return mp[pr];
        }
        if (i >= s.length()) {
            if (curr == 0) {
                return true;
            }
            return false;
        }
        if (s[i] == '(') {
            curr++;
            return dfs(s, i + 1, curr);
        }
        if (s[i] == ')') {
            curr--;
            if (curr < 0) {
                mp[pr] = false;
                return false;
            }
            return dfs(s, i + 1, curr);
        }
        if (s[i] == '*') {
            bool s1 = dfs(s, i + 1, curr);
            if (s1) {
                mp[pr] = true;

                return true;
            }
            curr += 1;
            s1 = dfs(s, i + 1, curr);
            if (s1) {
                mp[pr] = true;
                return true;
            }
            curr -= 2;
            s1 = dfs(s, i + 1, curr);
            if (s1) {
                mp[pr] = true;
                return true;
            }

            mp[pr] = false;
            return false;
        }
        mp[pr] = false;

        return false;
    }
};
