class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> src, dst;
        for (auto itr : s1) {
            if (src.find(itr) == src.end()) {
                src[itr] = 1;
            } else {
                src[itr]++;
            }
        }

        int match = 0, window = s1.length();
        // initialize first interval
        if (s2.length() >= s1.length()) {
            for (int i = 0; i < s1.length(); i++) {
                if (dst.find(s2[i]) == dst.end()) {
                    dst[s2[i]] = 1;
                } else {
                    dst[s2[i]]++;
                }
            }
            for (char ind = 'a'; ind <= 'z'; ind++) {
                if (dst.find(ind) == dst.end()) {
                    dst[ind] = 0;
                }
                if (src.find(ind) == src.end()) {
                    src[ind] = 0;
                }
            }

            if (isMatch(src, dst)) {
                return true;
            }

            for (int i = 1; i <= s2.length() - window; i++) {
                dst[s2[i - 1]]--;
                dst[s2[i + window - 1]]++;
                if (isMatch(src, dst)) {
                    return true;
                }
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
