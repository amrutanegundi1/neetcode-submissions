class Solution {
   public:
    map<pair<int, int>, bool> mp;
    bool checkValidString(string s) {
        // int leftmin = 0, leftmax = 0;
        // for(auto itr : s)
        // {
        //     if(itr == '(')
        //     {
        //         leftmin++;
        //         leftmax++;
        //     }
        //     else if(itr == ')')
        //     {
        //         leftmin--;
        //         leftmax--;
        //     }
        //     else
        //     {
        //         leftmin--;
        //         cout<<leftmin<<endl;
        //         leftmax++;
        //     }
        //     leftmin = max(0, leftmin);
        //     if(leftmax < 0)
        //     {
        //         return false;
        //     }
        // }
        // return leftmin == 0;
        if (dfs(s, 0, 0)) return true;
        return false;
    }
    bool dfs(string s, int i, int curr) {
        pair<int, int> pr = pair<int, int>(i, curr);
        if (mp.find(pr) != mp.end()) {
            return mp[pr];
        }
        if(curr < 0)
        return false;
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
