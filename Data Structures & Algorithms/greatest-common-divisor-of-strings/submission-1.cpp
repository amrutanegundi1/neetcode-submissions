class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int l1 = str1.length(), l2 = str2.length();
        for(int i = min(str1.length(), str2.length()); i > 0; i--)
        {
            string can = str1.substr(0, i);
            if(l1 % i != 0 || l2 % i != 0)
            {
                continue;
            }
            int cnt = l1 / i;
            string res = "";
            while(cnt > 0)
            {
                res += can;
                cnt--;
            }
            if(res != str1)
            {
                continue;
            }
            cnt = l2 / i;
            res = "";
            while(cnt > 0)
            {
                res += can;
                cnt--;
            }
            if(res != str2)
            {
                continue;
            }
            return can;
        }
        return "";
    }
};