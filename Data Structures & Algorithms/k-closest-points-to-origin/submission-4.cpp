class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<>> que;
        for(int i = 0; i < points.size(); i++)
        {
            double temp = points[i][0]*points[i][0] + points[i][1]* points[i][1];
            double dist = sqrt(temp);
            que.push({dist, i});
            // cout<<dist<<" "<<i<<endl;
        }
        for(int i = 0; i < k; i++)
        {
            auto tp = que.top();

            // cout<<tp.first<<" "<<tp.second<<endl;
            res.push_back(points[tp.second]);
            que.pop();
        }
        return res;
    }
};
