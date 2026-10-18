class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
        {
            return false;
        }
        array<char, 26> m1({0}), m2({0});
        for (auto itr : s1) {
            m1[itr - 'a']++;
        }
        for (int i = 0; i < s1.length(); i++) {
            m2[s2[i] - 'a']++;
        }
        if (m1 == m2) {
            return true;
        }
        int l = 1, r = s1.length() - 1;
        while (l <= (s2.length() - s1.length())) {
            m2[s2[l - 1] - 'a']--;
            r++;
            m2[s2[r] - 'a']++;
            if (m1 == m2) {
                return true;
            }
            l++;
        }
        return false;
    }
};
