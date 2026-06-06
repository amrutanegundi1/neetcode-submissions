class KthLargest {
    private:
    int k;
    priority_queue<int, vector<int>, greater<int>> que;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto itr : nums)
        {
            que.push(itr);
        }
        while(que.size() > k)
        {
            que.pop();
        }
    }
    
    int add(int val) {
        que.push(val);
        if(que.size() > k)
        {
            que.pop();
        }
        return que.top();
    }
};
