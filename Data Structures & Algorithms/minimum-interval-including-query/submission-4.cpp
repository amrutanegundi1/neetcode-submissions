class Solution {
   public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // map<int,int> mp;

        // for(int i = 0; i < intervals.size(); i++)
        // {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     int interval = end - start + 1;
        //     for(int j = start; j <= end; j++)
        //     {
        //         if(mp.find(j) != mp.end())
        //         {
        //             mp[j] = min(mp[j], interval);
        //         }
        //         else
        //         {
        //             mp[j] = interval;
        //         }
        //     }
        // }
        // vector<int> res;
        // for(int i = 0; i < queries.size(); i++)
        // {
        //     if(mp.find(queries[i]) != mp.end())
        //     {
        //         res.push_back(mp[queries[i]]);
        //     }
        //     else
        //     {
        //         res.push_back(-1);
        //     }
        // }
        // return res;
        vector<int> sorted = queries;
        sort(sorted.begin(), sorted.end());
        sort(intervals.begin(), intervals.end());
        map<int, int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int j = 0;
        for (int i = 0; i < sorted.size(); i++) {
            while (j < intervals.size() && intervals[j][0] <= sorted[i]) {
                que.push(pair<int, int>(intervals[j][1] - intervals[j][0] + 1, intervals[j][1]));
                j++;
            }
            if (que.size() > 0) {
                pair<int, int> pr = que.top();
                while (pr.second < sorted[i]) {
                    que.pop();
                    if(que.size() == 0)
                    {
                        break;
                    }
                    pr = que.top();
                }
                if(que.size())
                {
                    res[sorted[i]] = pr.first;
                }
                else
                {
                    res[sorted[i]] = -1;
                }
            }
            else
            {
                res[sorted[i]] = -1;
            }
        }
        vector<int> result;
        for(auto itr : queries)
        {
            result.push_back(res[itr]);
        }
        return result;
    }
};
