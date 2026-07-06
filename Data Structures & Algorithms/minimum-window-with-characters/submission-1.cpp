class Solution {
   public:
    string minWindow(string s, string t) {
        map<char, int> req, have;
        int reqCount = 0, haveCount = 0;

        for (auto itr : t) {
            if (req.find(itr) != req.end()) {
                req[itr]++;
            } else {
                req[itr] = 1;
            }
        }
        reqCount = req.size();

        int l = 0, r = 0;
        int start = -1, length = INT_MAX;

        for (r = 0; r < s.length(); r++) {
            if (req.find(s[r]) != req.end()) {
                if (have.find(s[r]) != have.end()) {
                    have[s[r]]++;
                } else {
                    have[s[r]] = 1;
                }
                if (req[s[r]] == have[s[r]]) {
                    haveCount++;
                }

                while (haveCount == reqCount) {
                    if (r - l + 1 < length) {
                        start = l;
                        length = min(length, r - l + 1);
                    }
                    if (have.find(s[l]) != have.end()) {
                        have[s[l]]--;
                        if (have[s[l]] < req[s[l]]) {
                            haveCount--;
                        }
                    }
                    l++;
                }
            }
        }
        if (length == INT_MAX) {
            return "";
        }
        return s.substr(start, length);
    }
};
