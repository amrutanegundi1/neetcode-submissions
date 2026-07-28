class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.length()+1, false);
        dp[s.length()] = true;

        for(int i = s.length()-1; i >= 0; i--)
        {
            for(auto itr : wordDict)
            {
                int length = itr.length(); 
                if(i + length <= s.length() && s.substr(i, length) == itr)
                {
                    dp[i] = dp[i + length];
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
