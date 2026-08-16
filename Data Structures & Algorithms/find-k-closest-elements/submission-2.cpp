class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        unordered_map<int, int> mp;
        for (auto itr : arr) {
            mp[itr]++;
        }
        vector<int> res;
        int digit = x, l = 0, r = 0;
        while (k > 0) {
            while (mp.find(digit - l) != mp.end() && k > 0) {
                res.push_back(digit - l);
                mp[digit - l]--;
                if (mp[digit - l] == 0) {
                    mp.erase(digit - l);
                }
                k--;
            }
            while (mp.find(digit + r) != mp.end() && k > 0) {
                res.push_back(digit + r);
                mp[digit + r]--;
                if (mp[digit + r] == 0) {
                    mp.erase(digit + r);
                }
                k--;
            }
            l++;
            r++;

        }
        sort(res.begin(), res.end());
        return res;
    }
};