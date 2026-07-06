class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     map<char, int> charsSeen;
    //     int maxLength = 0;
    //     int l = 0;
    //     for(int r = 0; r < s.size(); r++)
    //     {
    //         if(charsSeen.find(s[r]) != charsSeen.end() && l <= charsSeen[s[r]])
    //         {
    //             l = charsSeen[s[r]] +1;
    //         }
    //         charsSeen[s[r]] = r;
    //         maxLength = max(maxLength, r-l +1);
    //     }
    //     return maxLength;
    // }

    int lengthOfLongestSubstring(string s) {
        set<char> charsSeen;
        int maxLength = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++)
        {
            while(charsSeen.find(s[r]) != charsSeen.end())
            {
                charsSeen.erase(s[l]);
                l++;
            }
            charsSeen.insert(s[r]);
            maxLength = max(maxLength, r-l +1);
        }
        return maxLength;
    }
};
