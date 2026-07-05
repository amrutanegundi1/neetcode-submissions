class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        map<int,int> mp;

        for(int i = 0; i < intervals.size(); i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int interval = end - start + 1;
            for(int j = start; j <= end; j++)
            {
                if(mp.find(j) != mp.end())
                {
                    mp[j] = min(mp[j], interval);
                }
                else
                {
                    mp[j] = interval;
                }
            }
        }
        vector<int> res;
        for(int i = 0; i < queries.size(); i++)
        {
            if(mp.find(queries[i]) != mp.end())
            {
                res.push_back(mp[queries[i]]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
        
    }
};
