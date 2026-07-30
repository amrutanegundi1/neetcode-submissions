class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        vector<int> res;
        for(int i = 0; i< s.length();i++)
        {
            mp[s[i]] = i;
        }
        int currIndex = 0, prev = 0;
        for(int i = 0; i < s.length(); i++)
        {
            currIndex = max(currIndex, mp[s[i]]);
            if(i == currIndex)
            {
                res.push_back(i+1 - prev);
                prev = i+1;

            }
        }
        return res;
    }
};
