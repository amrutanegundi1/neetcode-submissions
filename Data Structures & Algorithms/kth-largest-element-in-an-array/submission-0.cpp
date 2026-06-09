class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for(auto itr : nums)
        {
            que.push(itr);
        }
        while(que.size() > k)
        {
            que.pop();
        }
        return que.top();
    }
};
