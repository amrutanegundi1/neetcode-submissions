class Solution {
public:
    int countSubstrings(string s) {

        vector<vector<bool>> mp(s.length(), vector<bool>(s.length(), false));
        int n = s.length();
        int count = 0;

        for(int i = n -1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j] && ((j- i + 1 <= 3) || mp[i+1][j-1] == true))
                {
                    mp[i][j] = true;
                    count++;
                }
            }
        }
        return count;       
    }
};
