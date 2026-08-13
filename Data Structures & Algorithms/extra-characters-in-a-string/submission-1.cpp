class Solution {
public:
    vector<int> dp;
    int minExtraChar(string s, vector<string>& dictionary) {
        dp.resize(s.length(), -1);
        return dfs(s, dictionary, 0);
        
    }

    int dfs(string s, vector<string>& words, int i)
    {
        if(i >= s.length())
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }

        int res = 1 + dfs(s, words, i+1);

        for(int j = i; j < s.length(); j++)
        {
            if(isStringPresent(s.substr(i, j-i+1), words))
            {
                res = min(res, dfs(s, words, j+1));
            }
        }
        dp[i] = res;
        return res;
    }

    bool isStringPresent(string s, vector<string>& words)
    {
        for(auto itr : words)
        {
            if(itr == s)
            {
                return true;
            }
        }
        return false;
    }
};