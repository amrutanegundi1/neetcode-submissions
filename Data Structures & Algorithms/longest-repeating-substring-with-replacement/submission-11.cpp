class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> ar = {0};
        int l = 0, r =0;
        int res = 0;
        while(r < s.length())
        {
            ar[s[r] - 'A']++;

            if((r - l + 1) - maxFreq(ar) <= k)
            {
                res = max(res, r-l +1);
            }
            else
            {
                ar[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return res;
        
    }
    int maxFreq(array<int,26> arr)
    {
        int res = 0;

        for(int i = 0; i< 26; i++)
        {
            res = max(res, arr[i]);
        }
        return res;
    }
};
