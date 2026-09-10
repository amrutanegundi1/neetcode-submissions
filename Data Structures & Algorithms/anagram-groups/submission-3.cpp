class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto itr : strs)
        {
            string val = itr;
            sort(itr.begin(), itr.end());
            mp[itr].push_back(val);
        }
        vector<vector<string>> res;
        for(auto itr : mp)
        {
            res.push_back(itr.second);
        }
        return res;
    }
};
