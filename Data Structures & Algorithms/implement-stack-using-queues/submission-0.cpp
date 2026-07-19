class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        vector<int> temp;
        while(!q.empty())
        {
            temp.push_back(q.front());
            q.pop();
        }
        for(int i = 0; i < temp.size()-1;i++)
            q.push(temp[i]);
        return temp[temp.size()-1];
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */