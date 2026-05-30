class Solution {
public:
    string longestPalindrome(string s) {
        
        int ind = 0, maxLen = 0;
        vector<vector<bool>> mat(s.length(), vector<bool>(s.length(), false));
        int n = s.length();
        for(int i = s.length()-1; i>=0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j] && (j-i+1 <= 2 || mat[i+1][j-1] == true))
                {
                    mat[i][j] = true;
                    if(j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        ind = i;
                    }
                }
            }
        }
        return s.substr(ind, maxLen);
    }
};
