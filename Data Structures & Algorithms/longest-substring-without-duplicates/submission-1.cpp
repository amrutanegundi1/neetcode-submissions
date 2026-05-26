class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)
            return 0;
        int maxLen = 1;
        for(int i=0; i < s.length()-1; i++)
        {
            int j = i+1;
            set<char> charsSeen;
            charsSeen.insert(s[i]);
            for(j = i+1; j < s.length(); j++)
            {
                if(charsSeen.find(s[j]) == charsSeen.end())
                {
                    charsSeen.insert(s[j]);
                }
                else
                {
                    break;
                }
            }
            maxLen = max(maxLen, j-i);
        }
        return maxLen;
    }
};
