class Solution {
public:
    string longestPalindrome(string s) {
        
        int indexLeft, indexRight, maxLen = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            //odd length
            int left = i, right = i;
            while(left >= 0 && right < s.length())
            {
                if(s[left] == s[right])
                {
                    if((right - left + 1) > maxLen)
                    {
                        
                        maxLen = right - left + 1;
                        indexLeft = left;
                        indexRight = right;
                    }
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }

            //even length
            left = i, right = i+1;
            while(left >= 0 && right < s.length())
            {
                if(s[left] == s[right])
                {
                    if((right - left + 1) > maxLen)
                    {
                        maxLen = right - left + 1;
                        indexLeft = left;
                        indexRight = right;
                    }
                    left--;
                    right++;
                }
                else
                {
                    break;
                }
            }
        }
        string result = "";
        if(maxLen > 0)
        {
            for(int i = indexLeft; i <= indexRight; i++)
            {
                result += s[i];
            }
        }
        return result;
    }
};
