class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.length(); i++)
        {
            mp[s[i]] = i;
        }
        

        vector<int> res;
        int size = 0, start = 0, end = 0;
        for(int i = 0; i < s.length(); i++)
        {
            size++;
            end = max(end, mp[s[i]]);
            if(i == end)
            {
                res.push_back(size);
                size = 0;
            }

        }
        return res;
    }
};
