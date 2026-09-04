class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int l = 0, r = 0;

        while(r < s.length() - 1)
        {
            bool extended = false;
            for(int i = l + minJump; i <= min(l + maxJump, int(s.length()-1)); i++)
            {
                if(s[i] == '0')
                {
                    extended = true;
                    r = max(r, i);
                }
            }
            if(!extended)
            {
                return false;
            }
            if(r == s.length()-1)
            {
                return true;
            }
            if(extended)
            {
                l = l + minJump;
                while(l < min(l + maxJump, int(s.length()-1)) && s[l] == '1')
                    l++;
            }
        }
        return true;
        
    }
};