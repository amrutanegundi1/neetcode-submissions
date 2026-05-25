class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> result;
        vector<vector<string>> ret;
        for(int i = 0; i < strs.size(); i++)
        {
            string src = strs[i];
            sort(src.begin(),src.end());
            if(result.find(src) != result.end())
            {
                result[src].push_back(i);
            }
            else
            {
                vector<int> indexList;
                indexList.push_back(i);
                result.insert(pair<string,vector<int>>(src, indexList));
            }
        }
        for(auto itr : result)
        {
            vector<string> resultSet;
            for(auto ind : itr.second)
            {
                resultSet.push_back(strs[ind]);
            }
            ret.push_back(resultSet);
        }
        return ret;
        
    }
};
