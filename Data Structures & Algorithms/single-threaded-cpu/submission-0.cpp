class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>> que;
        int start = 0;
        vector<int> result;

        int i = 0;
        while (i < tasks.size() || !que.empty()) {
            if (i < tasks.size() && tasks[i][0] <= start) {
                que.push({tasks[i][1], tasks[i][2]});
                i++;
                continue;
            }
            
            if (que.empty()) {
                start = tasks[i][0];
                continue;
            }
            //cout << i << " " << start << " " << que.size() << endl;
            vector<int> temp = que.top();
            que.pop();
            result.push_back(temp[1]);
            start += temp[0];
        }
        return result;
    }
};