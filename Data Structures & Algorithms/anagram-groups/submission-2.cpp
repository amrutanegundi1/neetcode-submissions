class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> result;
        vector<vector<string>> ret;
        for(int i = 0; i < strs.size(); i++)
        {
            string src = strs[i];
            sort(src.begin(),src.end());
            result[src].push_back(strs[i]);
        }
        for(auto itr : result)
        {
            ret.push_back(itr.second);
        }
        return ret;
        
    }
};
