class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[s.length()] = true;

        for (int i = s.length() - 1; i >= 0; i--) {
            for (string itr : wordDict) {
                if (i + itr.length() <= s.length()) {
                    if (s.substr(i, itr.length()) == itr) {
                        dp[i] = dp[i + itr.length()];
                    }
                    if(dp[i] == true)
                    {
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
