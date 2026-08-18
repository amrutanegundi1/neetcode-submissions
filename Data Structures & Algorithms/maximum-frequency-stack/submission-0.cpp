class FreqStack {
public:
    int index = 0;
    priority_queue<vector<int>> que;
    unordered_map<int,int> freq;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        que.push({freq[val], index++, val});
    }
    
    int pop() {
        vector<int> data = que.top();
        que.pop();
        freq[data[2]]--;
        index--;
        return data[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */