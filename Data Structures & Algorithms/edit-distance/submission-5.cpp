class Solution {
   public:
    map<pair<int, int>, int> mp;
    int minDistance(string word1, string word2) {
        // // return dfs(word1, word2, 0, 0);
        // vector<int> dp(word2.size() + 1);

        // // for (int i = 0; i <= word1.size(); i++) {
        // //     dp[i][0] = i;
        // // }
        // for (int i = 0; i <= word2.size(); i++) {
        //     dp[i] = i;
        // }

        // for (int i = 1; i <= word1.size(); i++) {
        //     vector<int> temp(word2.size() + 1);
        //     temp[0] = i;
        //     for (int j = 1; j <= word2.size(); j++) {
        //         if(word1[i-1] == word2[j-1])
        //         {
        //             temp[j] = dp[j-1];
        //         }
        //         else
        //         {
        //             temp[j] = 1 + min(temp[j-1], min(dp[j], dp[j-1]));
        //         }
        //     }
        //     dp = temp;
        // }
        // // for (int i = 0; i <= word1.size(); i++) {
        // //     for (int j = 0; j <= word2.size(); j++) {
        // //         cout<<dp[i][j]<<" ";
        // //     }
        // //     cout<<endl;
        // // }
        // return dp[word2.size()];
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,0));

        for(int i = 0; i <= word1.length(); i++)
        {
            for(int j = 0; j <= word2.length(); j++)
            {
                if(i == 0)
                {
                    dp[i][j] = j;
                }
                else if(j == 0)
                {
                    dp[i][j] = i;
                }
                else
                {
                    if(word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    }
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }

    int dfs(string word1, string word2, int i1, int j1) {
        pair<int, int> pr = pair<int, int>(i1, j1);
        if (mp.find(pr) != mp.end()) {
            return mp[pr];
        }
        if (i1 == word1.length() && j1 == word2.length()) {
            return 0;
        }
        if (i1 == word1.length() && j1 != word2.length()) {
            return word2.length() - j1;
        }
        if (j1 == word2.length() && i1 != word1.length()) {
            return word1.length() - i1;
        }
        if (word1[i1] == word2[j1]) {
            return dfs(word1, word2, i1 + 1, j1 + 1);
        } else {
            mp[pr] = min(/* insert*/ dfs(word1, word2, i1, j1 + 1),
                         min(/*delete*/ dfs(word1, word2, i1 + 1, j1),
                             dfs(word1, word2, i1 + 1, j1 + 1))) +
                     1;
            return mp[pr];
        }
    }
};
