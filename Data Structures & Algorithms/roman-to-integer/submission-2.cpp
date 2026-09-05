class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        for(int i = 0; i < s.length(); i++)
        {
            if(i + 1 < s.length())
            {
                int temp = res;
                if(s[i] == 'I')
                {
                    if(s[i+1] == 'V')
                        res += 4;
                    if(s[i+1] == 'X')
                        res += 9;
                }
                else if(s[i] == 'X')
                {
                    if(s[i+1] == 'L')
                        res += 40;
                    if(s[i+1] == 'C')
                        res += 90;
                }
                else if(s[i] == 'C')
                {
                    if(s[i+1] == 'D')
                        res += 400;
                    if(s[i+1] == 'M')
                        res += 900;
                }
                if(temp != res)
                {
                    i = i + 1;
                    continue;
                }
                res += romanToVal(s[i]);
            }
            else
            {
                res += romanToVal(s[i]);
            }
        }
        return res;
    }
    int romanToVal(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
        return 0;
    }
};