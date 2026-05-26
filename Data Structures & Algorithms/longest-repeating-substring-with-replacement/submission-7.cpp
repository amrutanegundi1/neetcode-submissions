class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int max_count = 0;
        int l = 0;
        array<int, 26> counter = {0};

        for(int r =0; r < s.length();r++)
        {
            counter[s[r] - 'A']++;
            if(r - l +1 - maxFreq(counter) <= k)
            {
                max_count = max(max_count, r - l +1);
                continue;
            }
            else
            {
                counter[s[l] - 'A']--;
                l++;
            }
        }
        return max_count;
    }

    int maxFreq(array<int, 26> counter)
    {
        int maxCount = 0;
        for( int i =0; i< 26; i++)
        {
            maxCount = max(maxCount, counter[i]);
        }
        return maxCount;
    }
};
