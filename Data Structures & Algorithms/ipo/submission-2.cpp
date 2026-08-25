class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int res = w;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> que;
        for(int i = 0; i < capital.size(); i++)
        {
            que.push({capital[i], profits[i]});
        }
        priority_queue<pair<int, int>> cap;
        while(k > 0)
        {
            vector<pair<int,int>> ls;
            while(!que.empty() && que.top().first <= w)
            {
                cap.push({que.top().second, que.top().first});
                que.pop();
            }
            if(cap.empty())
            {
                break;
            }
            res += cap.top().first;
            w += cap.top().first;
            cap.pop();
            k--;
        }
        return res;
    }
};