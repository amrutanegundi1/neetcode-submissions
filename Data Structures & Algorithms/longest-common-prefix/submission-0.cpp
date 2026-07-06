class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for(int i = 0; i < strs[0].length(); i++)
        {
            bool prefix = true;
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j].length() >= i+1)
                {
                    if(strs[j][i] != strs[0][i])
                    {
                        prefix = false;
                        break;
                    }
                }
                else
                {
                    prefix = false;
                    break;
                }
            }
            if(prefix)
            {
                res += strs[0][i];
            }
            else
            {
                break;
            }

        }
        return res;
        
    }
};