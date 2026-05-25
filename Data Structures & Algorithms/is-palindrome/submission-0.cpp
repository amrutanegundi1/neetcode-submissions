class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> pal;
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                pal.push_back('a' + (s[i] - 'A'));
            } else if( s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' )
            {
                pal.push_back(s[i]);
            }
        }
        vector<char> reverse = pal;
        std::reverse(reverse.begin(), reverse.end());

        return pal == reverse;
    }
};
