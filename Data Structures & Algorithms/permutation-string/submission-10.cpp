class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> src, dst;
        for (auto itr : s1) {
            if (src.find(itr) == src.end()) {
                src[itr] = 1;
            } else {
                src[itr]++;
            }
        }

        int window = s1.length();
        // initialize first interval
        if (s2.length() >= s1.length()) {
            for (int i = 0; i < s1.length(); i++) {
                if (dst.find(s2[i]) == dst.end()) {
                    dst[s2[i]] = 1;
                } else {
                    dst[s2[i]]++;
                }
            }
            if(src == dst)
                return true;

            for (int i = 1; i <= s2.length() - window; i++) {
                dst[s2[i - 1]]--;
                if(dst[s2[i - 1]] == 0)
                {
                    dst.erase(s2[i - 1]);
                }
                if(dst.find(s2[i + window - 1]) != dst.end())
                    dst[s2[i + window - 1]]++;
                else
                    dst[s2[i + window - 1]] = 1;
                if(src == dst)
                    return true;
            }
        }
        return false;
    }
    bool isMatch(unordered_map<char, int> src, unordered_map<char, int> dst) {
        int count = 0;
        for (char ind = 'a'; ind <= 'z'; ind++) {
            if (src[ind] == dst[ind]) {
                count++;
            }
        }
        return count == 26;
    }

    int getMatch(unordered_map<char, int> src, unordered_map<char, int> dst) {
        int count = 0;
        for (char ind = 'a'; ind <= 'z'; ind++) {
            if (src[ind] == dst[ind]) {
                count++;
            }
        }
        return count;
    }
    bool permute(string s1, string s2, int l, int r) {
        if (l == r) {
            if (s2.contains(s1)) {
                return true;
            }
        }
        for (int i = l; i <= r; i++) {
            swap(s1[i], s1[l]);
            if (permute(s1, s2, l + 1, r)) return true;
            swap(s1[i], s1[l]);
        }
        return false;
    }
};
