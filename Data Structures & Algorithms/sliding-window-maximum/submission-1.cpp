class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        priority_queue<pair<int,int>> que;
        for(int i = 0; i < k; i++)
        {
            que.push(pair<int,int>(nums[i], i));
        }
        res.push_back(que.top().first);
        for(int i = k; i < nums.size(); i++)
        {
            que.push(pair<int,int>(nums[i], i));
            pair<int,int> pr = que.top();
            while(pr.second <= i - k)
            {
                que.pop();
                pr = que.top();
            }
            res.push_back(pr.first);
        }
        return res;
    }
};
